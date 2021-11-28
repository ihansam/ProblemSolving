#include <iostream>
using namespace std;

int ans=0, N, M, nx, ny;
int map[502][502] = {0,};
bool v[502][502] = {0,};
int gox[4] = {0, 0, -1, 1};
int goy[4] = {1, -1, 0, 0};

void dfs(int d, int x, int y, int res){
	if(d==4){
		if(res > ans) ans = res;
		return;
	}
	v[x][y] = 1;
	for(int i=0; i<4; ++i){
		nx = x + gox[i];
		ny = y + goy[i];
		if(nx>=1 && nx<=N && ny>=1 && ny<=M && !v[nx][ny]){
			dfs(d+1, nx, ny, res + map[nx][ny]);
		}
	}
	v[x][y] = 0;
}

int cross, fk;
void f(int x, int y){
	cross = map[x][y];
	for(int i=0; i<4; ++i)
		cross += map[x+gox[i]][y+goy[i]];
	for(int i=0; i<4; ++i){
		fk = cross - map[x+gox[i]][y+goy[i]];
		if(fk > ans) ans = fk;
	}
}

int main(void){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=M; ++j)
			cin >> map[i][j];
	}
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=M; ++j){
			dfs(1, i, j, map[i][j]);
			f(i, j);	// ㅗㅓㅏㅜ
		}
	}
	cout << ans;
	return 0;
}
