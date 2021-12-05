#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pt;

int N, M;
int min_time;
int lab[52][52];
int copy_map[52][52];
int gox[] = {0, 0, 1, -1};
int goy[] = {1, -1, 0, 0};
vector<pt> candidates;
vector<bool> visit(2500, false);

void get_input(){
	for(int i=0; i<52; ++i){
		for(int j=0; j<52; ++j)
			lab[i][j] = -1;
	}
	min_time = 2500;
	candidates.clear();
	cin >> N >> M;
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=N; ++j){
			cin >> lab[i][j];
			if(lab[i][j]==1) lab[i][j] = -1;
			else if(lab[i][j]==2){
				candidates.push_back(make_pair(i, j));
				lab[i][j] = 0;
			}
		}
	}
}

int infect_time(){
	int max_time = -1;
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=N; ++j){
			if(!copy_map[i][j]) return 2500;
			else if(copy_map[i][j] > max_time) max_time=copy_map[i][j];
		}
	}
	return max_time - 1;
}

void spread_virus_bfs(){
	int x, y, nx, ny;
	for(int i=0; i<=N+1; ++i){
		for(int j=0; j<=N+1; ++j)
			copy_map[i][j] = lab[i][j];
	}
	queue<pt> q;
	for(int i=0; i<int(candidates.size()); ++i){
		if(visit[i]) {
			q.push(candidates[i]);
			x = candidates[i].first;
			y = candidates[i].second;
			copy_map[x][y] = 1;
		}
		if(q.size()==M) break;
	}
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i=0; i<4; ++i){
			nx = x + gox[i];
			ny = y + goy[i];
			if(copy_map[nx][ny]==0){
				copy_map[nx][ny] = copy_map[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
	int inf_time = infect_time();
	if(inf_time < min_time) min_time = inf_time;
}

void put_virus_dfs(int d, int last_visit_idx){
	if(d==M){
		spread_virus_bfs();
		return;
	}
	for(int i=last_visit_idx+1; i<int(candidates.size()); ++i){
		if(!visit[i]){
			visit[i] = 1;
			put_virus_dfs(d+1, i);
			visit[i] = 0;
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	get_input();
	put_virus_dfs(0, -1);
	if(min_time == 2500) min_time = -1;
	cout << min_time;
	return 0;
}
