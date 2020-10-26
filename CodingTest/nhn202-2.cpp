#include <iostream>
#include <vector>
using namespace std;

enum DIRECTION{LEFT=-1, RIGHT=1};

int findmaxidx(int from, int to, vector <int> &v){
    int start, end;
    start = min(from, to);
    end = max(from, to);
    int idx = 0;
    int m = 0;
    for(int i=start; i<=end; ++i){
        if(v[i] > m){
            idx = i;
            m = v[i];
        }
    }
    return idx;
}

bool isdecrese(int from, int to, enum DIRECTION dir, const vector<int> &v){
    bool res = true;
    int tmp = v[from];
    for(int i=from; i!=to+dir; i+=dir){
        if(v[i]>tmp) return false;
        else tmp = v[i];
    }
    return res;
}

void findsolution(int from, enum DIRECTION dir, vector<int> &v, vector<int> &sol){
    int to;
    if(dir == LEFT) to = 0;
    else to = v.size()-1;
    if(isdecrese(from, to, dir, v)) {   // from부터 to까지 계속 감소하면 더 확인할 필요 없음
        for(int i=from; i!=to+dir; i+=dir){
            sol[i] = v[i];
        }
        return;
    }
    int localmax = findmaxidx(from+dir, to, v);
    int maxheight = v[localmax];
    sol[from] = v[from];
    for(int i=from+dir; i!=localmax+dir; i+=dir){
        sol[i] = maxheight;
    }
    findsolution(localmax, dir, v, sol);
    
    return;
}
        

int main() {
    // input 처리
	int N_test;
    cin >> N_test;
    vector <int> testsize(N_test);
    for(int i=0; i<N_test; ++i){
        cin >> testsize[i];
    }
    vector<vector<int> > testcase;
    vector<vector<int> > answer;
    for(int i=0; i<N_test; ++i){
        vector <int> tc(testsize[i]);
        for(int j=0; j<testsize[i]; ++j){
            cin >> tc[j];
        }
        testcase.push_back(tc);
        vector <int> ans(testsize[i]);
        for(int j=0; j<testsize[i]; ++j){
            cin >> ans[j];
        }
        answer.push_back(ans);
    }
    for(int i=0; i<N_test; ++i){
        // 알고리즘
        vector <int> solution(testsize[i]);
        vector <int> test = testcase[i];
        
        int top = findmaxidx(0, test.size()-1, test);
        findsolution(top, LEFT, test, solution);
        findsolution(top, RIGHT, test, solution);
        
        // 테스트
        for(auto item: solution){
            cout << item << " " ;
        }
        cout << endl;
        if(solution != answer[i]) cout << "오답" << endl;
        else cout << "정답" << endl;
    }
	return 0;
}

/* TEST INPUT
5
6 6 10 10 10
6 2 11 0 3 5
6 6 11 5 5 5
12 9 11 14 5 10
12 12 12 14 10 10
6 12 0 2 8 4 0 7 3 6
6 12 8 8 8 7 7 7 6 6
12 13 11 8 10 15 7 7 19 14
12 13 13 13 13 15 15 15 19 14
18 16 13 23 19 20 22 15 19 17
18 18 18 23 22 22 22 19 19 17
*/
