#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (int i=0; i<m; i++)
		cin >> a[i];
	vector<int> ans;
	for (int i=0; i<n; i++) {
		int flg = 0;
		for (int j = 0; j<m; j++) {
			if (i+1 == a[j]) {
				flg = 1;
				break;
			}
		}
		if (!flg) {
			ans.insert(ans.end(), i + 1);
		}
	}
	cout << ans.size() << endl;
	for (size_t i=0; i<ans.size(); i++) {
		cout << ans[i];
		if (i != ans.size() - 1)
			cout << ' ';
	}
	cout << endl;
}

