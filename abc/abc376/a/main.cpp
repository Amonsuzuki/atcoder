#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, c;
	cin >> n >> c;
	vector<int> s(n);
	int count=1;
	int j=0;
	for(int i=0; i<n; i++) {
		cin >> s[i];
		if (i != 0 && (s[i] - s[j]) >= c) {
			count++;
			j = i;
		}
	}
	cout << count << endl;
}
