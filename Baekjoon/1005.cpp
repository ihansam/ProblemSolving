#include <bits/stdc++.h>
#define IO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int T, N, K, W, X, Y, curr;
int cost[1001]={0}, dp[1001]={0}, conn[1001]={0};
int map[1001][1001];
queue<int> q;

inline int max(int a, int b){return (a>b)? a:b;}

void get_input(){
	cin >> N >> K;
	for(int i=1; i<=N; ++i){
		cin >> cost[i];
		conn[i] = 0;
		dp[i] = -1;
		for(int j=1; j<=N; ++j) map[i][j] = 0;
	}
	for(int i=0; i<K; ++i){
		cin >> X >> Y;
		map[X][Y] = 1;
		++conn[Y];
	}
	cin >> W;
}

void solve(){
	for(int n=1; n<=N; ++n){
		if(!conn[n]){
			dp[n] = cost[n];
			q.push(n);
		}
	}
	while(!q.empty()){
		curr = q.front();
		q.pop();
		for(int next=1; next<=N; ++next){
			if(!map[curr][next]) continue;
			dp[next] = max(dp[next], dp[curr]+cost[next]);
			if(--conn[next]) continue;
			q.push(next);
		}
	}
	cout << dp[W] << '\n';
}

int main(void){
	IO;
	cin >> T;
	while(T--){
		get_input();
		solve();
	}
	return 0;
}
