#include <vector>
#include <iostream>
using namespace std;

int N, M, K, x, y, age;
int A[12][12];
int cnt = 0;
int map[12][12];
vector<int> Tree[12][12];
vector<int> Trees;

void one_year_after(){
	//Spring & Summer
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=N; ++j){
			int k;
			Trees = Tree[i][j];
			for(k=int(Trees.size())-1; k>=0; --k){
				age = Trees[k];
				if(map[i][j]>=age){
					map[i][j] -= age;
					++Trees[k];
				}
				else break;
			}
			for(int dead_tree=0; dead_tree<=k; ++dead_tree)
				map[i][j] += Trees[dead_tree]/2;
			vector<int> survive;
			for(int surv_tree=k+1; surv_tree<int(Trees.size()); ++surv_tree)
				survive.push_back(Trees[surv_tree]);
			Tree[i][j] = survive;
		}
	}
	// Fall
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=N; ++j){
			Trees = Tree[i][j];
			for(auto t: Trees){
				if(!(t%5)){
					for(int ii=-1; ii<2; ++ii){
						for(int jj=-1; jj<2; ++jj){
							if(!ii && !jj) continue;
							Tree[i+ii][j+jj].push_back(1);
						}
					}
				}
			}
		}
	}
	// Winter
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=N; ++j){
			map[i][j] += A[i][j];
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> K;
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=N; ++j)
			cin >> A[i][j];
	}
	for(int i=0; i<M; ++i){
		cin >> x >> y >> age;
		Tree[x][y].push_back(age);
	}
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=N; ++j)
			map[i][j] = 5;
	}
	while(K--)
		one_year_after();
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=N; ++j)
			cnt += Tree[i][j].size();
	}
	cout << cnt;
	return 0;
}
