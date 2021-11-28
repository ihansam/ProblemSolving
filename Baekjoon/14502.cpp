#include <iostream>
#include <vector>
using namespace std;

int safe=0, N, M;
vector<vector<int>> lab (10, vector<int>(10, 1));
vector<vector<int>> hel (10, vector<int>(10));
vector<int> gox = {0, 0, -1, 1};
vector<int> goy = {1, -1, 0, 0};

void spread_dfs(vector<vector<int>>& h, int x, int y){
	for(int i=0; i<4; ++i){
		int nx= x + gox[i];
		int ny = y + goy[i];
		if(!h[nx][ny]){
			h[nx][ny] = 2;
			spread_dfs(h, nx, ny);
		}
	}
}

void spread(vector<vector<int>>& h){
	vector<pair<int, int>> virus;
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=M; ++j){
			if(h[i][j]==2)
				virus.push_back({i, j});
		}
	}
	for(int i=0; i<virus.size(); ++i)
		spread_dfs(h, virus[i].first, virus[i].second);
	int cnt = 0;
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=M; ++j){
			if(!h[i][j])
				++cnt;
		}
	}
	if(cnt > safe)
		safe = cnt;
}

void dfs(int d, int topr){
	if(d==3){
		hel = lab;
		spread(hel);
		return;
	}
	for(int i=topr; i<=N; ++i){
		for(int j=1; j<=M; ++j){
			if(!lab[i][j]){
				lab[i][j] = 1;
				dfs(d+1, topr);
				lab[i][j] = 0;
			}
		}
	}
}

int main(void){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=M; ++j)
			cin >> lab[i][j];
	}
	dfs(0, 1);
	cout << safe;
	return 0;
}
