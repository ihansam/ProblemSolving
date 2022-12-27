#include <iostream>
using namespace std;

int M, x;
bool set[21];
string cmd;
	
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i=1; i<=20; ++i)
		set[i] = 0;
	cin >> M;
	for(int i=0; i<M; ++i){
		cin >> cmd;
		if(cmd == "all"){
			for(int j=1; j<=20; ++j)
				set[j] = 1;
		}
		else if(cmd == "empty"){
			for(int j=1; j<=20; ++j)
				set[j] = 0;
		}
		else{
			cin >> x;
			if(cmd == "add")
				set[x] = 1;
			else if(cmd == "remove")
				set[x] = 0;
			else if(cmd == "check")
				cout << set[x] << '\n';
			else if(cmd == "toggle")
				set[x] = (set[x])? 0 : 1;
		}
	}
	return 0;
}
