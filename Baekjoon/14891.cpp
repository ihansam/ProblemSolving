#include <vector>
#include <iostream>
using namespace std;

int K, num, dir, ans=0;
vector<string> topni(5);
vector<int> topidx(5, 0);
vector<bool> visit(5, 0);
int WEST = 6, EAST = 2, TOP = 0;

int get_idx(int idx, int diff){
	idx += diff;
	if(idx>=8) return idx%8;
	else if(idx<0) return idx%8+8;
	else return idx;
}

bool get_topni_pole(int tnum, int i){
	return topni[tnum][get_idx(topidx[tnum], i)] - '0';
}

void turn_topni(int n, int d){
	visit[n] = 1;
	if(n>1 && !visit[n-1] && (get_topni_pole(n-1, EAST)!=get_topni_pole(n, WEST)))
		turn_topni(n-1, -d);
	if(n<4 && !visit[n+1] && (get_topni_pole(n+1, WEST)!=get_topni_pole(n, EAST)))
		turn_topni(n+1, -d);
	// turn top idx (d=1이면 1 감소)
	topidx[n] = get_idx(topidx[n], -d);
	visit[n] = 0;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i;
	for(i=1; i<=4; ++i)
		cin >> topni[i];
	cin >> K;
	for(i=0; i<K; ++i){
		cin >> num >> dir;
		turn_topni(num, dir);
	}
	for(i=1; i<=4; ++i)
		ans += (get_topni_pole(i, TOP))*(1<<(i-1));
	cout << ans;
	return 0;
}
