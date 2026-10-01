#include <iostream> 
#include "recommendations.h" 
 
using namespace std; 
 
 
// SHARED GENRE RECOMMENDATION LOGIC 
// Generates a genre recommendation based on the user's three preferences
// The result contains the recommended genre, playlist mix, and songs
 
GenreResult getGenreResult( 
    int soundChoice, 
    int energyChoice, 
    int styleChoice 
) { 
 
    // Stores the final genre recommendation
    GenreResult result; 
 
 
    // POP 
    // soundChoice 1 represents catchy and mainstream music
    if (soundChoice == 1) { 
 
        result.genre = "Pop"; 
 
        // Select a suitable Pop mix based on energy level and music style
        if (energyChoice == 1 && styleChoice == 1) 
            result.mix = "Acoustic Pop Mix"; 
 
        else if (energyChoice == 1 && styleChoice == 2) 
            result.mix = "Chill Pop Beats"; 
 
        else if (energyChoice == 3 && styleChoice == 1) 
            result.mix = "Pop Vocal Hits"; 
 
        else if (energyChoice == 3 && styleChoice == 2) 
            result.mix = "Dance Pop Mix"; 
 
        // Default Pop mix for other combinations
        else 
            result.mix = "Pop Hits Mix"; 
 
 
        // Store the recommended Pop songs
        result.songs = { 
            "'Espresso' by Sabrina Carpenter", 
            "'BIRDS OF A FEATHER' by Billie Eilish", 
            "'Die With A Smile' by Lady Gaga & Bruno Mars" 
        }; 
    } 
 
 
    // R&B 
    // soundChoice 2 represents smooth and soulful music
    else if (soundChoice == 2) { 
 
        result.genre = "R&B"; 
 
        // Select a suitable R&B mix based on energy level and music style
        if (energyChoice == 1 && styleChoice == 1) 
            result.mix = "Smooth R&B Vocals"; 
 
        else if (energyChoice == 1 && styleChoice == 2) 
            result.mix = "Chill R&B Beats"; 
 
        else if (energyChoice == 3 && styleChoice == 2) 
            result.mix = "Upbeat R&B Mix"; 
 
        // Default R&B mix for other combinations
        else 
            result.mix = "R&B Essentials"; 
 
 
        // Store the recommended R&B songs
        result.songs = { 
            "'Snooze' by SZA", 
            "'Best Part' by Daniel Caesar ft. H.E.R.", 
            "'Leave The Door Open' by Silk Sonic" 
        }; 
    } 
 
 
    // HIP-HOP 
    // soundChoice 3 represents strong beats and rhythm
    else if (soundChoice == 3) { 
 
        result.genre = "Hip-Hop"; 
 
        // Select a suitable Hip-Hop mix based on the user's preferences
        if (energyChoice == 1 && styleChoice == 2) 
            result.mix = "Lo-Fi Hip-Hop Beats"; 
 
        else if (energyChoice == 3 && styleChoice == 2) 
            result.mix = "Hip-Hop Energy"; 
 
        else if (styleChoice == 1) 
            result.mix = "Rap & Vocal Mix"; 
 
        // Default Hip-Hop mix for other combinations
        else 
            result.mix = "Hip-Hop Essentials"; 
 
 
        // Store the recommended Hip-Hop songs
        result.songs = { 
            "'HUMBLE.' by Kendrick Lamar", 
            "'God's Plan' by Drake", 
            "'See You Again' by Tyler, The Creator ft. Kali Uchis" 
        }; 
    } 
 
 
    // ROCK 
    // soundChoice 4 represents guitar and drums
    else if (soundChoice == 4) { 
 
        result.genre = "Rock"; 
 
        // Select the Rock mix according to the preferred energy level
        if (energyChoice == 1) 
            result.mix = "Soft Rock Mix"; 
 
        else if (energyChoice == 3) 
            result.mix = "Hard Rock Energy"; 
 
        // Default Rock mix for moderate or other combinations
        else 
            result.mix = "Rock Essentials"; 
 
 
        // Store the recommended Rock songs
        result.songs = { 
            "'Smells Like Teen Spirit' by Nirvana", 
            "'Do I Wanna Know?' by Arctic Monkeys", 
            "'The Pretender' by Foo Fighters" 
        }; 
    } 
 
 
    // ELECTRONIC 
    // soundChoice 5 represents electronic and synthesized music
    else if (soundChoice == 5) { 
 
        result.genre = "Electronic"; 
 
        // Select an Electronic mix based on energy level and style
        if (energyChoice == 1) 
            result.mix = "Chill Electronic"; 
 
        else if (energyChoice == 3 && styleChoice == 2) 
            result.mix = "EDM Energy Mix"; 
 
        // Default Electronic mix for other combinations
        else 
            result.mix = "Electronic Essentials"; 
 
 
        // Store the recommended Electronic songs
        result.songs = { 
            "'Clarity' by Zedd ft. Foxes", 
            "'Wake Me Up' by Avicii", 
            "'Something Just Like This' by The Chainsmokers & Coldplay" 
        }; 
    } 
 
 
    // Return the completed recommendation
    return result; 
} 
 
 
// GENRE RECOMMENDATION MENU 
// Provides two recommendation methods: Find My Genre and Browse by Genre
 
