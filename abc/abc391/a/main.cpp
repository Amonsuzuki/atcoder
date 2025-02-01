#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s;
	cin >> s;
	if (s == "N") {
		cout << "S" << endl;
		return (0);
	}
	if (s == "E") {
		cout << "W" << endl;
		return (0);
	}
	if (s == "W") {
		cout << "E" << endl;
		return (0);
	}
	if (s == "S") {
		cout << "N" << endl;
		return (0);
	}
	if (s == "NE") {
		cout << "SW" << endl;
		return (0);
	}
	if (s == "NW") {
		cout << "SE" << endl;
		return (0);
	}
	if (s == "SE") {
		cout << "NW" << endl;
		return (0);
	}
	if (s == "SW") {
		cout << "NE" << endl;
		return (0);
	}
}
