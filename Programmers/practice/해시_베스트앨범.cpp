#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    if (a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map <string, int> totalmap;
    unordered_map <string, vector<pair<int, int> > > idxmap;
    for(int i=0; i<genres.size(); ++i){
        totalmap[genres[i]] += plays[i];
        idxmap[genres[i]].push_back(pair<int, int> (i, plays[i]));
    }
    unordered_map <string, int>::iterator iter;
    map <int, string, greater<int> > totals;
    for(iter=totalmap.begin(); iter!=totalmap.end(); ++iter)
        totals[iter->second] = iter->first;
    map <int, string>::iterator itt;
    vector<int> answer;
    for(itt=totals.begin(); itt!=totals.end(); ++itt){
        string key = itt->second;
        vector<pair<int, int> > records = idxmap[key];
        sort(records.begin(), records.end(), cmp);
        answer.push_back(records[0].first);
        if(records.size()>1)
            answer.push_back(records[1].first);    
    }
    return answer;
}
