#include <iostream>
#define MOD (int)1e9
using namespace std;

int N;
long long dp[101][10][1024];

int solve(int n){
	if(n<10) return 0;
	for(int i=1; i<=9; ++i) dp[1][i][1<<i] = 1;
	for(int zari=2; zari<=n; ++zari){
		for(int lst=0; lst<=9; ++lst){
			for(int used=0; used<1024; ++used){
				int use = used | (1<<lst);
				if(lst!=0)
					dp[zari][lst][use] += dp[zari-1][lst-1][used];
				if(lst!=9)
					dp[zari][lst][use] += dp[zari-1][lst+1][used];
				dp[zari][lst][use] %= MOD;
			}
		}
	}
	int ans = 0;
	for(int i=0; i<=9; ++i) ans = (ans+dp[n][i][1023]) % MOD;
	return ans;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	cout << solve(N);
	return 0;
}
