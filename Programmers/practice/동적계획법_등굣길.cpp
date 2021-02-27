#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> map (n, vector<int>(m, 0));
    for(auto pd: puddles)               // mark puddle location
        map[pd[1]-1][pd[0]-1] = -1;
    for(int i=0; i<n; ++i){             // fill 1 till met puddle
        if(!map[i][0])
            map[i][0] = 1;
        else
            break;
    }
    for(int j=1; j<m; ++j){
        if(!map[0][j])
            map[0][j] = 1;
        else
            break;
    }
    for(int i=1; i<n; ++i){
        int left = map[i][0];
        for(int j=1; j<m; ++j){
            if(map[i][j])           // puddle check
                left = -1;
            else{
                int up = map[i-1][j];
                if(left == -1){
                    if(up != -1)
                        left = up;
                    else
                        left = -1;
                }
                else{
                    if(up != -1)
                        left = (left+up)%1000000007;
                }
            }
            map[i][j] = left;
        }
    }
    return map[n-1][m-1];
}