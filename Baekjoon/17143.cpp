#include <iostream>
using namespace std;

typedef struct shark{
	int x;
	int y;
	int s;
	int d;
	int z;
}Shark;

int R, C, M, r, c, s, d, z;
int ans=0, fish_king=0;
int gox[] = {0, -1, 1, 0, 0};
int goy[] = {0, 0, 0, 1, -1};
int map[101][101] = {0,};
Shark sharks[10001];

void get_input(){
	cin >> R >> C >> M;
	for(int i=1; i<=R; ++i){
		for(int j=1; j<=C; ++j) map[i][j] = 0;
	}
	for(int i=1; i<=M; ++i){
		cin >> r >> c >> s >> d >> z;
		map[r][c] = i;
		sharks[i] = {r, c, s, d, z};
	}
}

void kill_shark(){
	for(int i=1; i<=R; ++i){
		int shark_idx = map[i][fish_king];
		if(shark_idx){
			ans += sharks[shark_idx].z;
			sharks[shark_idx].z = 0;
			map[i][fish_king] = 0;
			break;
		}
	}
}

void move_a_shark(int sk_idx){
	int curr;
	int dir = sharks[sk_idx].d;
	if(dir<3){	// 위 아래
		int move_cnt = (sharks[sk_idx].s%(2*(R-1)));
		curr = sharks[sk_idx].x;
		while(move_cnt--){
			if(dir==1){
				if(--curr==0){
					curr=2;
					dir = 2;
				}
			}
			else{
				if(++curr==R+1){
					curr=R-1;
					dir = 1;
				}
			}
		}
		sharks[sk_idx].x = curr;
	}
	else{		// 좌우
		int move_cnt = (sharks[sk_idx].s%(2*(C-1)));
		curr = sharks[sk_idx].y;
		while(move_cnt--){
			if(dir==4){
				if(--curr==0){
					curr = 2;
					dir = 3;
				}
			}
			else{
				if(++curr==C+1){
					curr = C-1;
					dir = 4;
				}
			}
		}
		sharks[sk_idx].y = curr;
	}
	sharks[sk_idx].d = dir;
}

void move_sharks(){
	for(int idx=1; idx<=M; ++idx){
		Shark sk = sharks[idx];
		if(!sk.z) continue;
		map[sk.x][sk.y] = 0;
		move_a_shark(idx);
	}
	for(int idx=1; idx<=M; ++idx){
		Shark sk = sharks[idx];
		if(!sk.z) continue;
		int map_num = map[sk.x][sk.y];
		if(map_num){	// 이미 상어가 있을 떄
			if(sharks[map_num].z > sk.z){	// 원래 애가 크면
				sharks[idx].z = 0;			// 새 상어는 먹힘
				continue;
			}
			else{							// 굴러온 애가 크면
				sharks[map_num].z = 0;		// 원래 애를 먹음
			}
		}
		map[sk.x][sk.y] = idx;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	get_input();
	if(!M){
		cout << 0;
		return 0;
	}
	while(++fish_king<=C){
		kill_shark();
		move_sharks();
	}
	cout << ans;
	return 0;
}
