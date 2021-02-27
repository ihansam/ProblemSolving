#include <vector>
#include <map>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    map<int, vector<int>> graph;
    for(int i=0; i<n; ++i)
        graph[i] = {};
    for(auto vertex : edge){
        graph[vertex[0]].push_back(vertex[1]);
        graph[vertex[1]].push_back(vertex[0]);
    }
    vector<bool> visit (n+1, 0);
    queue<int> bfs;
    queue<int> depth;
    visit[1] = 1;
    bfs.push(1);
    int dep = 0;
    depth.push(1);
    while(!bfs.empty()){
        int currnum = bfs.front();
        bfs.pop();
        int currdep = depth.front();
        depth.pop();
        if(dep < currdep){
            dep = currdep;
            answer = 0;
        }
        ++answer;
        for(auto candidate: graph[currnum]){
            if(!visit[candidate]){
                visit[candidate] = 1;
                bfs.push(candidate);
                depth.push(currdep+1);
            }
        }
    }
    return answer;
}