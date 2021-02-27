#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b){
    if (a[0] == b[0]) return a[1] < b[1];
    else return a[0] < b[0];
}

struct cmpp {
    bool operator()(const vector<int>& a, const vector<int>& b){
        if (a[1] == b[1]) return a[0] > b[0];
        else return a[1] > b[1];        
    }
};

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end(), cmp);
    priority_queue <vector<int>, vector<vector<int> >, cmpp> workload;
    int answer = 0;
    int time = 0;
    int i = 0;
    while(i<jobs.size()||!workload.empty()){
        if(!workload.empty()){  // do a work!
            time += workload.top()[1];
            answer += (time - workload.top()[0]);
            workload.pop();
        }
        if(workload.empty() && i<jobs.size() && (time < jobs[i][0]))
            time = jobs[i][0];                          
        while(i<jobs.size() && (time >= jobs[i][0]))    
            workload.push(jobs[i++]);
    }
    return answer/jobs.size();
}
