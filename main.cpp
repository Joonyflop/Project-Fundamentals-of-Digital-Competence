#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cstdlib>
#include "recommendations.h"

using namespace std;

// Stores saved recommendations during current session
// Vector allows multiple recommendation records to be stored
vector<string> savedRecommendations;


// Clears the console screen depending on the operating system
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// input from user
// Pauses the program before returning to the main menu
void pressEnterToContinue() {

    cout << "\nPress any key to return to the main menu...";

    // Removes any remaining characters from the input buffer
    cin.ignore(
        numeric_limits<streamsize>::max(),
        '\n'
    );

    // Waits for the user to press a key
    cin.get();
}

// SHARED INPUT VALIDATION
// Ensures the user enters a valid number within the allowed range
// This function is shared by different recommendation modules
int getValidChoice(
    const char* prompt,
    int minimum,
    int maximum
) {

    int choice;

    // Continue asking until valid input is entered
    while (true) {

        cout << prompt;

        // Check whether the input is a number
        if (cin >> choice) {

            // Check whether the number is within the accepted range
            if (choice >= minimum && choice <= maximum) {

                return choice;
            }

            // Display error when number is outside the valid range
            cout << "Invalid choice. Please enter "
                 << minimum
                 << "-"
                 << maximum
                 << ".\n";
        }

        else {

            // Handle non-numeric input
            cout << "Invalid input. Please enter a number.\n";

            // Reset the input stream after invalid input
            cin.clear();

            // Remove invalid characters from the input buffer
            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );
        }
    }
}


// MAIN PROGRAM
// Controls the main menu and connects all recommendation modules
int main() {

    // Stores the user's main menu selection
    int choice;

    // Keep displaying the main menu until the user chooses Exit
    do {

        // Clear previous screen
        clearScreen();

        // MAIN MENU
        // Display all available recommendation features
        cout << "+====================================+\n";
        cout << "      MUSIC RECOMMENDATION SYSTEM\n";
        cout << "+====================================+\n";

        cout << "\nChoose an option:\n\n";

        cout << "1. Mood Recommendation\n";
        cout << "2. Genre Recommendation\n";
        cout << "3. Activity Recommendation\n";
        cout << "4. Discovery Recommendation\n";
        cout << "5. Saved Recommendations\n";
        cout << "6. Exit\n";


        // Validate main menu input between 1 and 6
        choice = getValidChoice(
            "\nEnter your choice: ",
            1,
            6
        );


        // Stores recommendation produced in current round
        // Empty string means there is no recommendation to save
        string currentRecommendation = "";

        // MENU OPTIONS
        // switch statement directs the user to the selected module
        switch (choice) {


            // MOOD

            case 1: {
                clearScreen();

                // Run the Mood Recommendation module
                GenreResult result = moodRecommendation();

                // Only create a record when a recommendation is returned
                if (!result.genre.empty()) {
                    currentRecommendation =
                        "Mood Recommendation"
                        "\n   Mood/Vibe: " + result.genre +
                        "\n   Playlist: " + result.mix +
                        "\n   Suggestions:";

                    // Add every suggested song to the saved record
                    for (const string& suggestion : result.songs) {
                        currentRecommendation += "\n   - " + suggestion;
                    }
                }

                break;
            }

            // GENRE

            case 2: {

                clearScreen();

                // Run the Genre Recommendation module
                GenreResult result =
                    genreRecommendation();


                // Only create record if recommendation exists
                if (!result.genre.empty()) {

                    // Format the genre result before saving
                    currentRecommendation =
                        "Genre Recommendation"
                        "\n   Genre: " + result.genre +
                        "\n   Mix: " + result.mix +
                        "\n   Songs:";


                    // Add each recommended song to the record
                    for (const string& song : result.songs) {

                        currentRecommendation +=
                            "\n   - " + song;
                    }
                }

                break;
            }


            // --------------------------------------------------
            // ACTIVITY
            // --------------------------------------------------

            case 3: {

            clearScreen();

            // Run the Activity Recommendation module
            // The function directly returns the recommendation as a string
            currentRecommendation =
                activityRecommendation();

            break;
        }


            // --------------------------------------------------
            // DISCOVERY
            // --------------------------------------------------

            case 4: {

                // DISCOVERY

                clearScreen();

                // Run the Discovery Recommendation module
                GenreResult result = discoveryRecommendation();

                // Only create a record when a recommendation is returned
                if (!result.genre.empty()) {
                    currentRecommendation =
                        "Discovery Recommendation"
                        "\n   Genre: " + result.genre +
                        "\n   Vibe: " + result.mix +
                        "\n   Suggestions:";

                    // Add each discovery suggestion to the record
                    for (const string& suggestion : result.songs) {
                        currentRecommendation += "\n   - " + suggestion;
                    }
                }

                break;
            }
            

            // SAVED RECOMMENDATIONS
            // Displays all recommendations saved during the current session
            case 5: {

                clearScreen();

                cout << "+====================================+\n";
                cout << "|       SAVED RECOMMENDATIONS        |\n";
                cout << "+====================================+\n";


                // Check whether the saved recommendation list is empty
                if (savedRecommendations.empty()) {

                    cout << "\nNo saved record found.\n";
                }

                else {

                    // Loop through and display every saved recommendation
                    for (
                        size_t i = 0;
                        i < savedRecommendations.size();
                        i++
                    ) {

                        // Display each recommendation with its record number
                        cout << "\n"
                             << i + 1
                             << ". "
                             << savedRecommendations[i]
                             << "\n";
                    }
                }


                cout << "\n+====================================+\n";

                // Wait for user input before returning to the menu
                pressEnterToContinue();

                break;
            }


            // --------------------------------------------------
            // EXIT
            // --------------------------------------------------

            case 6: {

                clearScreen();

                // Display the exit message
                cout << "+====================================+\n";
                cout << "|      MUSIC RECOMMENDATION SYSTEM   |\n";
                cout << "+====================================+\n";

                cout << "\nThank you for using the "
                     << "Music Recommendation System!\n";

                cout << "\n+====================================+\n";

                break;
            }
        }


        // SAVE RECOMMENDATION
        // Only ask to save when a recommendation was actually generated
        if (!currentRecommendation.empty()) {

            int saveChoice;


           cout << "\nWould you like to save this recommendation? (1 = Yes, 0 = No): ";


            // Validate the save option so only 0 or 1 is accepted
            saveChoice = getValidChoice(
                "\nEnter your choice: ",
                0,
                1
            );


            // Save the current recommendation when the user chooses Yes
            if (saveChoice == 1) {

                // Add the recommendation to the vector
                savedRecommendations.push_back(
                    currentRecommendation
                );

                cout << "\nRecommendation saved!\n";
            }

            else {

                // Recommendation is not added to the saved list
                cout << "\nRecommendation not saved.\n";
            }


            // Pause before returning to the main menu
            pressEnterToContinue();
        }

    } 
    // End the main program loop when option 6 is selected
    while (choice != 6);


    // End the program successfully
    return 0;
}