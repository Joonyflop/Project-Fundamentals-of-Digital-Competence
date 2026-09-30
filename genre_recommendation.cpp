#include <iostream>
#include "recommendations.h"

using namespace std;

// Member 2 - Genre Recommendation Module
void genreRecommendation() {
  int menuChoice;
    int genreChoice;

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

    cout << "\n------------------------------------\n";

    cout << "\nWhat genre are you in the mood for?\n\n";
    cout << "1. Pop\n";
    cout << "2. R&B\n";
    cout << "3. Hip-Hop\n";
    cout << "4. Rock\n";
    cout << "5. Electronic\n";

    cout << "\nEnter your choice (1-5): ";
    cin >> genreChoice;

    cout << "\n------------------------------------\n";

    switch (genreChoice) {
        case 1:
            cout << "Genre: Pop\n";
            cout << "Recommended Mix: Pop Hits Mix\n";
            break;

        case 2:
            cout << "Genre: R&B\n";
            cout << "Recommended Mix: R&B Vibes\n";
            break;

        case 3:
            cout << "Genre: Hip-Hop\n";
            cout << "Recommended Mix: Hip-Hop Essentials\n";
            break;

        case 4:
            cout << "Genre: Rock\n";
            cout << "Recommended Mix: Rock Essentials\n";
            break;

        case 5:
            cout << "Genre: Electronic\n";
            cout << "Recommended Mix: Electronic Energy\n";
            break;

        default:
            cout << "Invalid choice. Please select 1-5.\n";
    }

    cout << "------------------------------------\n";
}