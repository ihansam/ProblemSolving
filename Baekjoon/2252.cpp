#include <queue>
#include <vector>
#include <iostream>
#define IO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int M, N, a, b;
int ahead[32001] = {0};
vector<vector<int>> graph(32001, vector<int>());

void get_input(){
	cin >> N >> M;
	while(M--){
		cin >> a >> b;
		graph[a].push_back(b);
		++ahead[b];
	}
}

void solve(){
	queue<int> q;
	int top;
	for(int i=1; i<=N; ++i)
		if(!ahead[i]) q.push(i);
	while(!q.empty()){
		top = q.front();
		q.pop();
		cout << top << ' ';
		for(auto next: graph[top])
			if(!(--ahead[next])) q.push(next);
	}
}

int main(void){
	IO;
	get_input();
	solve();
	return 0;
}
