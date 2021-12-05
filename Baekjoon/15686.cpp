#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> coord;

int N, M, ans=10000, tmp, cnt=0, hcnt=0;
vector<coord> house(100);
vector<coord> chick_house(13);
vector<bool> visit(13, 0);

int chick_distance(coord c, coord h){
	return abs(c.first - h.first) + abs(c.second - h.second);
}

int city_chick_distance(){
	int ccd = 0;
	for(int h=0; h<hcnt; ++h){
		int min_d = 10000;
		for(int i=0; i<cnt; ++i){
			if(!visit[i]){
				tmp = chick_distance(house[h], chick_house[i]);
				if(tmp < min_d) min_d = tmp;			
			}
		}
		ccd += min_d;
	}
	return ccd;
}

void dfs(int d, int last){
	if(d+M==cnt){
		int ccd = city_chick_distance();
		if(ccd < ans) ans = ccd;
		return;
	}
	for(int i=last+1; i<cnt; ++i){
		if(!visit[i]){
			visit[i] = 1;
			dfs(d+1, i);
			visit[i] = 0;
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=N; ++j){
			cin >> tmp;
			if(tmp==1)
				house[hcnt++] = {i, j};
			if(tmp==2)
				chick_house[cnt++] = {i, j};
		}
	}
	dfs(0, -1);
	cout << ans;
	return 0;
}
