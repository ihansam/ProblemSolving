#include <vector>
using namespace std;

int solution(vector<int> money) {
    int n = money.size();
    vector<int> dp1 = {0, money[1]};
    for(int i=2; i<n; ++i)
        dp1.push_back(max(dp1[i-2]+money[i], dp1[i-1]));
    vector<int> dp2 = {money[0], max(money[0], money[1])};
    for(int i=2; i<n-1; ++i)
        dp2.push_back(max(dp2[i-2]+money[i], dp2[i-1]));
    return max(dp1[n-1], dp2[n-2]);
}
