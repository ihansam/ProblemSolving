#include <vector>
#include <iostream>
using namespace std;

typedef struct dice{
	int top=0;
	int l=0; int f=0; int r=0; int b=0;
	int bottom=0;
} DICE;

DICE d;
int N, M, x, y, K, tmp, dir;
vector<vector<int>> map(20, vector<int>(20));
vector<int> inst(1000);

vector<int> gox = {0, 0, 0, -1, 1};
vector<int> goy = {0, 1, -1, 0, 0};

void move_dice(int dir){
	if(dir==1){
		tmp = d.r;
		d.r = d.top;
		d.top = d.l;
		d.l = d.bottom;
		d.bottom = tmp;
	}
	else if(dir==2){
		tmp = d.r;
		d.r = d.bottom;
		d.bottom = d.l;
		d.l = d.top;
		d.top = tmp;
	}
	else if(dir==3){
		tmp = d.top;
		d.top = d.f;
		d.f = d.bottom;
		d.bottom = d.b;
		d.b = tmp;
	}
	else{
		tmp = d.f;
		d.f = d.top;
		d.top = d.b;
		d.b = d.bottom;
		d.bottom = tmp;
	}
}

int main(void){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M >> x >> y >> K;
	for(int i=0; i<N; ++i){
		for(int j=0; j<M; ++j)
			cin >> map[i][j];
	}
	for(int i=0; i<K; ++i){
		cin >> inst[i];
	}
	
	for(int i=0; i<K; ++i){
		dir = inst[i];
		x += gox[dir];
		y += goy[dir];
		if(x>=0 && x<N && y>=0 && y<M){
			move_dice(dir);
			if(!map[x][y])
				map[x][y] = d.bottom;
			else{
				d.bottom = map[x][y];
				map[x][y] = 0;
			}
			cout << d.top << '\n';
		}
		else{
			x -= gox[dir];
			y -= goy[dir];
		}		
	}
	return 0;
}
