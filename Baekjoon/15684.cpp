#include <iostream>
using namespace std;

int N, M, H, answer = -1;
bool found = false;
int map[11][31] = {0,};

void check_done(int depth){
	for(int _in=1; _in<N; ++_in){
		int line = _in;
		for(int step=1; step<=H; ++step){
			if(map[line-1][step]) --line;
			else if(map[line][step]) ++line;
		}
		if(line != _in) return;
	}
	answer = depth;
	found = true;
}

void dfs(int d, int max_d, int start_line){
	check_done(d);
	if(found || d==max_d) return;
	for(int line=start_line; line<N; ++line){
		for(int step=1; step<=H; ++step){
			if(!map[line][step] && !map[line-1][step] && !map[line+1][step]){
				map[line][step] = 1;
				dfs(d+1, max_d, line);
				map[line][step] = 0;
			}
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> H;
	for(int i=0; i<M; ++i){
		int a, b;
		cin >> a >> b;
		map[b][a] = 1;
	}
	if(!M) answer = 0;
	else{
		for(int max_d=1; max_d<4; ++max_d){
			dfs(0, max_d, 1);
			if(found) break;
		}
	}
	cout << answer;
	return 0;
}
