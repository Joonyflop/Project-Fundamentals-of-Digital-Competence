#include <iostream>   // lets us use cout (print to screen)
#include <string>     // lets us use the string type (text)
#include "recommendations.h"   // our shared header (has getValidChoice and the function names)

using namespace std;   // so we can write cout/string instead of std::cout/std::string

// CHOOSE TIME OF DAY

string chooseTimeOfDay() {   // asks the user for a time of day and gives back its name as text

    cout << "\n+====================================+\n";   // top border of the box
    cout << "           TIME OF DAY\n";                      // title of this screen
    cout << "+====================================+\n";     // bottom border of the box

    cout << "\nWhen will you listen?\n\n";   // ask the question

    cout << "1. Morning\n";     // option 1
    cout << "2. Afternoon\n";   // option 2
    cout << "3. Evening\n";     // option 3
    cout << "4. Night\n";       // option 4

    int timeChoice = getValidChoice(   // ask for a number and store it in timeChoice
        "\nEnter your choice: ",       // the message shown to the user
        1,                             // smallest number allowed
        4                              // biggest number allowed
    );   // getValidChoice keeps asking until the number is between 1 and 4

    switch (timeChoice) {   // check which number the user picked
        case 1:                 // if they picked 1
            return "Morning";   // give back the word Morning
        case 2:                 // if they picked 2
            return "Afternoon"; // give back the word Afternoon
        case 3:                 // if they picked 3
            return "Evening";   // give back the word Evening
        case 4:                 // if they picked 4
            return "Night";     // give back the word Night
    }   // end of the switch

    return "Morning";   // backup answer so the function always returns something
}   // end of chooseTimeOfDay


// TIP FOR EACH TIME OF DAY

string getTimeTip(const string& timeOfDay) {   // takes a time of day and gives back a short tip

    if (timeOfDay == "Morning") {                   // if the time is Morning
        return "A fresh start to your day!";        // give the morning tip
    }
    else if (timeOfDay == "Afternoon") {            // otherwise, if it is Afternoon
        return "Perfect to keep your energy going.";// give the afternoon tip
    }
    else if (timeOfDay == "Evening") {              // otherwise, if it is Evening
        return "A nice way to wrap up the day.";    // give the evening tip
    }

    return "Best with the volume turned down low."; // anything else (Night) gets this tip
}   // end of getTimeTip


// SHOW ACTIVITY SUGGESTIONS

string showSuggestions(          // prints the recommendations and also returns them as text
    const string& title,         // the activity name, e.g. "Studying"
    const string& vibe,          // a short description of the mood
    const string& timeOfDay,     // the time of day the user chose
    const string suggestions[],  // the list of songs/playlists to show
    int count                    // how many items are in that list
) {
    string result;                       // will store a text copy of everything we print
    string tip = getTimeTip(timeOfDay);  // get the tip that matches the time of day

    cout << "\n+====================================+\n";   // top border of the box
    cout << "       ACTIVITY RECOMMENDATION\n";               // title of this screen
    cout << "+====================================+\n";       // bottom border of the box

    cout << "\nSuggestions for " << title << ":\n";   // print which activity this is for
    cout << "Time of day: " << timeOfDay << "\n";     // print the chosen time of day
    cout << "Vibe: " << vibe << "\n";                 // print the vibe description
    cout << "Tip: " << tip << "\n";                   // print the tip

    result =                          // start building the text copy
        "Activity Recommendation"     // heading line
        "\n   Activity: " + title +   // add the activity name
        "\n   Time of day: " + timeOfDay +   // add the time of day
        "\n   Vibe: " + vibe +        // add the vibe
        "\n   Tip: " + tip +          // add the tip
        "\n   Suggestions:";          // add the label for the list that comes next


    for (int i = 0; i < count; i++) {   // go through the list one item at a time

        cout << "- " << suggestions[i] << "\n";   // print the current song/playlist on screen

        result +=                       // add the same item to the text copy
            "\n   - " + suggestions[i]; // on a new line with a dash
    }   // end of the loop

    cout << "\n+====================================+\n";   // bottom border of the results

    return result;   // hand the text copy back to whoever called this function
}   // end of showSuggestions


// ACTIVITY RECOMMENDATION

