#include <iostream>
#include "recommendations.h"

using namespace std;

// Member 2 - Genre Recommendation Module
void genreRecommendation() {

    int menuChoice;
    int genreChoice;
    int soundChoice;
    int energyChoice;
    int styleChoice;

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

   
   if (menuChoice == 1) {

    cout << "\n------ FIND MY GENRE ------\n";
    cout << "Answer a few questions and we will find a genre for you!\n";

    // Question 1
    cout << "\n1. What kind of sound do you prefer?\n";
    cout << "1. Catchy and mainstream\n";
    cout << "2. Smooth and soulful\n";
    cout << "3. Strong beats and rhythm\n";
    cout << "4. Guitar and drums\n";
    cout << "5. Electronic and synthesized\n";
    cout << "\nEnter your choice (1-5): ";
    cin >> soundChoice;

    // Question 2
    cout << "\n2. What energy level do you prefer?\n";
    cout << "1. Chill\n";
    cout << "2. Moderate\n";
    cout << "3. High energy\n";
    cout << "\nEnter your choice (1-3): ";
    cin >> energyChoice;

    // Question 3
    cout << "\n3. What do you enjoy more in music?\n";
    cout << "1. Vocals\n";
    cout << "2. Beats\n";
    cout << "3. Both\n";
    cout << "\nEnter your choice (1-3): ";
    cin >> styleChoice;

    cout << "\n------------------------------------\n";
    cout << "          YOUR RESULT\n";
    cout << "------------------------------------\n";

    if (soundChoice == 1) {
        cout << "Recommended Genre: Pop\n";

        if (energyChoice == 1)
            cout << "Recommended Mix: Chill Pop Mix\n";
        else if (energyChoice == 2)
            cout << "Recommended Mix: Pop Hits Mix\n";
        else
            cout << "Recommended Mix: Upbeat Pop Mix\n";
    }

    else if (soundChoice == 2) {
        cout << "Recommended Genre: R&B\n";

        if (energyChoice == 1)
            cout << "Recommended Mix: Chill R&B Vibes\n";
        else if (energyChoice == 2)
            cout << "Recommended Mix: R&B Essentials\n";
        else
            cout << "Recommended Mix: Upbeat R&B Mix\n";
    }

    else if (soundChoice == 3) {
        cout << "Recommended Genre: Hip-Hop\n";

        if (energyChoice == 1)
            cout << "Recommended Mix: Chill Hip-Hop\n";
        else if (energyChoice == 2)
            cout << "Recommended Mix: Hip-Hop Essentials\n";
        else
            cout << "Recommended Mix: Hip-Hop Energy\n";
    }

    else if (soundChoice == 4) {
        cout << "Recommended Genre: Rock\n";

        if (energyChoice == 1)
            cout << "Recommended Mix: Soft Rock Mix\n";
        else if (energyChoice == 2)
            cout << "Recommended Mix: Rock Essentials\n";
        else
            cout << "Recommended Mix: Rock Energy Mix\n";
    }

    else if (soundChoice == 5) {
        cout << "Recommended Genre: Electronic\n";

        if (energyChoice == 1)
            cout << "Recommended Mix: Chill Electronic\n";
        else if (energyChoice == 2)
            cout << "Recommended Mix: Electronic Mix\n";
        else
            cout << "Recommended Mix: Electronic Energy\n";
    }

    else {
        cout << "Invalid choice.\n";
    }

    cout << "------------------------------------\n";
}}