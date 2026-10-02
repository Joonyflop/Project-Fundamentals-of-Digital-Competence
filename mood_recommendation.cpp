#include <iostream>
#include <string>
#include "recommendations.h"

using namespace std;

// Music categories
static const int HAPPY = 0;
static const int SAD = 1;
static const int CHILL = 2;
static const int ENERGETIC = 3;

static const string categoryNames[4] = {"Happy", "Sad", "Chill", "Energetic"};
static const string intensityNames[3] = {"Soft", "Moderate", "Powerful"};

// songs[category][intensity]
static const string songs[4][3] = {
    {"Here Comes the Sun - The Beatles", "Happy - Pharrell Williams", "Uptown Funk - Mark Ronson"},   // Happy
    {"Skinny Love - Bon Iver", "Someone Like You - Adele", "Rolling in the Deep - Adele"},            // Sad
    {"Ocean Eyes - Billie Eilish", "Location - Khalid", "Redbone - Childish Gambino"},                // Chill
    {"Sunflower - Post Malone", "Levitating - Dua Lipa", "Titanium - David Guetta ft. Sia"}           // Energetic
};

static const string playlists[4] = {"Happy Hits", "Sad Songs", "Chill Hits", "Power Workout"};

static int askQuestion(const string& question, const string options[], int count) {
    cout << "\n" << question << "\n";
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << options[i] << "\n";
    }
    return getValidChoice("Enter choice: ", 1, count);
}

static int pickCategory(int mood, int goal) {
    if (goal == 3) return CHILL;
    if (goal == 4) return ENERGETIC;

    if (goal == 1) {
        if (mood == 1) return HAPPY;
        if (mood == 2) return SAD;
        if (mood == 3) return CHILL;
        if (mood == 4) return ENERGETIC;
        return CHILL;
    }

    // Goal 2: Improve my mood
    if (mood == 4) return ENERGETIC;   
    if (mood == 2 || mood == 5) return CHILL;
    return HAPPY;
}

// Member 1 - Mood Recommendation Module
GenreResult moodRecommendation() {
    string moods[5] = {"Happy", "Sad", "Chill", "Energetic", "Stressed"};
    string goals[4] = {"Match my mood", "Improve my mood", "Calm me down", "Boost my energy"};

    cout << "\n====================================\n";
    cout << "          YOUTUBE MUSIC             \n";
    cout << "       MOOD RECOMMENDATION          \n";
    cout << "====================================\n";
    cout << "1. Find Music by Mood & Goal\n";
    cout << "2. Back to Main Menu\n";

    int choice = getValidChoice("Enter choice (1-2): ", 1, 2);

    if (choice == 1) {
        int mood = askQuestion("What is your current mood", moods, 5);
        int goal = askQuestion("What do you want the music to do?", goals, 4);
        int intensity = askQuestion("3. Preferred intensity", intensityNames, 3);

        int category = pickCategory(mood, goal);

        GenreResult result;
        result.genre = categoryNames[category] + " (" + intensityNames[intensity - 1] + ")";
        result.mix = playlists[category];
        result.songs.push_back(songs[category][intensity - 1]);

        cout << "\n------------------------------------\n";
        cout << "  RECOMMENDATION: " << result.genre << "\n";
        cout << "------------------------------------\n";
        cout << "  Song: " << result.songs[0] << "\n";
        cout << "  Playlist: " << result.mix << "\n";
        cout << "------------------------------------\n";

        return result;
    }

    cout << "\nReturning to main menu...\n";
    return {"", "", {}};
}
