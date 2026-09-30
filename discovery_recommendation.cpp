#include <iostream>
#include <string>
#include "recommendations.h"

using namespace std;

// Helper function to display discovery suggestions cleanly
static void showDiscovery(const string& category, const string& vibe,
                          const string tracks[], int count) {
    cout << "\n------------------------------------\n";
    cout << "  DISCOVERY: " << category << "\n";
    cout << "  Vibe: " << vibe << "\n";
    cout << "------------------------------------\n";
    for (int i = 0; i < count; i++) {
        cout << "  - " << tracks[i] << "\n";
    }
    cout << "------------------------------------\n";
}

// Member 4 - Music Discovery / Preference Module
void discoveryRecommendation() {
    // 1. J-Pop
    const string jpop[] = {
        "Song: 'Idol' by YOASOBI",
        "Song: 'Night Dancer' by imase",
        "Song: 'Kick Back' by Kenshi Yonezu",
        "Song: 'Bling-Bang-Bang-Born' by Creepy Nuts",
        "Song: 'Lilac' by Mrs. GREEN APPLE",
        "Playlist: J-Pop Hits & Viral Discoveries"
    };

    // 2. C-Pop & Mandopop
    const string cpop[] = {
        "Song: 'Unbreakable Love' by Eric Chou",
        "Song: 'Red Scarf' by WeiBird",
        "Song: 'Love Confession' by Jay Chou",
        "Song: 'A Little Happiness' by Hebe Tien",
        "Song: 'The Lonely Brave' by Eason Chan",
        "Playlist: Mandopop Hits & Acoustic Melodies"
    };

    // 3. K-Pop
    const string kpop[] = {
        "Song: 'APT.' by ROSÉ & Bruno Mars",
        "Song: 'Supernova' by aespa",
        "Song: 'Magnetic' by ILLIT",
        "Song: 'SPOT!' by ZICO ft. JENNIE",
        "Song: 'How Sweet' by NewJeans",
        "Playlist: K-Pop Essentials & Chart Toppers"
    };

    // 4. 90s Jams & Classics
    const string classic90s[] = {
        "Song: 'Smells Like Teen Spirit' by Nirvana",
        "Song: 'Wonderwall' by Oasis",
        "Song: 'No Scrubs' by TLC",
        "Song: 'Say My Name' by Destiny's Child",
        "Song: 'I Want It That Way' by Backstreet Boys",
        "Playlist: 90s Throwbacks & Pop Classics"
    };

    // 5. Alternative Hip-Hop & R&B
    const string altHiphopRnb[] = {
        "Song: 'Redbone' by Childish Gambino",
        "Song: 'PRIDE.' by Kendrick Lamar",
        "Song: 'Lost' by Frank Ocean",
        "Song: 'Kill Bill' by SZA",
        "Song: 'BEST INTEREST' by Tyler, The Creator",
        "Playlist: Alt R&B & Experimental Hip-Hop"
    };

    // 6. Indie Bands
    const string indieBands[] = {
        "Song: 'Heat Waves' by Glass Animals",
        "Song: 'Electric Feel' by MGMT",
        "Song: 'Tongue Tied' by GROUPLOVE",
        "Song: 'A-Punk' by Vampire Weekend",
        "Song: 'Do I Wanna Know?' by Arctic Monkeys",
        "Playlist: Essential Indie Band Anthems"
    };

    // 7. Jazz & Blues
    const string jazzBlues[] = {
        "Song: 'Take Five' by Dave Brubeck Quartet",
        "Song: 'So What' by Miles Davis",
        "Song: 'What a Wonderful World' by Louis Armstrong",
        "Song: 'At Last' by Etta James",
        "Song: 'The Thrill Is Gone' by B.B. King",
        "Playlist: Timeless Jazz & Blues Essentials"
    };

    int choice;

    do {
        cout << "\n====================================\n";
        cout << "          YOUTUBE MUSIC             \n";
        cout << "       MUSIC DISCOVERY MENU         \n";
        cout << "====================================\n";
        cout << "1. J-Pop Discoveries\n";
        cout << "2. C-Pop & Mandopop\n";
        cout << "3. K-Pop Essentials\n";
        cout << "4. 90s Jams & Classics\n";
        cout << "5. Alt Hip-Hop & R&B\n";
        cout << "6. Indie Bands\n";
        cout << "7. Jazz & Blues\n";
        cout << "8. Back to Main Menu\n";

        choice = getValidChoice("Enter your choice (1-8): ", 1, 8);

        switch (choice) {
            case 1:
                showDiscovery("J-Pop Discoveries", "High-energy anime anthems & synth-pop hits", jpop, 6);
                break;
            case 2:
                showDiscovery("C-Pop & Mandopop", "Heartfelt ballads & emotional pop melodies", cpop, 6);
                break;
            case 3:
                showDiscovery("K-Pop Essentials", "Catchy hooks, vibrant beats & global chart-toppers", kpop, 6);
                break;
            case 4:
                showDiscovery("90s Jams & Classics", "Nostalgic rock, pop throwbacks & iconic R&B", classic90s, 6);
                break;
            case 5:
                showDiscovery("Alt Hip-Hop & R&B", "Atmospheric, neo-soul & experimental groove", altHiphopRnb, 6);
                break;
            case 6:
                showDiscovery("Indie Bands", "Upbeat guitar riffs, synth riffs & catchy hooks", indieBands, 6);
                break;
            case 7:
                showDiscovery("Jazz & Blues", "Smooth sax, smoky brass & soulful electric guitar", jazzBlues, 6);
                break;
            case 8:
                cout << "\nReturning to main menu...\n";
                break;
        }
    } while (choice != 8);
}