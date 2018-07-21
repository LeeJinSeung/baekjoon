#include <iostream>
#include <cmath>
using namespace std;



int main() {
	cin.tie(NULL);
	double d, v, h;
	double rv, rh;
	cin >> d >> v >> h;
	rv = floor(d * v / sqrt(v * v + h * h));
	rh = floor(d * h / sqrt(v * v + h * h));
	cout << rv << " " << rh;
	return 0;
}
