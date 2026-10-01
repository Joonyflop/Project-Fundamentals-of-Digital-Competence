#include <iostream>
#include <string>
#include "recommendations.h"

using namespace std;


// Helper function to display discovery suggestions
static GenreResult showDiscovery( //using the shared main .cpp file to display the discovery suggestions
    const string& category,
    const string& vibe,
    const string tracks[],
    int count
) {

    GenreResult result;

    // Store recommendation information
    result.genre = category;
    result.mix = vibe;

    cout << "\n------------------------------------\n";
    cout << "  RECOMMENDATION: " << category << "\n";
    cout << "  Vibe: " << vibe << "\n";
    cout << "------------------------------------\n";

    for (int i = 0; i < count; i++) {

        cout << "  - " << tracks[i] << "\n";

        // Store each recommendation
        result.songs.push_back(tracks[i]);
    }

    cout << "------------------------------------\n";

    return result;
}


// Member 4 - Music Discovery / Preference Module   //all the song lists are below and stored first in the file
GenreResult discoveryRecommendation() {             // cuz it looks more organised this way

    // ----------------------------------------------------
    // Datasets: Familiar Classics
    // ----------------------------------------------------

    const string familiarJpop[] = {
        "Song: 'First Love' by Hikaru Utada",
        "Song: 'Lemon' by Kenshi Yonezu",
        "Song: 'Pretender' by Official HIGE DANdism",
        "Song: 'Lost Umbrella' by Inabakumori",
        "Song: 'Silhouette' by KANA-BOON",
        "Playlist: Legendary J-Pop Hits"
    };

    const string familiarKpop[] = {
        "Song: 'Merry Go Round' by BTS",
        "Song: 'Whistle' by BLACKPINK",
        "Song: 'That That' by PSY",
        "Song: 'Strategy' by TWICE",
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
        "Song: 'Bloody Paradise' by ENHYPEN",
        "Song: 'Lemonade' by aespa",
        "Song: 'It's Me' by ILLIT",
        "Song: 'SPOT!' by ZICO ft. JENNIE",
        "Song: 'Bad' by ATEEZ",
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


    cout << "\n+====================================+\n";
    cout << "          MADE FOR YOU               \n";
    cout << "       MUSIC DISCOVERY MENU         \n";
    cout << "+====================================+\n";

    cout << "What are you in the mood for?\n";

    cout << "1. Listen to Familiar Music\n";
    cout << "2. Discover New Music For You\n";
    cout << "3. Back to Main Menu\n";

    mainChoice = getValidChoice(
        "Enter your choice (1-3): ",
        1,
        3
    );


    // ----------------------------------------------------
    // OPTION 1: FAMILIAR MUSIC
    // ----------------------------------------------------

    if (mainChoice == 1) {

        cout << "\n--- FAMILIAR MUSIC CATEGORIES ---\n";

        cout << "1. J-Pop Classics\n";
        cout << "2. K-Pop Essentials\n";
        cout << "3. C-Pop & Mandopop Hall of Fame\n";
        cout << "4. 90s Jams & Throwbacks\n";
        cout << "5. Classic Indie Anthems\n";
        cout << "6. Timeless Jazz & Blues\n";

        int subChoice = getValidChoice(  //get the user input for the subchoice
            "Enter category (1-6): ",       //the songs we edi put on top so they just display the list when called
            1,
            6
        );


        switch (subChoice) {

            case 1:

                return showDiscovery(
                    "Familiar J-Pop",
                    "Nostalgic, widely-loved Japanese hits",
                    familiarJpop,
                    6
                );


            case 2:

                return showDiscovery(
                    "Familiar K-Pop",
                    "Global Korean pop anthems everyone knows",
                    familiarKpop,
                    6
                );


            case 3:

                return showDiscovery(
                    "Familiar C-Pop",
                    "Timeless Mandopop ballads and classics",
                    familiarCpop,
                    6
                );


            case 4:

                return showDiscovery(
                    "90s Classics",
                    "Nostalgic rock, pop throwbacks & iconic R&B",
                    classic90s,
                    6
                );


            case 5:

                return showDiscovery(
                    "Classic Indie",
                    "Famous alternative and indie rock anthems",
                    classicIndie,
                    6
                );


            case 6:

                return showDiscovery(
                    "Timeless Jazz & Blues",
                    "Smooth sax, smoky brass & soulful electric guitar",
                    classicJazzBlues,
                    6
                );
        }
    }


    // ----------------------------------------------------
    // OPTION 2: DISCOVER NEW MUSIC
    // ----------------------------------------------------

    else if (mainChoice == 2) {  //same w here too. 

        cout << "\n--- DISCOVER NEW MUSIC ---\n";

        cout << "1. New J-Pop Releases\n";
        cout << "2. New K-Pop Chart-Toppers\n";
        cout << "3. Fresh C-Pop & Mandopop Tracks\n";
        cout << "4. Alt Hip-Hop & R&B\n";
        cout << "5. Modern Indie Discoveries\n";
        cout << "6. Contemporary Jazz & Blues Revival\n";

        int subChoice = getValidChoice(
            "Enter category (1-6): ",
            1,
            6
        );


        switch (subChoice) {

            case 1:

                return showDiscovery(
                    "New J-Pop",
                    "Viral Japanese tracks and recent anime hits",
                    newJpop,
                    6
                );


            case 2:

                return showDiscovery(
                    "New K-Pop",
                    "Latest releases and trending Korean tracks",
                    newKpop,
                    6
                );


            case 3:

                return showDiscovery(
                    "New C-Pop",
                    "Modern Mandopop releases and acoustic sounds",
                    newCpop,
                    6
                );


            case 4:

                return showDiscovery(
                    "Alt Hip-Hop & R&B",
                    "Atmospheric, neo-soul & experimental groove",
                    altHiphopRnb,
                    6
                );


            case 5:

                return showDiscovery(
                    "Modern Indie",
                    "Upbeat guitar riffs, synth riffs & fresh hooks",
                    newIndieBands,
                    6
                );


            case 6:

                return showDiscovery(
                    "Jazz & Blues Revival",
                    "Fresh vocal jazz and modern blues arrangements",
                    newJazzBlues,
                    6
                );
        }
    }


    // ----------------------------------------------------
    // OPTION 3: BACK TO MAIN MENU
    // ----------------------------------------------------

    else if (mainChoice == 3) { //exit menu option

        cout << "\nReturning to main menu...\n";

        // Empty result means nothing should be saved
        return {"", "", {}};
    }


    // Safety return
    return {"", "", {}};
}