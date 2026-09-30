#include <iostream>
#include <string>
#include "recommendations.h"

using namespace std;

// Helper function to display discovery suggestions
static void showDiscovery(const string& category, const string& vibe,
                          const string tracks[], int count) {
    cout << "\n------------------------------------\n";
    cout << "  RECOMMENDATION: " << category << "\n";
    cout << "  Vibe: " << vibe << "\n";
    cout << "------------------------------------\n";
    for (int i = 0; i < count; i++) {
        cout << "  - " << tracks[i] << "\n";
    }
    cout << "------------------------------------\n";
}

// Member 4 - Music Discovery / Preference Module
void discoveryRecommendation() {
    // ----------------------------------------------------
    // Datasets: Familiar Classics
    // ----------------------------------------------------
    const string familiarJpop[] = {
        "Song: 'First Love' by Hikaru Utada",
        "Song: 'Lemon' by Kenshi Yonezu",
        "Song: 'Pretender' by Official HIGE DANdism",
        "Song: 'Heavy Rotation' by AKB48",
        "Song: 'Silhouette' by KANA-BOON",
        "Playlist: Legendary J-Pop Hits"
    };

    const string familiarKpop[] = {
        "Song: 'Dynamite' by BTS",
        "Song: 'DDU-DU DDU-DU' by BLACKPINK",
        "Song: 'Gangnam Style' by PSY",
        "Song: 'Fancy' by TWICE",
        "Song: 'Love Scenario' by iKON",
        "Playlist: Iconic K-Pop Essentials"
    };

    const string familiarCpop[] = {
        "Song: 'Love Confession' by Jay Chou",
        "Song: 'Tong Hua' by Michael Wong",
        "Song: 'A Little Happiness' by Hebe Tien",
        "Song: 'Tian Mi Mi' by Teresa Teng",
        "Song: 'Red Scarf' by WeiBird",
        "Playlist: Timeless Mandopop Classics"
    };

    const string classic90s[] = {
        "Song: 'Smells Like Teen Spirit' by Nirvana",
        "Song: 'Wonderwall' by Oasis",
        "Song: 'No Scrubs' by TLC",
        "Song: 'Say My Name' by Destiny's Child",
        "Song: 'I Want It That Way' by Backstreet Boys",
        "Playlist: 90s Throwbacks & Pop Classics"
    };

    const string classicIndie[] = {
        "Song: 'Do I Wanna Know?' by Arctic Monkeys",
        "Song: 'Seven Nation Army' by The White Stripes",
        "Song: 'The Less I Know The Better' by Tame Impala",
        "Song: 'Mr. Brightside' by The Killers",
        "Song: 'Take Me Out' by Franz Ferdinand",
        "Playlist: Essential Classic Indie Anthems"
    };

    const string classicJazzBlues[] = {
        "Song: 'Take Five' by Dave Brubeck Quartet",
        "Song: 'So What' by Miles Davis",
        "Song: 'What a Wonderful World' by Louis Armstrong",
        "Song: 'At Last' by Etta James",
        "Song: 'The Thrill Is Gone' by B.B. King",
        "Playlist: Timeless Jazz & Blues Essentials"
    };

    // ----------------------------------------------------
    // Datasets: Discover New Music
    // ----------------------------------------------------
    const string newJpop[] = {
        "Song: 'Idol' by YOASOBI",
        "Song: 'Night Dancer' by imase",
        "Song: 'Bling-Bang-Bang-Born' by Creepy Nuts",
        "Song: 'Lilac' by Mrs. GREEN APPLE",
        "Song: 'Kick Back' by Kenshi Yonezu",
        "Playlist: Trending J-Pop Discoveries"
    };

    const string newKpop[] = {
        "Song: 'APT.' by ROSÉ & Bruno Mars",
        "Song: 'Supernova' by aespa",
        "Song: 'Magnetic' by ILLIT",
        "Song: 'SPOT!' by ZICO ft. JENNIE",
        "Song: 'How Sweet' by NewJeans",
        "Playlist: Fresh K-Pop Chart Toppers"
    };

    const string newCpop[] = {
        "Song: 'Unbreakable Love' by Eric Chou",
        "Song: 'Guest' by Zhang Yuan",
        "Song: 'Just Tell Me' by Tarcy Su",
        "Song: 'Say Goodbye to Myself' by Bii",
        "Song: 'The Lonely Brave' by Eason Chan",
        "Playlist: Modern C-Pop & Indie Melodies"
    };

    const string altHiphopRnb[] = {
        "Song: 'Redbone' by Childish Gambino",
        "Song: 'PRIDE.' by Kendrick Lamar",
        "Song: 'Lost' by Frank Ocean",
        "Song: 'Kill Bill' by SZA",
        "Song: 'BEST INTEREST' by Tyler, The Creator",
        "Playlist: Alt R&B & Experimental Hip-Hop"
    };

    const string newIndieBands[] = {
        "Song: 'Heat Waves' by Glass Animals",
        "Song: 'Electric Feel' by MGMT",
        "Song: 'Tongue Tied' by GROUPLOVE",
        "Song: 'A-Punk' by Vampire Weekend",
        "Song: 'Chaise Longue' by Wet Leg",
        "Playlist: Modern Indie Discoveries"
    };

    const string newJazzBlues[] = {
        "Song: 'On the Sunny Side of the Street' by Laufey",
        "Song: 'In the Waiting Line' by Stella Cole",
        "Song: 'Language' by Samara Joy",
        "Song: 'A Kiss Before I Go' by Melody Gardot",
        "Song: 'Black Acid Soul' by Lady Blackbird",
        "Playlist: Contemporary Jazz & Blues Revival"
    };

    int mainChoice;

    do {
        cout << "\n====================================\n";
        cout << "          YOUTUBE MUSIC             \n";
        cout << "       MUSIC DISCOVERY MENU         \n";
        cout << "====================================\n";
        cout << "What are you in the mood for?\n";
        cout << "1. Listen to Familiar Music\n";
        cout << "2. Discover New Music\n";
        cout << "3. Back to Main Menu\n";

        mainChoice = getValidChoice("Enter your choice (1-3): ", 1, 3);

        if (mainChoice == 1) {
            cout << "\n--- FAMILIAR MUSIC CATEGORIES ---\n";
            cout << "1. J-Pop Classics\n";
            cout << "2. K-Pop Essentials\n";
            cout << "3. C-Pop & Mandopop Hall of Fame\n";
            cout << "4. 90s Jams & Throwbacks\n";
            cout << "5. Classic Indie Anthems\n";
            cout << "6. Timeless Jazz & Blues\n";

            int subChoice = getValidChoice("Enter category (1-6): ", 1, 6);

            switch (subChoice) {
                case 1:
                    showDiscovery("Familiar J-Pop", "Nostalgic, widely-loved Japanese hits", familiarJpop, 6);
                    break;
                case 2:
                    showDiscovery("Familiar K-Pop", "Global Korean pop anthems everyone knows", familiarKpop, 6);
                    break;
                case 3:
                    showDiscovery("Familiar C-Pop", "Timeless Mandopop ballads and classics", familiarCpop, 6);
                    break;
                case 4:
                    showDiscovery("90s Classics", "Nostalgic rock, pop throwbacks & iconic R&B", classic90s, 6);
                    break;
                case 5:
                    showDiscovery("Classic Indie", "Famous alternative and indie rock anthems", classicIndie, 6);
                    break;
                case 6:
                    showDiscovery("Timeless Jazz & Blues", "Smooth sax, smoky brass & soulful electric guitar", classicJazzBlues, 6);
                    break;
            }
        } 
        else if (mainChoice == 2) {
            cout << "\n--- DISCOVER NEW MUSIC ---\n";
            cout << "1. New J-Pop Releases\n";
            cout << "2. New K-Pop Chart-Toppers\n";
            cout << "3. Fresh C-Pop & Mandopop Tracks\n";
            cout << "4. Alt Hip-Hop & R&B\n";
            cout << "5. Modern Indie Discoveries\n";
            cout << "6. Contemporary Jazz & Blues Revival\n";

            int subChoice = getValidChoice("Enter category (1-6): ", 1, 6);

            switch (subChoice) {
                case 1:
                    showDiscovery("New J-Pop", "Viral Japanese tracks and recent anime hits", newJpop, 6);
                    break;
                case 2:
                    showDiscovery("New K-Pop", "Latest releases and trending Korean tracks", newKpop, 6);
                    break;
                case 3:
                    showDiscovery("New C-Pop", "Modern Mandopop releases and acoustic sounds", newCpop, 6);
                    break;
                case 4:
                    showDiscovery("Alt Hip-Hop & R&B", "Atmospheric, neo-soul & experimental groove", altHiphopRnb, 6);
                    break;
                case 5:
                    showDiscovery("Modern Indie", "Upbeat guitar riffs, synth riffs & fresh hooks", newIndieBands, 6);
                    break;
                case 6:
                    showDiscovery("Jazz & Blues Revival", "Fresh vocal jazz and modern blues arrangements", newJazzBlues, 6);
                    break;
            }
        }
        else if (mainChoice == 3) {
            cout << "\nReturning to main menu...\n";
        }
    } while (mainChoice != 3);
}