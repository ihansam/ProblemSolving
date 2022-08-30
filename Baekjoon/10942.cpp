#include <vector>
#include <string>
#include <iostream>
#define IO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, M, s, e;
int arr[2001];
string str(2001, 'X');
vector<string> dp(2001);

void get_input(){
	cin >> N;
	string str(N+1, 'X');
	for(int i=1; i<=N; ++i){
		cin >> arr[i];
		dp[i] = str;
	}
}

char get_is_pellin(int s, int e){
	if(s>=e) return '1';
	if(dp[s][e] != 'X') return dp[s][e];
	if(arr[s] == arr[e])
		return dp[s][e] = get_is_pellin(s+1, e-1);
	else
		return dp[s][e] = '0';
}

void solve(){
	cin >> M;
	for(int i=0; i<M; ++i){
		cin >> s >> e;
		cout << get_is_pellin(s, e) << '\n';
	}
}

int main(void){
	IO;
	get_input();
	solve();
	return 0;
}
