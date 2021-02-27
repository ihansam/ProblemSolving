#include <vector>
#include <set>
using namespace std;

vector<set<int>> numpool(8);

bool found(int n, int target, int N){
    set <int> made;
    int NN = N;
    for(int i=1; i<n; ++i){
        NN = 10*NN + N;
        set<int>::iterator initer;
        set<int>::iterator outiter;
        for(initer=numpool[i-1].begin(); initer!=numpool[i-1].end(); ++initer){
            for(outiter=numpool[n-i-1].begin(); outiter!=numpool[n-i-1].end(); ++outiter){
                made.insert(*initer+*outiter);
                made.insert(*initer-*outiter);
                made.insert((*initer)*(*outiter));
                if((*outiter)!=0)
                    made.insert((*initer)/(*outiter));
            }
        }
    }
    made.insert(NN);
    if(made.find(target) != made.end())
        return true;
    else{
        numpool[n-1] = made;
        return false;
    }
}

int solution(int N, int number) {
    int answer = 0;
    for(int n = 1; n <= 8; ++n){
        if(found(n, number, N))
            return n;
    }
    return -1;
}