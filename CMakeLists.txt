cmake_minimum_required(VERSION 3.30)
project(DSandACPP)

set(CMAKE_CXX_STANDARD 26)
include_directories(${PROJECT_SOURCE_DIR}/src/shared/)
add_executable(DSandACPP src/main.cpp
        src/ch5/exercises/exercise_classes/vector.h
        src/ch5/exercises/exercise_classes/unsorted_scoreboard.h
        src/ch5/exercises/exercise_classes/scoreboard.h
        src/ch5/exercises/exercise_classes/scoreboard.cpp
        src/ch5/exercises/exercise_classes/game_entry.cpp
        src/ch5/exercises/creativity/ch5_22.cpp


)