string activityRecommendation() {   // the main function of the Activity module

    // Studying
    const string studying[] = {   // list of studying songs (can't be changed while running)

        "Playlist: Baroque Focus",   // a playlist

        "Song: 'Air on the G String' by Johann Sebastian Bach",   // a Bach song

        "Song: 'Winter (Four Seasons)' by Antonio Vivaldi",   // a Vivaldi song

        "Song: 'Canon in D' by Johann Pachelbel"   // a Pachelbel song
    };   // end of the studying list


    // Workout
    const string workout[] = {   // list of workout songs

        "Song: 'The One That Got Away' by Katy Perry",   // a Katy Perry song

        "Song: 'I Knew You Were Trouble' by Taylor Swift (Red)",   // a Taylor Swift song

        "Song: '22' by Taylor Swift (Red)",   // another Taylor Swift song

        "Song: 'We Are Never Ever Getting Back Together' by Taylor Swift (Red)",   // another Taylor Swift song

        "Playlist: Taylor Swift - Red (Taylor's Version)"   // the whole Red album as a playlist
    };   // end of the workout list


    // Driving
    const string driving[] = {   // list of driving songs

        "Song: 'Espresso' by Sabrina Carpenter",   // a Sabrina song

        "Song: 'Please Please Please' by Sabrina Carpenter",   // another Sabrina song

        "Song: 'Break Free' by Ariana Grande",   // an Ariana song

        "Song: 'yes, and?' by Ariana Grande",   // another Ariana song

        "Playlist: Happy Pop Road Trip"   // a happy pop playlist
    };   // end of the driving list


    // Relaxing
    const string relaxing[] = {   // list of relaxing songs

        "Song: 'Young and Beautiful' by Lana Del Rey",   // a Lana song

        "Song: 'Video Games' by Lana Del Rey",   // another Lana song

        "Song: 'Summertime Sadness' by Lana Del Rey",   // another Lana song

        "Playlist: Soft Lana Del Rey Vibes"   // a soft Lana playlist
    };   // end of the relaxing list


    // Crashout
    const string crashout[] = {   // list of crashout songs

        "Song: 'good 4 u' by Olivia Rodrigo",   // an Olivia song

        "Song: 'vampire' by Olivia Rodrigo",   // another Olivia song

        "Song: 'get him back!' by Olivia Rodrigo",   // another Olivia song

        "Playlist: Olivia Rodrigo Crashout Mix"   // an Olivia crashout playlist
    };   // end of the crashout list


    cout << "\n+====================================+\n";   // top border of the menu box
    cout << "|       ACTIVITY RECOMMENDATION      |\n";       // title of the menu
    cout << "+====================================+\n";       // bottom border of the menu box

    cout << "\nChoose an activity:\n\n";   // ask the user to pick

    cout << "1. Studying\n";          // option 1
    cout << "2. Workout\n";           // option 2
    cout << "3. Driving\n";           // option 3
    cout << "4. Relaxing\n";          // option 4
    cout << "5. Crashout\n";          // option 5
    cout << "6. Back to Main Menu\n"; // option 6, goes back


    int activity = getValidChoice(   // ask for a number and store it in activity
        "\nEnter your choice: ",     // the message shown to the user
        1,                           // smallest number allowed
        6                            // biggest number allowed
    );   // getValidChoice keeps asking until the number is between 1 and 6


    // Back to main menu: no need to ask for the time of day
    if (activity == 6) {   // if the user chose "Back to Main Menu"

        cout << "\nReturning to main menu...\n";   // tell the user what is happening

        return "";   // give back empty text (nothing to show) and leave the function
    }


    // Ask for the time of day after an activity is chosen
    string timeOfDay = chooseTimeOfDay();   // show the time menu and store the answer


    switch (activity) {   // check which activity the user picked

        case 1:   // the user picked Studying

            return showSuggestions(   // show the studying results and return their text
                "Studying",                     // activity name
                "Calm and focused (Baroque)",   // vibe description
                timeOfDay,                      // the chosen time of day
                studying,                       // the studying song list
                4                               // the studying list has 4 items
            );


        case 2:   // the user picked Workout

            return showSuggestions(   // show the workout results and return their text
                "Workout",                          // activity name
                "Emotional but energetic (Red era)",// vibe description
                timeOfDay,                          // the chosen time of day
                workout,                            // the workout song list
                5                                   // the workout list has 5 items
            );


        case 3:   // the user picked Driving

            return showSuggestions(   // show the driving results and return their text
                "Driving",                           // activity name
                "Happy songs you never want to end", // vibe description
                timeOfDay,                           // the chosen time of day
                driving,                             // the driving song list
                5                                    // the driving list has 5 items
            );


        case 4:   // the user picked Relaxing

            return showSuggestions(   // show the relaxing results and return their text
                "Relaxing",                // activity name
                "Soft, dreamy, and slow",  // vibe description
                timeOfDay,                 // the chosen time of day
                relaxing,                  // the relaxing song list
                4                          // the relaxing list has 4 items
            );


        case 5:   // the user picked Crashout

            return showSuggestions(   // show the crashout results and return their text
                "Crashout",                           // activity name
                "Loud, dramatic, and fully unhinged", // vibe description
                timeOfDay,                            // the chosen time of day
                crashout,                             // the crashout song list
                4                                     // the crashout list has 4 items
            );
    }   // end of the switch


    return "";   // backup so the function always returns something
}   // end of activityRecommendation