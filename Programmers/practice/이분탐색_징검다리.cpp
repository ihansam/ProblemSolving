#include <algorithm>
#include <vector>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);
    int left = 0, right = distance, answer = 0;
    while(left<=right){
        int target = (left+right)/2;
        int cnt = 0, last = 0;
        for(auto rock: rocks){
            if((rock-last) < target)
                ++cnt;
            else
                last = rock;
        }
        if(cnt > n){
            right = target - 1;
        }
        else{
            left = target + 1;
            answer = target;
        }
    }
    return answer;
}