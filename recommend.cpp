#include <iostream>
#include <string>
using namespace std;

void youtubeMusic() {
    int choice;

    cout << "\n===== YouTube Music =====" << endl;
    cout << "1. Play Music" << endl;
    cout << "2. Search Song" << endl;
    cout << "3. View Playlist" << endl;
    cout << "4. Exit" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Playing music..." << endl;
            break;

        case 2:
            cout << "Searching for a song..." << endl;
            break;

        case 3:
            cout << "Opening playlist..." << endl;
            break;

        case 4:
            cout << "Exiting YouTube Music..." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
    }
}