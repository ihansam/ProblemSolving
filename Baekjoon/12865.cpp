#include <iostream>
using namespace std;

int N, K, weight, value;
int BP[101][100001] = {0,};

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	for(int i=1; i<=N; ++i){
		cin >> weight >> value;
		for(int w=1; w<=K; ++w){
			if(w >= weight){
				BP[i][w] = max(BP[i-1][w-weight]+value, BP[i-1][w]);
			}
			else{
				BP[i][w] = BP[i-1][w];
			}
		}
	}
	cout << BP[N][K];
	return 0;
}
