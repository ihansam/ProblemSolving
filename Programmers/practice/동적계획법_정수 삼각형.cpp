#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int height = triangle.size();
    for(int step = 1; step < height; ++step){
        triangle[step][0] += triangle[step-1][0];
        triangle[step][step] += triangle[step-1][step-1];
        for(int i = 1; i < step; ++i){
            triangle[step][i] += max(triangle[step-1][i-1], triangle[step-1][i]);
        }
    }
    return *max_element(triangle[height-1].begin(), triangle[height-1].end());
}