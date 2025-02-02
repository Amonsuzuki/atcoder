#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct typeij{
	int i;
	int j;
	int total;
};


int main() {
	int h, w, d;
	cin >> h >> w >> d;
	vector<string> s(h);
	for (int i=0; i<h; i++)
		cin >> s[i];
	set<typeij> H;
	int ans = 0;
	for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++) {
			if (s[i][j] == 'H')
				H.insert({i, j, i+j});
				ans++;
		}
	}
	for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++) {
			if (s[i][j] == '.')

