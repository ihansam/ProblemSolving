#include <string>
#include <vector>
#include <queue>
using namespace std;

bool isdiff1(string s1, string s2){
    bool flag = false;
    for(int i=0; i<s1.size(); ++i){
        if(s1[i]-s2[i]){
            if(!flag)
                flag = true;
            else
                return false;
        }
    }
    return flag;
}

int solution(string begin, string target, vector<string> words) {
    queue<string> strq;
    queue<vector<bool>> pathq;
    strq.push(begin);
    vector<bool> emptypath (words.size(), 0);
    pathq.push(emptypath);
    while(!strq.empty()){
        string curr = strq.front();
        strq.pop();
        vector<bool> path = pathq.front();
        pathq.pop();
        for(int i=0; i<path.size(); ++i){
            if(!path[i] && isdiff1(words[i], curr)){
                vector<bool> newpath = path;
                newpath[i] = 1;
                if(words[i] == target){
                    int res = 0;
                    for(int j=0; j<newpath.size(); ++j){
                        if(newpath[j])
                            ++res;                        
                    }
                    return res;
                }
                else{
                    strq.push(words[i]);
                    pathq.push(newpath);
                }
            }
        }        
    }
    return 0;
}