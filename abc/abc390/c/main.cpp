#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	for (int i=0; i<h; i++) 
		cin >> s[i];
	//fiind top
	int top = 0;
	for (int i=0; i<h; i++) {
		int flg=0;
		for (int j=0; j<w; j++) {
			if (s[i][j] == '#') {
				top = i;
				flg = 1;
				break;
			}
			//cout << s[i][j] << endl;
		}
		if (flg)
			break;
	}
	int bottom = 0;
	for (int i=0; i<h; i++) {
		int flg=0;
		for (int j=0; j<w; j++) {
			if (s[h - i - 1][j] == '#') {
				bottom = h - i - 1;
				flg = 1;
				break;
			}
		}
		if (flg)
			break;
	}
	int left = 0;
	for (int j=0; j<w; j++) {
		int flg=0;
		for (int i=0; i<h; i++) {
			if (s[i][j] == '#') {
				left = j;
				flg = 1;
				break;
			}
		}
		if (flg)
			break;
	}
	int right = 0;
	for (int j=0; j<w; j++) {
		int flg=0;
		for (int i=0; i<h; i++) {
			if (s[i][w - j - 1] == '#') {
				right = w - j - 1;
				flg = 1;
				break;
			}
		}
		if (flg)
			break;
	}
	//cout << top << bottom << left << right << endl;
	for (int i=top; i<=bottom; i++) {
		for (int j=left; j<=right; j++) {
			if (s[i][j] == '.') {
				cout << "No" << endl;
				return (0);
			}
		}
	}
	cout << "Yes" << endl;
	
}
