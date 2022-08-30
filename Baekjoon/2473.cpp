#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
#define IO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N;
vector<ll> a(5000);

inline ll my_abs(ll a){return (a>0)? a : -a;}

void get_input(){
	cin >> N;
	for(int i=0; i<N; ++i)
		cin >> a[i];
	sort(a.begin(), a.begin()+N);
}

void solve(){
	ll ansl, ansr, ansm, l, r, m;
	ll ans=3000000000, tmp;
	
	for(int m=0; m<N-2; ++m){
		l = m+1; r = N-1;
		while(l<r){
			if(l==m){
				++l;
				continue;
			}
			if(r==m){
				--r;
				continue;
			}
			tmp = a[l] + a[r] + a[m];
			if(my_abs(tmp) < ans){
				ans = my_abs(tmp);
				ansl = a[l];
				ansr = a[r];
				ansm = a[m];
			}
			if(tmp > 0) --r;
			else ++l;
		}
	}
	
	vector<ll> answer = {ansl, ansr, ansm};
	sort(answer.begin(), answer.end());
	for(auto tmp: answer)
		cout << tmp << ' ';
}

int main(void){
	IO;
	get_input();
	solve();
	return 0;
}
