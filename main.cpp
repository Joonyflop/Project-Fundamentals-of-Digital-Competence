#include <iostream>
#include <limits>
#include "recommendations.h"

using namespace std;

// Reads a whole number in the requested range and recovers from bad input.
int getValidChoice(const char* prompt, int minimum, int maximum) {
    int choice;

    while (true) {
        cout << prompt;
        cin >> choice;

        if (cin.fail()) {
            // Input was not a number (e.g. "abc"), so reset cin and discard it
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
        } else {
            // Discard anything left on the line (e.g. the "abc" in "3abc")
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (choice < minimum || choice > maximum) {
                cout << "Invalid choice. Enter a number from " << minimum
                     << " to " << maximum << ".\n";
            } else {
                return choice;
            }
        }
    }
}

int main() {
    int choice;

    cout << "YouTube Music Recommendation System\n";

    do {
        cout << "\n===== Main Menu =====\n";
        cout << "1. Mood Recommendation\n";
        cout << "2. Genre Recommendation\n";
        cout << "3. Activity Recommendation\n";
        cout << "4. Music Discovery / Preference\n";
        cout << "5. Exit\n";

        choice = getValidChoice("Enter your choice: ", 1, 5);

        switch (choice) {
            case 1:
                moodRecommendation();
                break;
            case 2:
                genreRecommendation();
                break;
            case 3:
                activityRecommendation();
                break;
            case 4:
                discoveryRecommendation();
                break;
            case 5:
                cout << "Thanks for using the program. Goodbye!\n";
                break;
        }
    } while (choice != 5);

    return 0;
}