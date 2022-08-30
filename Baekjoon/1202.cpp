#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#define IO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, K, m, v;
long long ans = 0;
vector<pair<int, int>> jewel(300000);
multiset<int> bag;

void get_input(){
	cin >> N >> K;
	for(int i=0; i<N; ++i){
		cin >> m >> v;
		jewel[i] = {v, m};
	}
	for(int i=0; i<K; ++i){
		cin >> m;
		bag.insert(m);
	}
	sort(jewel.begin(), jewel.begin()+N, greater<>());
}

void solve(){
	for(int i=0; i<N; ++i){
		m = jewel[i].second;
		v = jewel[i].first;
		auto it = bag.lower_bound(m);
		if(it==bag.end()) continue;
		ans += v;
		bag.erase(it);
		if(!bag.size()) break;
	}
	cout << ans;
}

int main(void){
	IO;
	get_input();
	solve();
	return 0;
}
