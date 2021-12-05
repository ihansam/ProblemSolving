#include <iostream>
using namespace std;

int R, C, T;
int map[50][50];
int add_dust[50][50];
int cond, ans=2;
int gox[] = {1, -1, 0, 0};
int goy[] = {0, 0, 1, -1};

void set_input(){
	cin >> R >> C >> T;
	for(int i=0; i<R; ++i){
		for(int j=0; j<C; ++j)
			cin >> map[i][j];
	}
	for(int i=0; i<R; ++i){
		if(map[i][0]==-1){
			cond = i; break;
		}
	}	
}

void diffusion(){
	for(int i=0; i<R; ++i){
		for(int j=0; j<C; ++j)
			add_dust[i][j] = 0;
	}
	for(int i=0; i<R; ++i){
		for(int j=0; j<C; ++j){
			if(map[i][j] && map[i][j] != -1){
				int reduce = 0;
				for(int d=0; d<4; ++d){
					int ni = i + gox[d];
					int nj = j + goy[d];
					if(ni>=0 && ni<R && nj>=0 && nj<C && map[ni][nj] != -1){
						reduce += (map[i][j]/5);
						add_dust[ni][nj] += (map[i][j]/5);
					}
				}
				add_dust[i][j] -= reduce;
			}
		}
	}
	for(int i=0; i<R; ++i){
		for(int j=0; j<C; ++j)
			map[i][j] += add_dust[i][j];
	}
}

void cycle(){
	// upside
	for(int r = cond-2; r>=0; --r)
		map[r+1][0] = map[r][0];
	for(int c=0; c<C; ++c)
		map[0][c] = map[0][c+1];
	for(int r=0; r<cond; ++r)
		map[r][C-1] = map[r+1][C-1];
	for(int c=C-1; c>1 ; --c)
		map[cond][c] = map[cond][c-1];
	map[cond][1] = 0;
	// downside
	for(int r = cond+2; r<R-1; ++r)
		map[r][0] = map[r+1][0];
	for(int c=0; c<C; ++c)
		map[R-1][c] = map[R-1][c+1];
	for(int r=R-2; r>cond; --r)
		map[r+1][C-1] = map[r][C-1];
	for(int c=C-1; c>1 ; --c)
		map[cond+1][c] = map[cond+1][c-1];
	map[cond+1][1] = 0;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	set_input();
	while(T--){
		diffusion();
		cycle();
	}
	for(int i=0; i<R; ++i){
		for(int j=0; j<C; ++j)
			ans += map[i][j];
	}
	cout << ans;
	return 0;
}
