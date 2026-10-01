# YouTube Music Recommendation System

A beginner-friendly C++ console program for a university group project. It
provides a shared menu and static example recommendations. It does not connect
to YouTube Music or use an API.

## Project files

- `main.cpp` contains the main menu and shared input validation.
- `recommendations.h` declares the recommendation functions and shared result
  structure.
- `activity_recommendation.cpp` contains activity-based recommendations.
- `genre_recommendation.cpp` contains genre recommendation logic.
- `discovery_recommendation.cpp` contains music discovery / preference logic.
- `mood_recommendation.cpp` contains the mood recommendation menu and examples.

Recommendations selected through the save prompt are kept for the current run
and can be viewed from the Saved Recommendations menu. They are not stored
between program runs.

## Compile and run

Open a terminal in this folder and compile the five program source files
together. For g++ (including MinGW on Windows):

```sh
g++ -std=c++11 main.cpp activity_recommendation.cpp mood_recommendation.cpp genre_recommendation.cpp discovery_recommendation.cpp -o recommendation_system
```

On Windows, run:

```powershell
.\recommendation_system.exe
```

On macOS or Linux, run:

```sh
./recommendation_system
```

Try each main menu option, the activity choices, the back/exit choices, and
invalid inputs such as a letter or a number outside the displayed range.
