#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int N, K, x, y, L, X, xx, yy;
char d;
vector<int> gox = {0, 1, 0, -1};
vector<int> goy = {1, 0, -1, 0};
vector<vector<int>> board(101, vector<int>(101, 0));
queue<pair<int, int>> snake;
queue<pair<int, int>> cmd;
int ans = 0;
int dir = 0;

int main(void){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=N; ++j)
			board[i][j] = 1;
	}
	for(int k=0; k<K; ++k){
		cin >> x >> y;
		board[x][y] = -1;
	}
	cin >> L;
	for(int i=0; i<L; ++i){
		cin >> X >> d;
		cmd.push({X, d-'D'});
	}
	snake.push({1, 1});
	board[1][1] = 0;
	x = 1; y = 2;
	while(board[x][y]){			// 벽 or 뱀 만나면 break
		++ans;
		if(board[x][y]==1){		// 사과 없는 길
			xx = snake.front().first;
			yy = snake.front().second;
			board[xx][yy] = 1;
			snake.pop();
		}
		board[x][y] = 0;
		snake.push({x, y});
		if(!cmd.empty() && cmd.front().first == ans){
			if(!cmd.front().second)	// 'D' - 'D' == 0: 우회전
				++dir;
			else --dir;
			if(dir==-1) dir=3;
			else if(dir==4) dir=0;
			cmd.pop();
		}
		x += gox[dir];
		y += goy[dir];
	}
	cout << ans + 1;
	return 0;
}
