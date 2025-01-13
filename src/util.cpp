#include "util.hpp"
#include <vector>
#include <string>


using Prog = std::vector<std::vector<Exercise>>;

void program_generator()
{
    Prog starting_strength = {
        {Exercise::Squat, Exercise::Bench, Exercise::Accessories, Exercise::Deadlift, Exercise::Press, Exercise::Accessories},
        {Exercise::Squat, Exercise::Bench, Exercise::Accessories, Exercise::Deadlift, Exercise::Press, Exercise::Accessories},
        {Exercise::Squat, Exercise::Bench, Exercise::Accessories, Exercise::Deadlift, Exercise::Press, Exercise::Accessories},
        {Exercise::Squat, Exercise::Bench, Exercise::Accessories, Exercise::Deadlift, Exercise::Press, Exercise::Accessories}
    };

    // sets/reps table:
    // 1 2 3 4 5
    // 1 2 3 4 5
    // 1 2 3 4 5
    // 1 2 3 4 5
    // 1 2 3 4 5     4x5 -> 3,4 
    //               i.e. index_1D = i * columns + j  --> 3 * 5 + 4 -> 19

//     Sets \ Reps   1   2   3   4   5
//       -------------------------
//       1 |  1   2   3   4   5
//       2 |  2   4   6   8  10
//       3 |  3   6   9  12  15
//       4 |  4   8  12  16  20
//       5 |  5  10  15  20  25

// Sets \ Reps   0   1   2   3   4
//       -------------------------
//       0 | (1,1) (1,2) (1,3) (1,4) (1,5)
//       1 | (2,1) (2,2) (2,3) (2,4) (2,5)
//       2 | (3,1) (3,2) (3,3) (3,4) (3,5)
//       3 | (4,1) (4,2) (4,3) (4,4) (4,5)
//       4 | (5,1) (5,2) (5,3) (5,4) (5,5) 
}