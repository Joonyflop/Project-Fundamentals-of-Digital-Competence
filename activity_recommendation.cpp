#include <iostream>
#include <string>
#include "recommendations.h"

using namespace std;

// Prints a title, a short vibe description, and a list of suggestions.
void showSuggestions(const string& title, const string& vibe,
                     const string suggestions[], int count) {
    cout << "\nSuggestions for " << title << ":\n";
    cout << "Vibe: " << vibe << "\n";
    for (int i = 0; i < count; i++) {
        cout << "- " << suggestions[i] << "\n";
    }
}

// Recommends example music for an activity selected by the user.
void activityRecommendation() {
    // Static example data (no real YouTube Music API needed)
    const string studying[] = {
        "Playlist: Baroque Focus",
        "Song: 'Air on the G String' by Johann Sebastian Bach",
        "Song: 'Winter (Four Seasons)' by Antonio Vivaldi",
        "Song: 'Canon in D' by Johann Pachelbel"
    };
    const string workout[] = {
        "Song: 'The One That Got Away' by Katy Perry",
        "Song: 'I Knew You Were Trouble' by Taylor Swift (Red)",
        "Song: '22' by Taylor Swift (Red)",
        "Song: 'We Are Never Ever Getting Back Together' by Taylor Swift (Red)",
        "Playlist: Taylor Swift - Red (Taylor's Version)"
    };
    const string driving[] = {
        "Song: 'Espresso' by Sabrina Carpenter",
        "Song: 'Please Please Please' by Sabrina Carpenter",
        "Song: 'Break Free' by Ariana Grande",
        "Song: 'yes, and?' by Ariana Grande",
        "Playlist: Happy Pop Road Trip"
    };
    const string relaxing[] = {
        "Song: 'Young and Beautiful' by Lana Del Rey",
        "Song: 'Video Games' by Lana Del Rey",
        "Song: 'Summertime Sadness' by Lana Del Rey",
        "Playlist: Soft Lana Del Rey Vibes"
    };
    const string crashout[] = {
        "Song: 'good 4 u' by Olivia Rodrigo",
        "Song: 'vampire' by Olivia Rodrigo",
        "Song: 'get him back!' by Olivia Rodrigo",
        "Playlist: Olivia Rodrigo Crashout Mix"
    };

    int activity;

    do {
        cout << "\n===== Activity Recommendation =====\n";
        cout << "1. Studying\n";
        cout << "2. Workout\n";
        cout << "3. Driving\n";
        cout << "4. Relaxing\n";
        cout << "5. Crashout\n";
        cout << "6. Back to Main Menu\n";
        activity = getValidChoice("Choose an activity: ", 1, 6);

        switch (activity) {
            case 1:
                showSuggestions("studying", "calm and focused (Baroque)", studying, 4);
                break;
            case 2:
                showSuggestions("a workout", "emotional but energetic (Red era)", workout, 5);
                break;
            case 3:
                showSuggestions("driving", "happy songs you never want to end", driving, 5);
                break;
            case 4:
                showSuggestions("relaxing", "soft, dreamy, and slow", relaxing, 4);
                break;
            case 5:
                showSuggestions("a crashout", "loud, dramatic, and fully unhinged", crashout, 4);
                break;
            case 6:
                break;
        }
    } while (activity != 6);
}