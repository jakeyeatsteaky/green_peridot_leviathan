#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include <functional>

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

    ___________________________
    NEW IDEA

    What if it was just similar to programs.  Not exactly starting strength but similar with my own flourish
    would make generating using a lambda easier.


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

void lambda_test();

int main(int argc, char** argv)
{
    Program ss = generateProgram(TrainingProgram::StartingStrength);
    outputProgram(ss, "StartingStrength.txt");

    lambda_test();

    std::fstream file("output.ppm");
    if (!file) return -1;

    size_t ppmHEIGHT = 200;
    size_t ppmWIDTH = 200;
    int pixels[ppmWIDTH*ppmHEIGHT];

    file << "P3" << std::endl;
    std::string line = std::to_string(ppmHEIGHT) + " " + std::to_string(ppmWIDTH);
    file << line << std::endl;
    file << "255" << std::endl;
    for (int i = 0; i < ppmHEIGHT; i++) {
        line.clear();
        for (int j = 0; j < ppmWIDTH; j++) {
            int color = (i*j*2134) % 255;
            pixels[i*j + j] = color;
            line += (std::to_string(color) + " ");
        }
        file << line << std::endl;
    }
    file.close();

    FILE* f = nullptr;
    f = fopen("output2.ppm", "wb");
    if (f == nullptr) {
        fclose(f);
        return -1;
    }

    fprintf(f, "P6\n %zu %zu\n 255\n", ppmWIDTH, ppmHEIGHT);
    if (ferror(f)) {
        fclose(f);
        return -1;
    }

    for (size_t i = 0; i < ppmWIDTH*ppmHEIGHT; i++) {
        int pixel = pixels[i];
        char bytes[3] = {
            (pixel >> (8*0)) & 0xFF,
            (pixel >> (8*1)) & 0xFF,
            (pixel >> (8*2)) & 0xFF
        };

        fwrite(bytes, sizeof(bytes), 1, f);
    }


    return 0;
}

void lambda_test()
{
    // simple lambda
    std::function<void()> greet = []() {printf("Hello, World\n");};
    greet();

    // with parameters
    std::function<int (int,int)> multiply = [](int x, int y) -> int {return x * y; };
    int result = multiply(10,100);

    // with capture
    int cap = 100;
    std::function<void (int)> modify = [&cap](int mod) -> void { cap += mod; };
    modify(100);
    printf("%d\n", cap);

}
