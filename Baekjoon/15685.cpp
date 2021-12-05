#include <iostream>
using namespace std;

int N, x, y, d, g, ans=0;
int map[101][101] = {0,};
int gox[4] = {1, 0, -1, 0};
int goy[4] = {0, -1, 0, 1};
int directions[1024];

void draw(){
	map[x][y] = 1;
	directions[0] = d;
	x += gox[d];
	y += goy[d];
	map[x][y] = 1;
	int gen, i, j, range;
	for(gen=1; gen<=g; ++gen){
		range = 1<<(gen-1);
		for(i=0; i<range; ++i){
			d = directions[range+i] = (directions[range-1-i] + 1)%4;
			x += gox[d];
			y += goy[d];
			map[x][y] = 1;
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	cin >> N;
	for(int i=0; i<N; ++i){
		cin >> x >> y >> d >> g;
		draw();
	}
	for(int i=0; i<100; ++i){
		for(int j=0; j<100; ++j){
			if(map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1])
				++ans;
		}
	}
	cout << ans;
	return 0;
}
