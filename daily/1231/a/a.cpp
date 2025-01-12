#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, d, ans = 0;
	cin >> a >> b >> c >> d;

	if (a == b) {
		ans++;
		if (c == d)
			ans++;
	}
	else if (a == c) {
		ans++;
		if (b == d)
			ans++;
	}
	else if (a == d) {
		ans++;
		if (b == c)
			ans++;
	}
	else if (b == c)
		ans++;
	else if (b == d)
		ans++;
	else if (c == d)
		ans++;
	cout << ans;
}
