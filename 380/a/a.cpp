#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s;
	cin >> s;
	if (s.size() != 6) {
		cout << "No";
		return (0);
	}
	int one=0, two=0, three=0;
	for(int i=0; i<6; i++) {
		if (s[i] == '1')
			one++;
		if (s[i] == '2')
			two++;
		if (s[i] == '3')
			three++;
	}
	if (one != 1) {
		cout << "No";
		return (0);
	}
	if (two != 2) {
		cout << "No";
		return (0);
	}
	if (three != 3) {
		cout << "No";
		return (0);
	}
	cout << "Yes";
}


