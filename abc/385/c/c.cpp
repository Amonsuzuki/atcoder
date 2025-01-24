#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, max, ans;
	cin >> n;
	vector<int> h(n);
	for(int i = 0; i < n; i++)
		cin >> h[i];
	vector dp(n, vector<int>(n, 1));
	ans = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; i + j < n; j++) {
			if (h[i] == h[i + j]) {
				dp[i + j][j] = dp[i][j] + 1;
				if (ans < dp[i + j][j])
					ans = dp[i + j][j];
			}
		}
	/*
	for(int a=0; a<n; a++) {
		for(int b=0; b<n; b++) 
			cout << dp[a][b] << ' ';
		cout << '\n';
	}
	cout << '\n';*/
	}
	cout << ans;
}
