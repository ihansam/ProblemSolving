#include <iostream>
#include <vector>
using namespace std;

int N, mres=1000000000, Mres=-1000000000, n;
vector<int> nums(11);
vector<int> life(4);
vector<int> choose_op(11);

void dfs(int d){
	if(d==N-1){
		n = nums[0];
		for(int i=1; i<=N-1; ++i){
			if(choose_op[i]==0) n += nums[i];
			else if(choose_op[i]==1) n -= nums[i];
			else if(choose_op[i]==2) n *= nums[i];
			else if(choose_op[i]==3) n /= nums[i];
		}
		if(n>Mres) Mres = n;
		if(n<mres) mres = n;
		return;
	}
	for(int i=0; i<4; ++i){
		if(life[i]){
			--life[i];
			choose_op[d+1] = i;
			dfs(d+1);
			++life[i];
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for(int i=0; i<N; ++i)
		cin >> nums[i];
	
	for(int i=0; i<4; ++i)
		cin >> life[i];	
	
	dfs(0);
	cout << Mres << '\n' << mres;
	
	return 0;
}
