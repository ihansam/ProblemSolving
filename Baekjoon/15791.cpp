#include <iostream>
#define IO cin.tie(0)->sync_with_stdio(0)
#define MOD 1000000007
#define ll long long
using namespace std;

int n, m;
ll fac=1, fac_n_minus_m=1, fac_m=1;

ll pow(ll a, ll b){
	if(a==1) return 1;
	if(b==0) return 1;
	if(b%2) return (pow(a, b-1)*a)%MOD;
	else{
		ll h = pow(a, b/2) % MOD;
		return h*h%MOD;
	}
}

int main(void){
	IO;
	cin >> n >> m;
	for(int i=2; i<=n; ++i){
		fac = (fac*i)%MOD;
		if(i==n-m) fac_n_minus_m = fac;
		if(i==m) fac_m = fac;
	}
	cout << (fac * pow((fac_n_minus_m * fac_m) % MOD, MOD-2)) % MOD;
	return 0;
}
