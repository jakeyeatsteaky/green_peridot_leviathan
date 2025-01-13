#ifndef UTIL_HPP
#define UTIL_HPP
#include <string>
typedef enum
{
    StartingStrength,
    StrongLifts5x5,
    FiveThreeOne,
    Candito
} TrainingProgram;

typedef enum
{
    Accessories = -1,
    Squat,
    Bench,
    Deadlift,
    Press
} Exercise;

// void exerciseNameStr(const Exercise ex, std::string& name)
// {
//     switch (ex)
//     {
//         case Squat:
//             name = "Squat";
//             break;

//         case Bench:
//             name = "Bench";
//             break;

//         case Deadlift:
//             name = "Deadlift";
//             break;

//         default:
//             name = "Exercise_Not_Handled";
//             break;
//     }
// }

void program_generator();


#endif