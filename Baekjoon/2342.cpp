#include <cstring>
#include <iostream>
#define INF 400000
using namespace std;

int n, cnt=0, ret;
int cmd[100001];
int cost[5][5] = {{INF, 2, 2, 2, 2},
				  {INF, 1, 3, 4, 3},
				  {INF, 3, 1, 3, 4},
				  {INF, 4, 3, 1, 3},
				  {INF, 3, 4, 3, 1}};
int dp[100001][5][5];

void get_input(){
	memset(dp, 0, sizeof(dp));
	while(cin >> n){
		if(n) cmd[++cnt] = n;
		else break;
	}
}

int dfs(int step, int l, int r){
	if(step > cnt) return 0;

	if(l && l==r) return INF;

	ret = dp[step][l][r];
	if(ret) return ret;
	
	ret = min(
		dfs(step+1,cmd[step],r)+cost[l][cmd[step]],
		dfs(step+1,l,cmd[step])+cost[r][cmd[step]]
	);
	dp[step][l][r] = ret;
	return ret;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	get_input();
	cout << dfs(1, 0, 0);
	return 0;
}
