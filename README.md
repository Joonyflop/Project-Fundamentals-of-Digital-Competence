# YouTube Music Recommendation System

A beginner-friendly C++ console program for a university group project. It
provides a shared menu and an example Activity Recommendation module. The mood,
genre, and music discovery / preference modules are placeholders for the other
group members to complete.

## Project files

- `main.cpp` contains the main menu and shared input validation function.
- `recommendations.h` declares the functions shared by the program and modules.
- `activity_recommendation.cpp` contains the Activity Recommendation module.
- `mood_recommendation.cpp`, `genre_recommendation.cpp`, and
  `discovery_recommendation.cpp` contain placeholders for the other members.

All recommendations are static examples. The program does not connect to
YouTube Music or use an API.

## Compile and run

From this folder, compile all the `.cpp` files together with a C++ compiler:

```sh
g++ -std=c++11 main.cpp activity_recommendation.cpp mood_recommendation.cpp genre_recommendation.cpp discovery_recommendation.cpp -o recommendation_system
```

Then run the program:

```sh
./recommendation_system
```

On Windows, run `recommendation_system.exe` after compiling.

Try each main menu option, all four activity choices, the back/exit choices,
and invalid inputs such as a letter or a number outside the displayed range.

