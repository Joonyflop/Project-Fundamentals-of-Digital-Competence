#include <iostream>
#include <string>
#include <cstdlib>
#include "recommendations.h"

using namespace std;

// CHOOSE TIME OF DAY

string chooseTimeOfDay() {

    cout << "\n====================================\n";
    cout << "           TIME OF DAY\n";
    cout << "====================================\n";

    cout << "\nWhen will you listen?\n\n";

    cout << "1. Morning\n";
    cout << "2. Afternoon\n";
    cout << "3. Evening\n";
    cout << "4. Night\n";

    int timeChoice = getValidChoice(
        "\nEnter your choice: ",
        1,
        4
    );

    switch (timeChoice) {
        case 1:
            return "Morning";
        case 2:
            return "Afternoon";
        case 3:
            return "Evening";
        case 4:
            return "Night";
    }

    return "Morning";
}


// TIP FOR EACH TIME OF DAY

string getTimeTip(const string& timeOfDay) {

    if (timeOfDay == "Morning") {
        return "A fresh start to your day!";
    }
    else if (timeOfDay == "Afternoon") {
        return "Perfect to keep your energy going.";
    }
    else if (timeOfDay == "Evening") {
        return "A nice way to wrap up the day.";
    }

    return "Best with the volume turned down low.";
}


// SHOW ACTIVITY SUGGESTIONS

string showSuggestions(
    const string& title,
    const string& vibe,
    const string& timeOfDay,
    const string suggestions[],
    int count
) {
system("cls");
    string result;
    string tip = getTimeTip(timeOfDay);

    cout << "\n====================================\n";
    cout << "       ACTIVITY RECOMMENDATION\n";
    cout << "====================================\n";

    cout << "\nSuggestions for " << title << ":\n";
    cout << "Time of day: " << timeOfDay << "\n";
    cout << "Vibe: " << vibe << "\n";
    cout << "Tip: " << tip << "\n";

    result =
        "Activity Recommendation"
        "\n   Activity: " + title +
        "\n   Time of day: " + timeOfDay +
        "\n   Vibe: " + vibe +
        "\n   Tip: " + tip +
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


    // Back to main menu: no need to ask for the time of day
    if (activity == 6) {

        cout << "\nReturning to main menu...\n";

        return "";
    }


    // Ask for the time of day after an activity is chosen
    string timeOfDay = chooseTimeOfDay();


    switch (activity) {

        case 1:

            return showSuggestions(
                "Studying",
                "Calm and focused (Baroque)",
                timeOfDay,
                studying,
                4
            );


        case 2:

            return showSuggestions(
                "Workout",
                "Emotional but energetic (Red era)",
                timeOfDay,
                workout,
                5
            );


        case 3:

            return showSuggestions(
                "Driving",
                "Happy songs you never want to end",
                timeOfDay,
                driving,
                5
            );


        case 4:

            return showSuggestions(
                "Relaxing",
                "Soft, dreamy, and slow",
                timeOfDay,
                relaxing,
                4
            );


        case 5:

            return showSuggestions(
                "Crashout",
                "Loud, dramatic, and fully unhinged",
                timeOfDay,
                crashout,
                4
            );
    }


    return "";
}