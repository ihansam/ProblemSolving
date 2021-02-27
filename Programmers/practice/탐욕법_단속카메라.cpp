#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end());
    int answer = 0;
    int left = -30001, right = 30001;
    for(auto car: routes){
        if(car[0] > right){
            left = car[0];
            right = car[1];
            ++answer;
        }
        else{
            left = car[0];
            right = min(right, car[1]);
        }
    }
    return answer+1;
}