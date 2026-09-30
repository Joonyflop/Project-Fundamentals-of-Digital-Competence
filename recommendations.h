#ifndef RECOMMENDATIONS_H
#define RECOMMENDATIONS_H

#include <string>
#include <vector>

using namespace std;

// Shared declarations used by the program and each recommendation module.
int getValidChoice(const char* prompt, int minimum, int maximum);

// Stores the result of a genre recommendation
struct GenreResult {
    string genre;
    string mix;
    vector<string> songs;
};

// Reusable genre recommendation logic for terminal and web interface
GenreResult getGenreResult(
    int soundChoice,
    int energyChoice,
    int styleChoice
);

void moodRecommendation();
void genreRecommendation();
void activityRecommendation();
void discoveryRecommendation();

#endif