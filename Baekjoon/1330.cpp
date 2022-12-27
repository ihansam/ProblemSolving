#include <iostream>
using namespace std;

int A, B;
string res;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> A >> B;
	
	res = (A==B)? "==" : ((A>B)? ">" : "<");
	cout << res;
	
	return 0;
}
