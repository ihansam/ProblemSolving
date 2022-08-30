#include <iostream>
#define IO cin.tie(0)->sync_with_stdio(0)
#define ll long double
using namespace std;

int N;
ll x0, y0, x1, y1, x2, y2;
ll ans = 0;

ll ccw_area(){
	return x0*y1 + x1*y2 + x2*y0 - x1*y0 - x2*y1 - x0*y2;
}

void get_input(){
	cin >> N >> x0 >> y0 >> x1 >> y1;
}

void solve(){
	for(int i=2; i<N; ++i){
		cin >> x2 >> y2;
		ans += ccw_area();
		x1 = x2; y1 = y2;
	}
	cout << fixed;
	cout.precision(1);
	cout << abs(ans/2);
}

int main(void){
	IO;
	get_input();
	solve();
	return 0;
}
