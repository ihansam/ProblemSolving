#include <iostream>
#include <vector>
using namespace std;

int ans=0, N, M, x, y, nx, ny, dir;
vector<vector<char>> map (51, vector<char>(51, 0));
vector<int> gox = {-1, 0, 1, 0};
vector<int> goy = {0, 1, 0, -1};

int turn(int dir){
	return (!dir)? 3 : dir-1;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> x >> y >> dir;
	for(int i=0; i<N; ++i){
		for(int j=0; j<M; ++j)
			cin >> map[i][j];
	}
	
	bool finish = false;
	while(!finish){
		if(map[x][y]=='0'){
			map[x][y] = '2';	// clean
			++ans;
		}
		for(int i=0; i<4; ++i){
			dir = turn(dir);
			nx = x + gox[dir];
			ny = y + goy[dir];	
			if(map[nx][ny]=='0'){
				x = nx;
				y = ny;
				break;
			}
		}
		if(map[x][y]=='0') continue;
		x -= gox[dir];
		y -= goy[dir];
		if(map[x][y]=='1')
			finish = true;
	}
	
	cout << ans;
	return 0;
}
