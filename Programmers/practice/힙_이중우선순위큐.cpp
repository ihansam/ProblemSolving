#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    multiset <int> dpq;
    for(auto op: operations){
        char instruction = op[0];
        int number = stoi(op.substr(2));
        if(instruction == 'I')
            dpq.insert(number);
        else{
            if(number == 1 && dpq.size() > 0)
                dpq.erase(--dpq.end());
            else if(number == -1 && dpq.size() > 0)
                dpq.erase(dpq.begin());
        }
    }
    if(dpq.size()>0)
        return {*(--dpq.end()), *dpq.begin()};
    return {0, 0};
}