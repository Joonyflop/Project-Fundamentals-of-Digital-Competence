#include <iostream>
#include "recommendations.h"

using namespace std;


// ==================================================
// SHARED GENRE RECOMMENDATION LOGIC
// Can be used by both terminal and web interface
// ==================================================

GenreResult getGenreResult(
    int soundChoice,
    int energyChoice,
    int styleChoice
) {
    GenreResult result;

    // POP
    if (soundChoice == 1) {

        result.genre = "Pop";

        if (energyChoice == 1 && styleChoice == 1)
            result.mix = "Acoustic Pop Mix";

        else if (energyChoice == 1 && styleChoice == 2)
            result.mix = "Chill Pop Beats";

        else if (energyChoice == 3 && styleChoice == 1)
            result.mix = "Pop Vocal Hits";

        else if (energyChoice == 3 && styleChoice == 2)
            result.mix = "Dance Pop Mix";

        else
            result.mix = "Pop Hits Mix";

        result.songs = {
            "Espresso - Sabrina Carpenter",
            "BIRDS OF A FEATHER - Billie Eilish",
            "Die With A Smile - Lady Gaga & Bruno Mars"
        };
    }


    // R&B
    else if (soundChoice == 2) {

        result.genre = "R&B";

        if (energyChoice == 1 && styleChoice == 1)
            result.mix = "Smooth R&B Vocals";

        else if (energyChoice == 1 && styleChoice == 2)
            result.mix = "Chill R&B Beats";

        else if (energyChoice == 3 && styleChoice == 2)
            result.mix = "Upbeat R&B Mix";

        else
            result.mix = "R&B Essentials";

        result.songs = {
            "Snooze - SZA",
            "Best Part - Daniel Caesar ft. H.E.R.",
            "Leave The Door Open - Silk Sonic"
        };
    }


    // HIP-HOP
    else if (soundChoice == 3) {

        result.genre = "Hip-Hop";

        if (energyChoice == 1 && styleChoice == 2)
            result.mix = "Lo-Fi Hip-Hop Beats";

        else if (energyChoice == 3 && styleChoice == 2)
            result.mix = "Hip-Hop Energy";

        else if (styleChoice == 1)
            result.mix = "Rap & Vocal Mix";

        else
            result.mix = "Hip-Hop Essentials";

        result.songs = {
            "HUMBLE. - Kendrick Lamar",
            "God's Plan - Drake",
            "See You Again - Tyler, The Creator ft. Kali Uchis"
        };
    }


    // ROCK
    else if (soundChoice == 4) {

        result.genre = "Rock";

        if (energyChoice == 1)
            result.mix = "Soft Rock Mix";

        else if (energyChoice == 3)
            result.mix = "Hard Rock Energy";

        else
            result.mix = "Rock Essentials";

        result.songs = {
            "Smells Like Teen Spirit - Nirvana",
            "Do I Wanna Know? - Arctic Monkeys",
            "The Pretender - Foo Fighters"
        };
    }


    // ELECTRONIC
    else if (soundChoice == 5) {

        result.genre = "Electronic";

        if (energyChoice == 1)
            result.mix = "Chill Electronic";

        else if (energyChoice == 3 && styleChoice == 2)
            result.mix = "EDM Energy Mix";

        else
            result.mix = "Electronic Essentials";

        result.songs = {
            "Clarity - Zedd ft. Foxes",
            "Wake Me Up - Avicii",
            "Something Just Like This - The Chainsmokers & Coldplay"
        };
    }

    return result;
}


// ==================================================
// MEMBER 2 - GENRE RECOMMENDATION MODULE
// ==================================================

void genreRecommendation() {

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


    // Validate menu choice
    while (menuChoice < 1 || menuChoice > 3) {

        cout << "Invalid choice. Please enter 1-3: ";
        cin >> menuChoice;
    }


    // ==================================================
    // OPTION 1: FIND MY GENRE
    // ==================================================

    if (menuChoice == 1) {

        cout << "\n------ FIND MY GENRE ------\n";
        cout << "Answer a few questions and we will find a genre for you!\n";


        // QUESTION 1
        cout << "\n- What kind of sound do you prefer?\n";
        cout << "1. Catchy and mainstream\n";
        cout << "2. Smooth and soulful\n";
        cout << "3. Strong beats and rhythm\n";
        cout << "4. Guitar and drums\n";
        cout << "5. Electronic and synthesized\n";

        cout << "\nEnter your choice (1-5): ";
        cin >> soundChoice;


        while (soundChoice < 1 || soundChoice > 5) {

            cout << "Invalid choice. Please enter 1-5: ";
            cin >> soundChoice;
        }


        // QUESTION 2
        cout << "\n- What energy level do you prefer?\n";
        cout << "1. Chill\n";
        cout << "2. Moderate\n";
        cout << "3. High energy\n";

        cout << "\nEnter your choice (1-3): ";
        cin >> energyChoice;


        while (energyChoice < 1 || energyChoice > 3) {

            cout << "Invalid choice. Please enter 1-3: ";
            cin >> energyChoice;
        }


        // QUESTION 3
        cout << "\n- What do you enjoy more in music?\n";
        cout << "1. Vocals\n";
        cout << "2. Beats\n";
        cout << "3. Both\n";

        cout << "\nEnter your choice (1-3): ";
        cin >> styleChoice;


        while (styleChoice < 1 || styleChoice > 3) {

            cout << "Invalid choice. Please enter 1-3: ";
            cin >> styleChoice;
        }


        // Get recommendation from shared C++ logic
        GenreResult result = getGenreResult(
            soundChoice,
            energyChoice,
            styleChoice
        );


        // Display result
        cout << "\n------------------------------------\n";
        cout << "          YOUR RESULT\n";
        cout << "------------------------------------\n";

        cout << "Recommended Genre: "
             << result.genre << "\n";

        cout << "Recommended Mix: "
             << result.mix << "\n";

        cout << "\nSuggested Songs:\n";


        // Display songs
        for (const string& song : result.songs) {

            cout << "- " << song << "\n";
        }


        cout << "------------------------------------\n";
    }


    // ==================================================
    // OPTION 2: BROWSE BY GENRE
    // ==================================================

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


        // Validate genre
        while (genreChoice < 1 || genreChoice > 5) {

            cout << "Invalid choice. Please enter 1-5: ";
            cin >> genreChoice;
        }


        cout << "\n------------------------------------\n";


        // Display selected genre
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


    // ==================================================
    // OPTION 3: BACK TO MAIN MENU
    // ==================================================

    else if (menuChoice == 3) {

        cout << "\nReturning to main menu...\n";
    }
}