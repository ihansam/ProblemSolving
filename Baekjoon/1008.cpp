#include <iostream>
using namespace std;

double A, B;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> A >> B;
	
	cout << fixed;
	cout.precision(12);
	cout << A/B;
	return 0;
}
