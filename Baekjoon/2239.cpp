#include <string>
#include <vector>
#include <iostream>
#define IO cin.tie(0)->sync_with_stdio(0)
using namespace std;

bool found = false;
vector<string> sudoku(9);

bool check(const int x, const int row, const int col){
	for(int c=0; c<9; ++c){
		if(c==col) continue;
		if(sudoku[row][c] - '0' == x) return false;
	}
	for(int r=0; r<9; ++r){
		if(r==row) continue;
		if(sudoku[r][col] - '0' == x) return false;
	}
	int r = (row/3)*3; int c = (col/3)*3;
	for(int i=0; i<3; ++i){
		for(int j=0; j<3; ++j){
			if(r+i==row && c+j==col) continue;
			if(sudoku[r+i][c+j] - '0' == x) return false;
		}
	}	
	return true;
}

void dfs(int d){
	if(d==81 || found) {
		found = true;
		return;
	}
	int row = d/9, col = d%9;
	if(sudoku[row][col] - '0') dfs(d+1);
	else{
		for(int num=1; num<10; ++num){
			if(check(num, row, col)){
				sudoku[row][col] = '0' + num;
				dfs(d+1);
				if(!found) sudoku[row][col] = '0';
			}
		}
	}
}

void get_input(){
	for(int i=0; i<9; ++i)
		cin >> sudoku[i];
}

void solve(){
	dfs(0);
	for(int i=0; i<9; ++i){
		cout << sudoku[i] << '\n';
	}
}

int main(void){
	IO;
	get_input();
	solve();
	return 0;
}
