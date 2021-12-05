#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r, c, k;
int R, C, ans;
int A[101][101];

bool comp(const pair<int, int> a, const pair<int, int> b){
	if(a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

void get_input(){
	R=3, C=3, ans=0;
	for(int i=1; i<=100; ++i){
		for(int j=1; j<=100; ++j)
			A[i][j] = 0;
	}
	cin >> r >> c >> k;
	for(int i=1; i<=R; ++i){
		for(int j=1; j<=C; ++j)
			cin >> A[i][j];
	}
}

void row_sort(){
	for(int i=1; i<=R; ++i){
		vector<int> count_arr(101, 0);
		vector<pair<int, int>> count_nums;
		for(int j=1; j<=C; ++j){
			++count_arr[A[i][j]];
			A[i][j] = 0;
		}
		for(int n=1; n<=100; ++n){
			if(count_arr[n]) count_nums.push_back({n, count_arr[n]});
		}
		sort(count_nums.begin(), count_nums.end(), comp);
		if(2*count_nums.size() > C) C = 2*count_nums.size();
		for(int idx=0; idx<int(count_nums.size()); ++idx){
			A[i][2*idx+1] = count_nums[idx].first;
			A[i][2*idx+2] = count_nums[idx].second;
		}
	}
}

void column_sort(){
	for(int i=1; i<=C; ++i){
		vector<int> count_arr(101, 0);
		vector<pair<int, int>> count_nums;
		for(int j=1; j<=R; ++j){
			++count_arr[A[j][i]];
			A[j][i] = 0;
		}
		for(int n=1; n<=100; ++n){
			if(count_arr[n]) count_nums.push_back({n, count_arr[n]});
		}
		sort(count_nums.begin(), count_nums.end(), comp);
		if(2*count_nums.size() > R) R = 2*count_nums.size();
		for(int idx=0; idx<int(count_nums.size()); ++idx){
			A[2*idx+1][i] = count_nums[idx].first;
			A[2*idx+2][i] = count_nums[idx].second;
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	get_input();
	while(ans<101){
		if(A[r][c]==k) break;
		if(R>=C) row_sort();
		else column_sort();
		++ans;
	}
	if(ans>100) ans = -1;
	cout << ans;
	return 0;
}
