#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	vector<string> t(m);
	for (int i=0; i<n; i++)
		cin >> s[i];
	for (int i=0; i<m; i++)
		cin >> t[i];
	int ansx=0, ansy=0;
	for (int i=0; i<n; i++) {
		int findans = 0;
		for (int j=0; j<n; j++) {
			int flg = 1;
			if (s[i][j] == t[0][0]) {
				for (int x=0; x<m; x++) {
					for(int y=0; y<m; y++) {
						if (s[i+x][j+y] != t[x][y]) {
							flg = 0;
							break;
						}
						/*
						cout << "current ij:" << i << ' ' << j <<endl;
						cout << "current xy:" << x << ' ' << y <<endl;
						cout << "current ixjy:" << i+x << ' ' << j+y <<endl << endl;;
						*/
					}

					if (flg == 0) {
//						cout << "Kita!" << endl;
						break;
					}
				}
				if (flg == 1) {
					ansx = i + 1;
					ansy = j + 1;
					findans = 1;
					break;
				}
			}
		}
		if (findans)
			break;
	}
	cout << ansx << ' ' << ansy << endl;
}




