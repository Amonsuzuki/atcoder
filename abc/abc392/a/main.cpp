#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a * b == c || a * c == b || b * c == a) {
		cout << "Yes" << endl;
		return (0);
	}
	cout << "No" << endl;
}
