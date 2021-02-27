#include <vector>
#include <set>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<set<int>> win(n+1);
    vector<set<int>> lose(n+1);
    for(auto res: results){
        win[res[0]].insert(res[1]);
        lose[res[1]].insert(res[0]);
    }
    for(int i=1; i<=n; ++i){
        set<int>::iterator it1;
        set<int>::iterator it2;
        for(it1=win[i].begin(); it1!=win[i].end(); ++it1){
            for(it2=lose[i].begin(); it2!=lose[i].end(); ++it2){
                win[*it2].insert(*it1);
                lose[*it1].insert(*it2);
            }
        }
    }
    int answer = 0;
    for(int i=1; i<=n; ++i){
        if(win[i].size()+lose[i].size()==n-1)
            ++answer;
    }
    return answer;
}