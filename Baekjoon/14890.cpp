#include <iostream>
#include <vector>
using namespace std;

int N, L, ans;

int check(vector<int>& line){
	vector<bool> put(N, 0);
	for(int i=0; i<N-1; ++i){
		int diff = line[i]-line[i+1];
		if(abs(diff)>1) return 0;
		else if(abs(diff)==1){
			int _from = i + (diff==1);
			int _end = _from + diff*L;
			if(_end<-1 || _end>N) return 0;
			for(int idx = _from; idx != _end; idx += diff){
				if((line[idx] != line[_from]) || put[idx]) return 0;
				put[idx] = 1;
			}
		}
	}
	return 1;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> L;
	vector<vector<int>> map(N, vector<int>(N));
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			cin >> map[i][j];
		}
	}
	for(int i=0; i<N; ++i){
		ans += check(map[i]);
		vector<int> tmp;
		for(int j=0; j<N; ++j)
			tmp.push_back(map[j][i]);
		ans += check(tmp);
	}
	cout << ans;
	return 0;
}
