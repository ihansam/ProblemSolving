#include <iostream>
#include <vector>
using namespace std;

int N;
int max_block;
vector<vector<int>> map(20, vector<int>(20));
vector<vector<int>> cp_map(20, vector<int>(20));
vector<int> dir_cmd(5, 0);

void get_input(){
	cin >> N;
	max_block = 0;
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j)
			cin >> map[i][j];
	}
}

void move_block(){
	cp_map = map;
	int idx, curr;
	for(auto cmd: dir_cmd){
		if(cmd == 0){
			for(int row=0; row<N; ++row){
				vector<int> line(N, 0);
				idx = 0;
				int last = -1;
				for(int j=0; j<N; ++j){
					curr = cp_map[row][j];
					if(!curr) continue;
					if(curr==last){
						line[idx-1] *= 2;
						last = -1;
					}
					else{
						line[idx++] = curr;
						last = curr;
					}
				}
				for(int col=0; col<N; ++col)
					cp_map[row][col] = line[col];
			}
		}
		else if(cmd == 1){
			for(int row=0; row<N; ++row){
				vector<int> line(N, 0);
				idx = N-1;
				int last = -1;
				for(int j=N-1; j>=0; --j){
					curr = cp_map[row][j];
					if(!curr) continue;
					if(curr==last){
						line[idx+1] *= 2;
						last = -1;
					}
					else{
						line[idx--] = curr;
						last = curr;
					}
				}
				for(int col=0; col<N; ++col)
					cp_map[row][col] = line[col];
			}
		}
		else if(cmd == 2){
			for(int col=0; col<N; ++col){
				vector<int> line(N, 0);
				idx = 0;
				int last = -1;
				for(int i=0; i<N; ++i){
					curr = cp_map[i][col];
					if(!curr) continue;
					if(curr==last){
						line[idx-1] *= 2;
						last = -1;
					}
					else{
						line[idx++] = curr;
						last = curr;
					}
				}
				for(int row=0; row<N; ++row)
					cp_map[row][col] = line[row];
			}
		}
		else if (cmd == 3){
			for(int col=0; col<N; ++col){
				vector<int> line(N, 0);
				idx = N-1;
				int last = -1;
				for(int i=N-1; i>=0; --i){
					curr = cp_map[i][col];
					if(!curr) continue;
					if(curr==last){
						line[idx+1] *= 2;
						last = -1;
					}
					else{
						line[idx--] = curr;
						last = curr;
					}
				}
				for(int row=0; row<N; ++row)
					cp_map[row][col] = line[row];
			}	
		}
	}
}

void check_max_block(){
	int mb = 0;
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			if(cp_map[i][j] > mb) mb = cp_map[i][j];
		}
	}
	if(mb > max_block) max_block = mb;
}

void dfs(int d){
	if(d==5){
		move_block();
		check_max_block();
		return;
	}
	for(int dir=0; dir<4; ++dir){
		dir_cmd[d] = dir;
		dfs(d+1);
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	get_input();
	dfs(0);
	cout << max_block;
	return 0;
}
