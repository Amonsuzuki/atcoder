#include <bits/stdc++.h>
using namespace std;

int main () {
	int x, y, z;
	cin >> x >> y >> z;
	if (x < 0) {
		x = -x;
		y = -y;
		z = -z;
	}
	if (!(0 < y && y < x))
		cout << x;
	else
		if (0 < z && z < y)
			cout << x;
		else if (z < 0)
				cout << x + (z)*-2;
		else
			cout << -1;
}
