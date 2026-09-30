#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cstdlib>
#include "recommendations.h"

using namespace std;


// Stores saved recommendations during current session
vector<string> savedRecommendations;


// ==================================================
// CLEAR SCREEN
// ==================================================

void clearScreen() {

    system("cls");
}


// ==================================================
// WAIT FOR USER
// ==================================================

void pressEnterToContinue() {

    cout << "\nPress Enter to return to main menu...";

    cin.ignore(
        numeric_limits<streamsize>::max(),
        '\n'
    );

    cin.get();
}


// ==================================================
// SHARED INPUT VALIDATION
// ==================================================

int getValidChoice(
    const char* prompt,
    int minimum,
    int maximum
) {

    int choice;

    while (true) {

        cout << prompt;

        if (cin >> choice) {

            if (choice >= minimum && choice <= maximum) {

                return choice;
            }

            cout << "Invalid choice. Please enter "
                 << minimum
                 << "-"
                 << maximum
                 << ".\n";
        }

        else {

            cout << "Invalid input. Please enter a number.\n";

            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );
        }
    }
}


// ==================================================
// MAIN PROGRAM
// ==================================================

int main() {

    int choice;

    do {

        // Clear previous screen
        clearScreen();


        // ==================================================
        // MAIN MENU
        // ==================================================

        cout << "====================================\n";
        cout << "      MUSIC RECOMMENDATION SYSTEM\n";
        cout << "====================================\n";

        cout << "\nChoose an option:\n\n";

        cout << "1. Mood Recommendation\n";
        cout << "2. Genre Recommendation\n";
        cout << "3. Activity Recommendation\n";
        cout << "4. Discovery Recommendation\n";
        cout << "5. Saved Recommendations\n";
        cout << "6. Exit\n";


        choice = getValidChoice(
            "\nEnter your choice: ",
            1,
            6
        );


        // Stores recommendation produced in current round
        string currentRecommendation = "";


        // ==================================================
        // MENU OPTIONS
        // ==================================================

        switch (choice) {


            // --------------------------------------------------
            // MOOD
            // --------------------------------------------------

            case 1: {

                clearScreen();

                moodRecommendation();

                currentRecommendation =
                    "Mood Recommendation";

                break;
            }


            // --------------------------------------------------
            // GENRE
            // --------------------------------------------------

            case 2: {

                clearScreen();

                GenreResult result =
                    genreRecommendation();


                // Only create record if recommendation exists
                if (!result.genre.empty()) {

                    currentRecommendation =
                        "Genre Recommendation"
                        "\n   Genre: " + result.genre +
                        "\n   Mix: " + result.mix +
                        "\n   Songs:";


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

                activityRecommendation();

                currentRecommendation =
                    "Activity Recommendation";

                break;
            }


            // --------------------------------------------------
            // DISCOVERY
            // --------------------------------------------------

            case 4: {

                clearScreen();

                discoveryRecommendation();

                currentRecommendation =
                    "Discovery Recommendation";

                break;
            }


            // --------------------------------------------------
            // SAVED RECOMMENDATIONS
            // --------------------------------------------------

            case 5: {

                clearScreen();

                cout << "====================================\n";
                cout << "       SAVED RECOMMENDATIONS\n";
                cout << "====================================\n";


                if (savedRecommendations.empty()) {

                    cout << "\nNo saved record found.\n";
                }

                else {

                    for (
                        size_t i = 0;
                        i < savedRecommendations.size();
                        i++
                    ) {

                        cout << "\n"
                             << i + 1
                             << ". "
                             << savedRecommendations[i]
                             << "\n";
                    }
                }


                cout << "\n====================================\n";

                pressEnterToContinue();

                break;
            }


            // --------------------------------------------------
            // EXIT
            // --------------------------------------------------

            case 6: {

                clearScreen();

                cout << "====================================\n";
                cout << "      MUSIC RECOMMENDATION SYSTEM\n";
                cout << "====================================\n";

                cout << "\nThank you for using the "
                     << "Music Recommendation System!\n";

                cout << "\n====================================\n";

                break;
            }
        }


        // ==================================================
        // SAVE RECOMMENDATION
        // ==================================================

        if (!currentRecommendation.empty()) {

            int saveChoice;


            cout << "\nSave this recommendation?\n\n";

            cout << "1. Yes\n";
            cout << "0. No\n";


            saveChoice = getValidChoice(
                "\nEnter your choice: ",
                0,
                1
            );


            if (saveChoice == 1) {

                savedRecommendations.push_back(
                    currentRecommendation
                );

                cout << "\nRecommendation saved!\n";
            }

            else {

                cout << "\nRecommendation not saved.\n";
            }


            pressEnterToContinue();
        }


        // User returned without generating a recommendation
        else if (choice >= 1 && choice <= 4) {

            cout << "\nNo recommendation record found.\n";

            pressEnterToContinue();
        }


    } while (choice != 6);


    return 0;
}