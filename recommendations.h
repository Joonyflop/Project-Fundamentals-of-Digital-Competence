#ifndef RECOMMENDATIONS_H
#define RECOMMENDATIONS_H

// Shared declarations used by the program and each recommendation module.
int getValidChoice(const char* prompt, int minimum, int maximum);

void moodRecommendation();
void genreRecommendation();
void activityRecommendation();
void discoveryRecommendation();

#endif