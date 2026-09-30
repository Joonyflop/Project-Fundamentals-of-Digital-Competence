#include <iostream>
#include "recommendations.h"

using namespace std;


// SHARED GENRE RECOMMENDATION LOGIC

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
            "'Espresso' by Sabrina Carpenter",
            "'BIRDS OF A FEATHER' by Billie Eilish",
            "'Die With A Smile' by Lady Gaga & Bruno Mars"
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
            "'Snooze' by SZA",
            "'Best Part' by Daniel Caesar ft. H.E.R.",
            "'Leave The Door Open' by Silk Sonic"
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
            "'HUMBLE.' by Kendrick Lamar",
            "'God's Plan' by Drake",
            "'See You Again' by Tyler, The Creator ft. Kali Uchis"
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
            "'Smells Like Teen Spirit' by Nirvana",
            "'Do I Wanna Know?' by Arctic Monkeys",
            "'The Pretender' by Foo Fighters"
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
            "'Clarity' by Zedd ft. Foxes",
            "'Wake Me Up' by Avicii",
            "'Something Just Like This' by The Chainsmokers & Coldplay"
        };
    }


    return result;
}


// GENRE RECOMMENDATION MENU

GenreResult genreRecommendation() {

    int menuChoice;
    int genreChoice;
    int soundChoice;
    int energyChoice;
    int styleChoice;


    // Genre menu
    cout << "\n====================================\n";
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


    // OPTION 1: FIND MY GENRE

    if (menuChoice == 1) {

        cout << "\n------ FIND MY GENRE ------\n";

        cout << "Answer a few questions and we will "
                "find a genre for you!\n";


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


        // Generate recommendation
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

        cout << "\nSuggestions:\n";

        for (const string& song : result.songs) {

            cout << "   - Song: " << song << "\n";
        }

        cout << "   - Playlist: "
             << result.mix << "\n";

        cout << "------------------------------------\n";


        // Return result to main.cpp
        return result;
    }


    // OPTION 2: BROWSE BY GENRE

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


        while (genreChoice < 1 || genreChoice > 5) {

            cout << "Invalid choice. Please enter 1-5: ";
            cin >> genreChoice;
        }


        GenreResult result;


        // POP
        if (genreChoice == 1) {

            result.genre = "Pop";
            result.mix = "Pop Hits Mix";

            result.songs = {
                "'Espresso' by Sabrina Carpenter",
                "'BIRDS OF A FEATHER' by Billie Eilish",
                "'Die With A Smile' by Lady Gaga & Bruno Mars"
            };
        }


        // R&B
        else if (genreChoice == 2) {

            result.genre = "R&B";
            result.mix = "R&B Vibes";

            result.songs = {
                "'Snooze' by SZA",
                "'Best Part' by Daniel Caesar ft. H.E.R.",
                "'Leave The Door Open' by Silk Sonic"
            };
        }


        // HIP-HOP
        else if (genreChoice == 3) {

            result.genre = "Hip-Hop";
            result.mix = "Hip-Hop Essentials";

            result.songs = {
                "'HUMBLE.' by Kendrick Lamar",
                "'God's Plan' by Drake",
                "'See You Again' by Tyler, The Creator ft. Kali Uchis"
            };
        }


        // ROCK
        else if (genreChoice == 4) {

            result.genre = "Rock";
            result.mix = "Rock Essentials";

            result.songs = {
                "'Smells Like Teen Spirit' by Nirvana",
                "'Do I Wanna Know?' by Arctic Monkeys",
                "'The Pretender' by Foo Fighters"
            };
        }


        // ELECTRONIC
        else if (genreChoice == 5) {

            result.genre = "Electronic";
            result.mix = "Electronic Energy";

            result.songs = {
                "'Clarity' by Zedd ft. Foxes",
                "'Wake Me Up' by Avicii",
                "'Something Just Like This' by The Chainsmokers & Coldplay"
            };
        }


        // Display selected genre
        cout << "\n------------------------------------\n";
        cout << "          YOUR RESULT\n";
        cout << "------------------------------------\n";

        cout << "Recommended Genre: "
             << result.genre << "\n";

        cout << "\nSuggestions:\n";

        for (const string& song : result.songs) {

            cout << "   - Song: " << song << "\n";
        }

        cout << "   - Playlist: "
             << result.mix << "\n";

        cout << "------------------------------------\n";


        // Return result to main.cpp
        return result;
    }


    // OPTION 3: BACK TO MAIN MENU

    else {

        cout << "\nReturning to main menu...\n";

        // Empty result means nothing should be saved
        return {"", "", {}};
    }
}