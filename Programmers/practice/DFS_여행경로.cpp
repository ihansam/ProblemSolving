#include <vector>
#include <algorithm>
using namespace std;

vector<string> answer;
bool done = false;

void DFS(string curr, vector<string> path, vector<bool> used,
         vector<vector<string>>& tickets){
    if (path.size() == tickets.size()+1){
        answer = path;
        done = true;
    }
    if(!done){
        for(int i=0; i<tickets.size(); ++i){
            if((tickets[i][0] == curr) && !used[i]){
                vector<bool> newused = used;
                newused[i] = 1;
                vector<string> newpath = path;
                newpath.push_back(tickets[i][1]);
                DFS(tickets[i][1], newpath, newused, tickets);
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    vector<string> path = {"ICN"};
    vector<bool> used (tickets.size(), 0);
    DFS("ICN", path, used, tickets);
    return answer;
}