GenreResult genreRecommendation() { 
 
    // Variables used to store the user's selections
    int genreChoice; 
    int soundChoice; 
    int energyChoice; 
    int styleChoice; 
 
 
    // Genre menu 
    // Display the Genre Recommendation submenu
    cout << "\n====================================\n"; 
    cout << "       GENRE RECOMMENDATION\n"; 
    cout << "====================================\n"; 
 
    cout << "\nWhat would you like to do?\n\n"; 
 
    cout << "1. Find My Genre\n"; 
    cout << "2. Browse by Genre\n"; 
    cout << "3. Back to Main Menu\n"; 
 
    // Validate the menu input and only accept choices from 1 to 3
    int menuChoice = getValidChoice("\nEnter your choice: ", 1, 3); 
 
 
    // OPTION 1: FIND MY GENRE 
    // Determines a suitable genre by asking the user three preference questions
 
    if (menuChoice == 1) { 
 
        cout << "\n------ FIND MY GENRE ------\n"; 
 
        cout << "Answer a few questions and we will " 
                "find a genre for you!\n"; 
 
 
        // QUESTION 1 
        // Ask the user about their preferred type of sound
        cout << "\n- What kind of sound do you prefer?\n"; 
 
        cout << "1. Catchy and mainstream\n"; 
        cout << "2. Smooth and soulful\n"; 
        cout << "3. Strong beats and rhythm\n"; 
        cout << "4. Guitar and drums\n"; 
        cout << "5. Electronic and synthesized\n"; 
 
        // Input validation ensures only choices 1 to 5 are accepted
        soundChoice = getValidChoice("\nEnter your choice (1-5): ", 1, 5); 
 
 
        // QUESTION 2 
        // Ask the user for their preferred music energy level
        cout << "\n- What energy level do you prefer?\n"; 
 
        cout << "1. Chill\n"; 
        cout << "2. Moderate\n"; 
        cout << "3. High energy\n"; 
 
        // Input validation ensures only choices 1 to 3 are accepted
        energyChoice = getValidChoice("\nEnter your choice (1-3): ", 1, 3); 
 
 
        // QUESTION 3 
        // Ask whether the user prefers vocals, beats, or both
        cout << "\n- What do you enjoy more in music?\n"; 
 
        cout << "1. Vocals\n"; 
        cout << "2. Beats\n"; 
        cout << "3. Both\n"; 
 
        // Input validation ensures only choices 1 to 3 are accepted
        styleChoice = getValidChoice("\nEnter your choice (1-3): ", 1, 3); 
 
 
        // Generate recommendation 
        // Pass the three user preferences to the shared recommendation function
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
 
        // Loop through and display each recommended song
        for (const string& song : result.songs) { 
 
            cout << "   - Song: " << song << "\n"; 
        } 
 
        // Display the playlist mix selected from the user's preferences
        cout << "   - Playlist: " 
             << result.mix << "\n"; 
 
        cout << "------------------------------------\n"; 
 
 
        // Return result to main.cpp 
        // This allows the recommendation to be used or saved by the main program
        return result; 
    } 
 
 
    // OPTION 2: BROWSE BY GENRE 
    // Allows the user to directly select a genre instead of answering questions
 
    else if (menuChoice == 2) { 
 
        cout << "\n------ BROWSE BY GENRE ------\n"; 
 
        cout << "\nChoose your preferred genre.\n\n"; 
 
        cout << "1. Pop\n"; 
        cout << "2. R&B\n"; 
        cout << "3. Hip-Hop\n"; 
        cout << "4. Rock\n"; 
        cout << "5. Electronic\n"; 
 
        // Validate the genre selection and only accept choices 1 to 5
        genreChoice = getValidChoice("\nEnter your choice (1-5): ", 1, 5); 
 
 
        // Stores the selected genre and its recommendations
        GenreResult result; 
 
 
        // POP 
        if (genreChoice == 1) { 
 
            result.genre = "Pop"; 
            result.mix = "Pop Hits Mix"; 
 
            // Store Pop song recommendations
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
 
            // Store R&B song recommendations
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
 
            // Store Hip-Hop song recommendations
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
 
            // Store Rock song recommendations
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
 
            // Store Electronic song recommendations
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
 
        // Loop through and display every song in the selected genre
        for (const string& song : result.songs) { 
 
            cout << "   - Song: " << song << "\n"; 
        } 
 
        // Display the playlist for the selected genre
        cout << "   - Playlist: " 
             << result.mix << "\n"; 
 
        cout << "------------------------------------\n"; 
 
 
        // Return result to main.cpp 
        // The returned recommendation can be saved by the main program
        return result; 
    } 
 
 
    // OPTION 3: BACK TO MAIN MENU 
 
    else { 
 
        cout << "\nReturning to main menu...\n"; 
 
        // Empty result means nothing should be saved 
        return {"", "", {}}; 
    } 
}