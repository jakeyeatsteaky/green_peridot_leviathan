#include <stdio.h>
#include <fstream>
#include <vector>

#include "util.hpp"

#define DESCRIPTION 0 
#if DESCRIPTION
    Okay so here is the general gist for how I want to create this thing.
    My goal is to have this be more of a data oriented architecture
    rather than the object oriented way.

    Basically the big data structure will be a grid (2D array) which represents:
        Rows: Blocks (a block is the smallest granularity object in a program which repeats)
        Cols: Sessions (a session is an individual training session)
        Grid: the Program

    There will be a system of lookup tables which determine things like sets/reps, and percentages

    So for example, enum Program_StartingStrength: 43
    Encoded in the first 2 numbers are the number of weeks, and number of training sessions per day
    then the following digits are maybe indices in a LUT for other things? I dont really know how its going to work yet but this is kind of the geenral idea
#endif

struct Session
{
    size_t idx;
    std::vector<Exercise> exercises;
};

using Program = std::vector<std::vector<Session>>;

Program generateProgram(const TrainingProgram tp)
{
    Program ret {};

    return ret;
}

void outputProgram(const Program& program, const std::string& path)
{
    
}

int main(int argc, char** argv)
{
    Program ss = generateProgram(TrainingProgram::StartingStrength);
    outputProgram(ss, "StartingStrength.txt");
    return 0;
}