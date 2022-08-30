#include <iostream>
#define IO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, S, ans=100001, l, r, part_sum;
int a[100000];

void get_input(){
	cin >> N >> S;
	for(int i=0; i<N; ++i) cin >> a[i];
}

void solve(){
	l=r=-1; part_sum=0;
	while(l<=r){
		if(part_sum < S){
			if(r<N-1) part_sum += a[++r];
			else break;
		}
		else{
			if(r-l < ans) ans = r-l;
			part_sum -= a[++l];
		}
	}
	cout << ((ans==100001)? 0 : ans);
}

int main(void){
	IO;
	get_input();
	solve();
	return 0;
}
