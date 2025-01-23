#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s;
	cin >> s;
	int count = 0;
	for (size_t i=1; i<s.size(); i++) {
		if (s[i] == '-')
			count++;
		else {
			cout << count; 
			if (i != s.size() - 1)
				cout << ' ';
			count = 0;
		}
	}
}
