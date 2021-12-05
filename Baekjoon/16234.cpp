#include <vector>
#include <queue>
#include <iostream>
using namespace std;

typedef pair<int, int> country;
int gox[] = {1, 0, -1, 0};
int goy[] = {0, 1, 0, -1};

int N, L, R;
int day=0, union_sum;
int x, y, nx, ny;
int move_cnt=-1;
int map[50][50];
bool visit[50][50] = {0,};
vector<country> unions;
queue<country> q;

void move_people(){
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j)
			visit[i][j] = 0;
	}
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			if(!visit[i][j]){
				visit[i][j] = 1;
				union_sum = map[i][j];
				unions.clear();
				unions.push_back({i, j});
				q.push({i, j});
				while(!q.empty()){
					x = q.front().first;
					y = q.front().second;
					q.pop();
					for(int k=0; k<4; ++k){
						nx = x + gox[k];
						ny = y + goy[k];
						if(nx>=0 && nx<N && ny>=0 && ny<N && !visit[nx][ny]){
							int diff = abs(map[x][y] - map[nx][ny]);
							if(diff>=L && diff<=R){
								visit[nx][ny] = 1;
								union_sum += map[nx][ny];
								unions.push_back({nx, ny});
								q.push({nx, ny});
							}
						}
					}
				}
				if(unions.size()>1){
					++move_cnt;
					union_sum /= unions.size();
					for(auto ctry: unions){
						map[ctry.first][ctry.second] = union_sum;
					}	
				}
			}
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> L >> R;
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j)
			cin >> map[i][j];
	}
	while(move_cnt){
		move_cnt = 0;
		move_people();
		if(move_cnt)
			++day;
	}
	cout << day;
	return 0;
}
