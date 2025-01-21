#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s;
	cin >> s;

	if (s.size() % 2 != 0) {
		cout << "No";
		return (0);
	}
	set<char> charSet;
	for (size_t i=0; i<s.size(); i += 2) {
		if (s[i] != s[i+1]) {
			cout << "No";
			return (0);
		}
		else if (charSet.find(s[i]) != charSet.end()) {
			cout << "No";
			return (0);
		}
		charSet.insert(s[i]);
	}
	cout << "Yes";
}

