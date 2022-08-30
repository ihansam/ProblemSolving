#include <vector>
#include <iostream>
#include <queue>
#define x first
#define y second
using namespace std;

typedef pair<int, int> pt;
typedef struct record{
	pt red;
	pt blue;
	int last_dir;
}Record;

int N, M;
int ans;
char ch;
bool found;
int map[10][10];
pt red, blue;
int gx[] = {0, 1, -1, 0, 0};
int gy[] = {0, 0, 0, -1, 1};
queue<Record> rq;

void set_input(){
	cin >> N >> M;
	ans = -1;
	found = false;
	while(!rq.empty()) rq.pop();
	for(int i=0; i<N; ++i){
		for(int j=0; j<M; ++j){
			cin >> ch;
			if(ch=='#'){
				map[i][j] = -1;
				continue;
			}
			else if(ch=='O'){
				map[i][j] = 1;
				continue;
			}
			else if(ch=='R') red = {i, j};
			else if(ch=='B') blue = {i, j};
			map[i][j] = 0;
		}
	}
}

bool move_ball(pt& ball, const int dir){
	int nx = ball.x + gx[dir];
	int ny = ball.y + gy[dir];
	while(map[nx][ny] != -1){
		ball.x = nx;
		ball.y = ny;
		if(map[nx][ny]==1) return true;
		nx += gx[dir];
		ny += gy[dir];
	}
	return false;
}

void adjust_balls(const int dir, const pt r, const pt b, pt& nr, pt& nb){
	if(dir==1){
		if(r.x < b.x) --nr.x;
		else --nb.x;
	}
	else if(dir==2){
		if(r.x < b.x) ++nb.x;
		else ++nr.x;
	}
	else if(dir==3){
		if(r.y < b.y) ++nb.y;
		else ++nr.y;
	}
	else if(dir==4){
		if(r.y < b.y) --nr.y;
		else --nb.y;
	}
}

void bfs(){
	int n = int(rq.size());
	for(int i=0; i<n; ++i){
		Record rc = rq.front();
		rq.pop();
		pt r = rc.red;
		pt b = rc.blue;
		for(int ndir=1; ndir<=4; ++ndir){
			if(ndir==rc.last_dir) continue;
			pt nr = r;
			pt nb = b;
			bool red_in = move_ball(nr, ndir);
			bool blue_in = move_ball(nb, ndir);
			if(nr == nb) adjust_balls(ndir, r, b, nr, nb);
			if(red_in && !blue_in){
				found = true;
				return;
			}
			else if(blue_in) continue;
			rq.push(Record{nr, nb, ndir});
		}		
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	set_input();
	rq.push(Record{red, blue, 0});
	for(int d=1; d<=10; ++d){
		bfs();
		if(found){
			ans = d;
			break;
		}
	}
	cout << ans;
	return 0;
}
