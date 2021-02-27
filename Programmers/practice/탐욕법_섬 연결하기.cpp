#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b){
    return a[2] < b[2];
}

int ancestor(int i, vector<int>& group){
    if(group[i]==i)
        return i;
    else
        return ancestor(group[i], group);
}

int solution(int n, vector<vector<int>> costs) {
    vector<int> group(n);
    for(int i=0; i<n; ++i)
        group[i] = i;
    sort(costs.begin(), costs.end(), cmp);
    int answer = 0;
    for(auto bridge: costs){
        int island1 = bridge[0];
        int island2 = bridge[1];
        int anc1 = ancestor(island1, group);
        int anc2 = ancestor(island2, group);
        if(anc1 != anc2){
            group[anc2] = anc1;
            answer += bridge[2];
        }        
    }
    return answer;
}