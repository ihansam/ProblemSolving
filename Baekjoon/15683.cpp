#include <vector>
#include <iostream>
using namespace std;

typedef struct camara{
	int x; int y; int c;
} Camera;

bool found_zero = false;
int N, M, ans=64;
vector<vector<int>> map(10, vector<int>(10, 6));
vector<vector<int>> cmap(10, vector<int>(10));
vector<int> gox = {-1, 0, 1, 0};
vector<int> goy = {0, 1, 0, -1};
vector<Camera> cams;
vector<int> dir_num = {0, 4, 2, 4, 4, 1};
vector<int> cams_dir_idx(64, 0);

void fill_map(int x, int y, vector<int> ckd){
	for(auto dir: ckd){
		int nx = x + gox[dir];
		int ny = y + goy[dir];
		while(cmap[nx][ny]!=6){
			if(!cmap[nx][ny])
				cmap[nx][ny] = -1;	// 감시 영역
			nx += gox[dir];
			ny += goy[dir];
		}
	}
}

void count_blinds(){
	int cnt = 0;
	cmap = map;
	
	for(int i=0; i<cams.size(); ++i){
		vector<int> check_dir;
		switch(cams[i].c){
			case 1:
				check_dir.push_back(cams_dir_idx[i]); break;
			case 2:
				check_dir.push_back(cams_dir_idx[i]);
				check_dir.push_back(cams_dir_idx[i]+2); break;
			case 3:
				check_dir.push_back(cams_dir_idx[i]);
				check_dir.push_back((cams_dir_idx[i]+1)%4); break;
			case 4:
				for(int j=0; j<4; ++j){
					if(j!=cams_dir_idx[i]) check_dir.push_back(j);
				}
				break;
			case 5:
				check_dir = {0, 1, 2, 3};
				break;
		}
		fill_map(cams[i].x, cams[i].y, check_dir);
	}	
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=M; ++j){
			if(!cmap[i][j]) ++cnt;
		}
	}
	if(cnt<ans) ans = cnt;
	if(!ans) found_zero = true;
}

void dfs(int d){
	if(found_zero) return;
	if(d==cams.size()){
		count_blinds();
		return;
	}
	int cam_num = cams[d].c;
	for(int dir=0; dir<dir_num[cam_num]; ++dir){
		cams_dir_idx[d] = dir;
		dfs(d+1);
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	int i, j, n;
	for(i=1; i<=N; ++i){
		for(j=1; j<=M; ++j){
			cin >> n;
			map[i][j] = n;
			if (n>0 && n<6){
				Camera cam = {i, j, n};
				cams.push_back(cam);
			}
		}
	}
	dfs(0);
	cout << ans;
	return 0;
}
