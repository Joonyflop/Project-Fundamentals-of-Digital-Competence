#include <iostream>
#include <string>
#include <cstdlib>
#include "recommendations.h"

using namespace std;

// SHOW ACTIVITY SUGGESTIONS

string showSuggestions(
    const string& title,
    const string& vibe,
    const string suggestions[],
    int count
) {
system("cls");
    string result;

    cout << "\n====================================\n";
    cout << "       ACTIVITY RECOMMENDATION\n";
    cout << "====================================\n";

    cout << "\nSuggestions for " << title << ":\n";
    cout << "Vibe: " << vibe << "\n";

    result =
        "Activity Recommendation"
        "\n   Activity: " + title +
        "\n   Vibe: " + vibe +
        "\n   Suggestions:";


    for (int i = 0; i < count; i++) {

        cout << "- " << suggestions[i] << "\n";

        result +=
            "\n   - " + suggestions[i];
    }

    cout << "\n====================================\n";

    return result;
}


// ACTIVITY RECOMMENDATION

string activityRecommendation() {

    // Studying
    const string studying[] = {

        "Playlist: Baroque Focus",

        "Song: 'Air on the G String' by Johann Sebastian Bach",

        "Song: 'Winter (Four Seasons)' by Antonio Vivaldi",

        "Song: 'Canon in D' by Johann Pachelbel"
    };


    // Workout
    const string workout[] = {

        "Song: 'The One That Got Away' by Katy Perry",

        "Song: 'I Knew You Were Trouble' by Taylor Swift (Red)",

        "Song: '22' by Taylor Swift (Red)",

        "Song: 'We Are Never Ever Getting Back Together' by Taylor Swift (Red)",

        "Playlist: Taylor Swift - Red (Taylor's Version)"
    };


    // Driving
    const string driving[] = {

        "Song: 'Espresso' by Sabrina Carpenter",

        "Song: 'Please Please Please' by Sabrina Carpenter",

        "Song: 'Break Free' by Ariana Grande",

        "Song: 'yes, and?' by Ariana Grande",

        "Playlist: Happy Pop Road Trip"
    };


    // Relaxing
    const string relaxing[] = {

        "Song: 'Young and Beautiful' by Lana Del Rey",

        "Song: 'Video Games' by Lana Del Rey",

        "Song: 'Summertime Sadness' by Lana Del Rey",

        "Playlist: Soft Lana Del Rey Vibes"
    };


    // Crashout
    const string crashout[] = {

        "Song: 'good 4 u' by Olivia Rodrigo",

        "Song: 'vampire' by Olivia Rodrigo",

        "Song: 'get him back!' by Olivia Rodrigo",

        "Playlist: Olivia Rodrigo Crashout Mix"
    };


    cout << "\n====================================\n";
    cout << "       ACTIVITY RECOMMENDATION\n";
    cout << "====================================\n";

    cout << "\nChoose an activity:\n\n";

    cout << "1. Studying\n";
    cout << "2. Workout\n";
    cout << "3. Driving\n";
    cout << "4. Relaxing\n";
    cout << "5. Crashout\n";
    cout << "6. Back to Main Menu\n";


    int activity = getValidChoice(
        "\nEnter your choice: ",
        1,
        6
    );


    switch (activity) {

        case 1:

            return showSuggestions(
                "Studying",
                "Calm and focused (Baroque)",
                studying,
                4
            );


        case 2:

            return showSuggestions(
                "Workout",
                "Emotional but energetic (Red era)",
                workout,
                5
            );


        case 3:

            return showSuggestions(
                "Driving",
                "Happy songs you never want to end",
                driving,
                5
            );


        case 4:

            return showSuggestions(
                "Relaxing",
                "Soft, dreamy, and slow",
                relaxing,
                4
            );


        case 5:

            return showSuggestions(
                "Crashout",
                "Loud, dramatic, and fully unhinged",
                crashout,
                4
            );


        case 6:

            cout << "\nReturning to main menu...\n";

            return "";
    }


    return "";
}