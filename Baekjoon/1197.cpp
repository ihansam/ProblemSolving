#include <vector>
#include <iostream>
#include <algorithm>
#define IO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int V, E, A, B, C, ans=0, cnt=1, a, b;
vector<vector<int>> edge(100000, vector<int>());
vector<int> map(10001);

void get_input(){
	cin >> V >> E;
	for(int i=0; i<E; ++i){
		cin >> A >> B >> C;
		edge[i] = {C, A, B};
	}
	sort(edge.begin(), edge.begin()+E);
	for(int i=1; i<=V; ++i)
		map[i] = i;
}

int top(int node){
	if(map[node]==node) return node;
	else return map[node] = top(map[node]);
}

void solve(){
	for(int i=0; cnt<V; ++i){
		C = edge[i][0]; A = edge[i][1]; B = edge[i][2];
		a = top(A); b = top(B);
		if(top(A) != top(B)){
			ans += C;
			map[a] = b;
			++cnt;
		}
	}
	cout << ans;
}

int main(void){
	IO;
	get_input();
	solve();
	return 0;
}
