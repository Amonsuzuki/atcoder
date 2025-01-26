#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s;
	cin >> s;
	int a=0, b=0, c=0;
	for (int i=0; i<3; i++) {
		if (s[i] == 'A')
			a++;
		if (s[i] == 'B')
			b++;
		if (s[i] == 'C')
			c++;
	}
	if (a == 1 && b == 1 && c == 1) {
		cout << "Yes" << endl;
		return (0);
	}
	cout << "No" << endl;
}
