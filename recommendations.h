#ifndef RECOMMENDATIONS_H
#define RECOMMENDATIONS_H

#include <string>
#include <vector>

using namespace std;


// Stores genre recommendation result
struct GenreResult {

    string genre;
    string mix;
    vector<string> songs;
};


// Shared input validation
int getValidChoice(
    const char* prompt,
    int minimum,
    int maximum
);


// Genre recommendation logic
GenreResult getGenreResult(
    int soundChoice,
    int energyChoice,
    int styleChoice
);


// Recommendation modules
void moodRecommendation();

GenreResult genreRecommendation();

void activityRecommendation();

void discoveryRecommendation();


#endif