#ifndef UTIL_HPP
#define UTIL_HPP

typedef enum
{
    StartingStrength,
    StrongLifts5x5,
    FiveThreeOne,
    Candito
} TrainingProgram;

typedef enum
{
    Squat,
    Bench,
    Deadlift
} Exercise;

void exerciseNameStr(const Exercise ex, std::string& name)
{
    switch (ex)
    {
        case Squat:
            name = "Squat";
            break;

        case Bench:
            name = "Bench";
            break;

        case Deadlift:
            name = "Deadlift";
            break;

        default:
            name = "Exercise_Not_Handled";
            break;
    }
}

#endif