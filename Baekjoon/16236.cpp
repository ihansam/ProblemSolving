#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct{
	int x; int y;
	int size;
}Point;

int N;
int ans = 0;
Point shark;
int eat_count = 0;
int shark_size = 2;
int map[20][20];
int visit[20][20] = {0,};
int gox[] = {1, -1, 0, 0};
int goy[] = {0, 0, 1, -1};
queue<Point> q;
vector<Point> candidates = {{0, 0}};

void get_input(){
	cin >> N;
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			cin >> map[i][j];
			if(map[i][j]==9){
				map[i][j] = 0;
				shark = {i, j};
			}
		}
	}
}

void hunt(){
	while(candidates.size()){
		int victim_distance = 50;
		bool found = false;
		candidates.clear();
		for(int i=0; i<N; ++i){
			for(int j=0; j<N; ++j) visit[i][j] = 0;
		}
		q.push(shark);
		visit[shark.x][shark.y] = 1;
		while(!q.empty()){
			Point curr = q.front();
			q.pop();
			if(found && visit[curr.x][curr.y] > victim_distance){
				while(!q.empty()) q.pop();
				continue;
			}
			for(int i=0; i<4; ++i){
				int nx = curr.x + gox[i];
				int ny = curr.y + goy[i];
				if(nx>=0 && nx<N && ny>=0 && ny<N && !visit[nx][ny]){
					if(map[nx][ny] > shark_size) continue;
					if(map[nx][ny]>0 && (map[nx][ny] < shark_size)){
						found = true;
						victim_distance = visit[curr.x][curr.y];
						candidates.push_back({nx, ny});
					}
					else{
						q.push({nx, ny});
						visit[nx][ny] = visit[curr.x][curr.y] + 1;
					}
				}
			}
		}
		if(!candidates.size()) continue;
		Point victim = candidates[0];
		for(int i=1; i<int(candidates.size()); ++i){
			int cx = candidates[i].x;
			int cy = candidates[i].y;
			if((victim.x > cx) || (victim.x == cx && victim.y > cy))
				victim = candidates[i];
		}
		shark.x = victim.x;
		shark.y = victim.y;
		map[victim.x][victim.y] = 0;
		if(++eat_count == shark_size){
			++shark_size;
			eat_count = 0;
		}
		ans += victim_distance;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	get_input();
	hunt();
	cout << ans;
	return 0;
}
