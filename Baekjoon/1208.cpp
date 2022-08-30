#include <map>
#include <iostream>
#define IO cin.tie(0)->sync_with_stdio(0)
using namespace std;

map<int, int> m;
int N, S, h;
long long ans = 0;
int a[40];

void dfs1(int d, int acc){
	if(d==h){
		++m[acc];
		return;
	}
	dfs1(d+1, acc);
	dfs1(d+1, acc+a[d]);
}

void dfs2(int d, int acc){
	if(d==N){
		ans += m[S-acc];
		return;
	}
	dfs2(d+1, acc);
	dfs2(d+1, acc+a[d]);
}

void get_input(){
	cin >> N >> S;
	for(int i=0; i<N; ++i) cin >> a[i];
}

void solve(){
	h = N/2;
	dfs1(0, 0);
	dfs2(h, 0);
	cout << ans - (!S);
}

int main(void){
	IO;
	get_input();
	solve();
	return 0;
}
