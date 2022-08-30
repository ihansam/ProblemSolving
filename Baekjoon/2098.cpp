#include <cstdio>
#define INF 16000000
#define START 0
using namespace std;

int N, END;
int map[16][16] = {0,};
int DP[16][1<<15] = {0,};

int min(int a, int b){
	return (a<b)? a : b;
}

void get_input(){
	scanf("%d", &N);
	END = (1<<(N-1))-1;
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j)
			scanf("%d", &map[i][j]);
	}
}

int dfs(int curr, int bitmask){
	if(bitmask == END){
		if(map[curr][START])
			return map[curr][START];
		else
			return INF;
	}
	
	int& ret = DP[curr][bitmask];
	if(ret) return ret;
	
	ret = INF;
	for(int next=1; next<N; ++next){
		if(!(bitmask&(1<<(next-1))) && map[curr][next])
			ret = min(ret, dfs(next, bitmask|(1<<(next-1))) + map[curr][next]);
	}
	return ret;
}

int main(void){
	get_input();
	printf("%d", dfs(START, 0));
	return 0;
}
