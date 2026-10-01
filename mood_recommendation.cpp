#include <iostream>
#include <string>
#include "recommendations.h"

using namespace std;

// Recommends example songs and a playlist that match the selected mood.
GenreResult moodRecommendation() {
    const string moods[4] = {"Happy", "Sad", "Chill", "Energetic"};
    const string playlists[4] = {
        "Happy Hits", "Sad Songs", "Chill Hits", "Power Workout"
    };
    const string songs[4][3] = {
        {"Happy - Pharrell Williams", "Uptown Funk - Mark Ronson ft. Bruno Mars", "Good as Hell - Lizzo"},
        {"Someone Like You - Adele", "Fix You - Coldplay", "When I Was Your Man - Bruno Mars"},
        {"Location - Khalid", "Ocean Eyes - Billie Eilish", "Better Together - Jack Johnson"},
        {"Titanium - David Guetta ft. Sia", "Levitating - Dua Lipa", "Blinding Lights - The Weeknd"}
    };

    cout << "\n===== Mood Recommendation =====\n";
    cout << "1. Happy\n";
    cout << "2. Sad\n";
    cout << "3. Chill\n";
    cout << "4. Energetic\n";

    int choice = getValidChoice("Choose your mood: ", 1, 4);
    int moodIndex = choice - 1;

    GenreResult result;
    result.genre = moods[moodIndex];
    result.mix = "Songs matching your mood";

    cout << "\nRecommendations for " << result.genre << ":\n";
    for (int i = 0; i < 3; ++i) {
        result.songs.push_back(songs[moodIndex][i]);
        cout << i + 1 << ". " << songs[moodIndex][i] << "\n";
    }

    string playlist = "Playlist: " + playlists[moodIndex];
    result.songs.push_back(playlist);
    cout << playlist << "\n";

    return result;
}
