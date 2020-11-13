#include <iostream>
#include <vector>
using namespace std;

enum mapidx{EMPTY=0, WALL, CAR, START, TARGET};
// EMPTY: can move, WALL: can't move, CAR: can remove
// Return the number of minumum removing car from START to TARGET
// if can't reach to TARGET, return -1

int main(){
    vector<vector<int> > tc1 = // return 0
    {{0, 0, 1, 0, 1},
     {0, 3, 1, 0, 1},
     {0, 0, 1, 0, 1},
     {1, 0, 1 ,0, 4},
     {1, 0, 0, 0, 0}};
    vector<vector<int> > tc2 = // return -1
    {{3, 1, 0, 0, 0},
     {0, 1, 1, 0, 0},
     {0, 1, 1, 1, 0},
     {0, 0, 1, 1, 0},
     {0, 0, 0, 1, 4}};
    vector<vector<int> > tc3 = // return 2
    {{3, 2, 2, 0, 0},
     {0, 2, 2, 0, 0},
     {0, 2, 2, 2, 0},
     {0, 0, 2, 2, 0},
     {0, 0, 2, 2, 4}};   
    return 0;
}

