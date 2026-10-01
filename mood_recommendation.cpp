#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Music categories
const int HAPPY = 0;
const int SAD = 1;
const int CHILL = 2;
const int ENERGETIC = 3;

string categoryNames[4] = {"Happy", "Sad", "Chill", "Energetic"};
string intensityNames[3] = {"Soft", "Moderate", "Powerful"};

// songs[category][intensity]
string songs[4][3] = {
    // Soft,                           Moderate,                    Powerful
    {"Here Comes the Sun - The Beatles", "Happy - Pharrell Williams", "Uptown Funk - Mark Ronson"},   // Happy
    {"Skinny Love - Bon Iver", "Someone Like You - Adele", "Rolling in the Deep - Adele"},            // Sad
    {"Ocean Eyes - Billie Eilish", "Location - Khalid", "Redbone - Childish Gambino"},                // Chill
    {"Sunflower - Post Malone", "Levitating - Dua Lipa", "Titanium - David Guetta ft. Sia"}           // Energetic
};

string playlists[4] = {"Happy Hits", "Sad Songs", "Chill Hits", "Power Workout"};

// Show a list and return a valid choice from 1 to count
int askQuestion(string question, string options[], int count) {
    int choice;

    cout << "\n" << question << "\n";
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << options[i] << "\n";
    }

    while (true) {
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > count) {
            cout << "Invalid input. Enter 1 to " << count << ".\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return choice;
        }
    }
}

// Decide the music category from mood (1-5) and goal (1-4)
int pickCategory(int mood, int goal) {
    // Calm me down / Boost my energy ignore the current mood
    if (goal == 3) return CHILL;
    if (goal == 4) return ENERGETIC;

    // Match my mood
    if (goal == 1) {
        if (mood == 1) return HAPPY;
        if (mood == 2) return SAD;
        if (mood == 3) return CHILL;
        if (mood == 4) return ENERGETIC;
        return CHILL;              // Stressed
    }

    // Improve my mood (goal == 2)
    if (mood == 2 || mood == 5) return CHILL;   // Sad or Stressed -> calmer music
    return HAPPY;                               // Happy, Chill, Energetic -> happy music
}

void moodRecommendation() {
    string moods[5] = {"Happy", "Sad", "Chill", "Energetic", "Stressed"};
    string goals[4] = {"Match my mood", "Improve my mood", "Calm me down", "Boost my energy"};
    char again;

    do {
        int mood = askQuestion("1. Current mood", moods, 5);
        int goal = askQuestion("2. What do you want the music to do?", goals, 4);
        int intensity = askQuestion("3. Preferred intensity", intensityNames, 3);

        int category = pickCategory(mood, goal);

        cout << "\n=== " << categoryNames[category] << " / "
             << intensityNames[intensity - 1] << " ===\n";
        cout << "Song: " << songs[category][intensity - 1] << "\n";
        cout << "Playlist: " << playlists[category] << "\n";

        cout << "\nTry again? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');
}

int main() {
    moodRecommendation();
    cout << "Goodbye!\n";
    return 0;
}