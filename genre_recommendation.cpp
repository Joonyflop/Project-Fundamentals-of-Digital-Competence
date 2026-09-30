#include <iostream>
#include "recommendations.h"

using namespace std;

// Member 2 - Genre Recommendation Module
// Recommends music based on the user's genre and listening preferences
void genreRecommendation() {

    // Variables for storing user choices
    int menuChoice;
    int genreChoice;
    int soundChoice;
    int energyChoice;
    int styleChoice;

    // Display genre recommendation menu
    cout << "\n====================================\n";
    cout << "          YOUTUBE MUSIC\n";
    cout << "       GENRE RECOMMENDATION\n";
    cout << "====================================\n";

    cout << "\nWhat would you like to do?\n\n";
    cout << "1. Find My Genre\n";
    cout << "2. Browse by Genre\n";
    cout << "3. Back to Main Menu\n";

    cout << "\nEnter your choice: ";
    cin >> menuChoice;

    // Make sure the user selects a valid menu option
    while (menuChoice < 1 || menuChoice > 3) {
        cout << "Invalid choice. Please enter 1-3: ";
        cin >> menuChoice;
    }

    // ============================================
    // OPTION 1: FIND MY GENRE
    // ============================================
    if (menuChoice == 1) {

        cout << "\n------ FIND MY GENRE ------\n";
        cout << "Answer a few questions and we will find a genre for you!\n";

        // Ask about the user's preferred sound
        cout << "\n- What kind of sound do you prefer?\n";
        cout << "1. Catchy and mainstream\n";
        cout << "2. Smooth and soulful\n";
        cout << "3. Strong beats and rhythm\n";
        cout << "4. Guitar and drums\n";
        cout << "5. Electronic and synthesized\n";

        cout << "\nEnter your choice (1-5): ";
        cin >> soundChoice;

        // Validate sound preference
        while (soundChoice < 1 || soundChoice > 5) {
            cout << "Invalid choice. Please enter 1-5: ";
            cin >> soundChoice;
        }

        // Ask about the user's preferred energy level
        cout << "\n- What energy level do you prefer?\n";
        cout << "1. Chill\n";
        cout << "2. Moderate\n";
        cout << "3. High energy\n";

        cout << "\nEnter your choice (1-3): ";
        cin >> energyChoice;

        // Validate energy preference
        while (energyChoice < 1 || energyChoice > 3) {
            cout << "Invalid choice. Please enter 1-3: ";
            cin >> energyChoice;
        }

        // Ask whether the user prefers vocals, beats, or both
        cout << "\n- What do you enjoy more in music?\n";
        cout << "1. Vocals\n";
        cout << "2. Beats\n";
        cout << "3. Both\n";

        cout << "\nEnter your choice (1-3): ";
        cin >> styleChoice;

        // Validate music style preference
        while (styleChoice < 1 || styleChoice > 3) {
            cout << "Invalid choice. Please enter 1-3: ";
            cin >> styleChoice;
        }

        // Display personalized recommendation
        cout << "\n------------------------------------\n";
        cout << "          YOUR RESULT\n";
        cout << "------------------------------------\n";

        // Sound choice 1 represents Pop
        if (soundChoice == 1) {

            cout << "Recommended Genre: Pop\n";

            // Select a Pop mix based on energy and style preferences
            if (energyChoice == 1 && styleChoice == 1)
                cout << "Recommended Mix: Acoustic Pop Mix\n";

            else if (energyChoice == 1 && styleChoice == 2)
                cout << "Recommended Mix: Chill Pop Beats\n";

            else if (energyChoice == 3 && styleChoice == 1)
                cout << "Recommended Mix: Pop Vocal Hits\n";

            else if (energyChoice == 3 && styleChoice == 2)
                cout << "Recommended Mix: Dance Pop Mix\n";

            else
                cout << "Recommended Mix: Pop Hits Mix\n";

            // Display example songs from the recommended genre
            cout << "\nSuggested Songs:\n";
            cout << "- Espresso - Sabrina Carpenter\n";
            cout << "- BIRDS OF A FEATHER - Billie Eilish\n";
            cout << "- Die With A Smile - Lady Gaga & Bruno Mars\n";
        }

        // Sound choice 2 represents R&B
        else if (soundChoice == 2) {

            cout << "Recommended Genre: R&B\n";

            // Select an R&B mix based on energy and style preferences
            if (energyChoice == 1 && styleChoice == 1)
                cout << "Recommended Mix: Smooth R&B Vocals\n";

            else if (energyChoice == 1 && styleChoice == 2)
                cout << "Recommended Mix: Chill R&B Beats\n";

            else if (energyChoice == 3 && styleChoice == 2)
                cout << "Recommended Mix: Upbeat R&B Mix\n";

            else
                cout << "Recommended Mix: R&B Essentials\n";

            cout << "\nSuggested Songs:\n";
            cout << "- Snooze - SZA\n";
            cout << "- Best Part - Daniel Caesar ft. H.E.R.\n";
            cout << "- Leave The Door Open - Silk Sonic\n";
        }

        // Sound choice 3 represents Hip-Hop
        else if (soundChoice == 3) {

            cout << "Recommended Genre: Hip-Hop\n";

            // Select a Hip-Hop mix based on energy and style preferences
            if (energyChoice == 1 && styleChoice == 2)
                cout << "Recommended Mix: Lo-Fi Hip-Hop Beats\n";

            else if (energyChoice == 3 && styleChoice == 2)
                cout << "Recommended Mix: Hip-Hop Energy\n";

            else if (styleChoice == 1)
                cout << "Recommended Mix: Rap & Vocal Mix\n";

            else
                cout << "Recommended Mix: Hip-Hop Essentials\n";

            cout << "\nSuggested Songs:\n";
            cout << "- HUMBLE. - Kendrick Lamar\n";
            cout << "- God's Plan - Drake\n";
            cout << "- See You Again - Tyler, The Creator ft. Kali Uchis\n";
        }

        // Sound choice 4 represents Rock
        else if (soundChoice == 4) {

            cout << "Recommended Genre: Rock\n";

            // Select a Rock mix based on the preferred energy level
            if (energyChoice == 1)
                cout << "Recommended Mix: Soft Rock Mix\n";

            else if (energyChoice == 3)
                cout << "Recommended Mix: Hard Rock Energy\n";

            else
                cout << "Recommended Mix: Rock Essentials\n";

            cout << "\nSuggested Songs:\n";
            cout << "- Smells Like Teen Spirit - Nirvana\n";
            cout << "- Do I Wanna Know? - Arctic Monkeys\n";
            cout << "- The Pretender - Foo Fighters\n";
        }

        // Sound choice 5 represents Electronic
        else if (soundChoice == 5) {

            cout << "Recommended Genre: Electronic\n";

            // Select an Electronic mix based on energy and style preferences
            if (energyChoice == 1)
                cout << "Recommended Mix: Chill Electronic\n";

            else if (energyChoice == 3 && styleChoice == 2)
                cout << "Recommended Mix: EDM Energy Mix\n";

            else
                cout << "Recommended Mix: Electronic Essentials\n";

            cout << "\nSuggested Songs:\n";
            cout << "- Clarity - Zedd ft. Foxes\n";
            cout << "- Wake Me Up - Avicii\n";
            cout << "- Something Just Like This - The Chainsmokers & Coldplay\n";
        }

        cout << "------------------------------------\n";
    }

    // ============================================
    // OPTION 2: BROWSE BY GENRE
    // ============================================
    else if (menuChoice == 2) {

        cout << "\n------ BROWSE BY GENRE ------\n";

        cout << "\nChoose your preferred genre.\n\n";
        cout << "1. Pop\n";
        cout << "2. R&B\n";
        cout << "3. Hip-Hop\n";
        cout << "4. Rock\n";
        cout << "5. Electronic\n";

        cout << "\nEnter your choice (1-5): ";
        cin >> genreChoice;

        // Make sure the selected genre is valid
        while (genreChoice < 1 || genreChoice > 5) {
            cout << "Invalid choice. Please enter 1-5: ";
            cin >> genreChoice;
        }

        cout << "\n------------------------------------\n";

        // Display a predefined mix and songs for the selected genre
        switch (genreChoice) {

            case 1:
                cout << "Genre: Pop\n";
                cout << "Recommended Mix: Pop Hits Mix\n";

                cout << "\nSuggested Songs:\n";
                cout << "- Espresso - Sabrina Carpenter\n";
                cout << "- BIRDS OF A FEATHER - Billie Eilish\n";
                cout << "- Die With A Smile - Lady Gaga & Bruno Mars\n";
                break;

            case 2:
                cout << "Genre: R&B\n";
                cout << "Recommended Mix: R&B Vibes\n";

                cout << "\nSuggested Songs:\n";
                cout << "- Snooze - SZA\n";
                cout << "- Best Part - Daniel Caesar ft. H.E.R.\n";
                cout << "- Leave The Door Open - Silk Sonic\n";
                break;

            case 3:
                cout << "Genre: Hip-Hop\n";
                cout << "Recommended Mix: Hip-Hop Essentials\n";

                cout << "\nSuggested Songs:\n";
                cout << "- HUMBLE. - Kendrick Lamar\n";
                cout << "- God's Plan - Drake\n";
                cout << "- See You Again - Tyler, The Creator ft. Kali Uchis\n";
                break;

            case 4:
                cout << "Genre: Rock\n";
                cout << "Recommended Mix: Rock Essentials\n";

                cout << "\nSuggested Songs:\n";
                cout << "- Smells Like Teen Spirit - Nirvana\n";
                cout << "- Do I Wanna Know? - Arctic Monkeys\n";
                cout << "- The Pretender - Foo Fighters\n";
                break;

            case 5:
                cout << "Genre: Electronic\n";
                cout << "Recommended Mix: Electronic Energy\n";

                cout << "\nSuggested Songs:\n";
                cout << "- Clarity - Zedd ft. Foxes\n";
                cout << "- Wake Me Up - Avicii\n";
                cout << "- Something Just Like This - The Chainsmokers & Coldplay\n";
                break;
        }

        cout << "------------------------------------\n";
    }

    // ============================================
    // OPTION 3: RETURN TO MAIN MENU
    // ============================================
    else if (menuChoice == 3) {

        // Return control to the main program
        cout << "\nReturning to main menu...\n";
    }
}