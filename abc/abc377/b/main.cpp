#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	vector<string> s(8);
	for (int i=0; i<8; i++)
		cin >> s[i];
	set<int> si;
	set<int> sj;
	for (int i=0; i<8; i++) {
		for (int j=0; j<8; j++) {
			if (s[i][j] == '#') {
				if (si.find(i) == si.end())
					si.insert(i);
				if (sj.find(j) == sj.end())
					sj.insert(j);
			}
		}
	}
	cout << (8 - si.size()) * (8 - sj.size()) << endl;
}
