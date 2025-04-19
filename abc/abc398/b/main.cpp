#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> a(8);
	cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6] >> a[7];
	vector<int> ans(14, 0);
	for (int i=1; i<8; i++)
		ans[a[i]]++;
	int flg3=0, flg2=0, skip;
	for (int i=0; i<14; i++) {
		if (ans[i] >= 3) {
			flg3 = 1;
			skip = i;
			break;
		}
	}
	if (flg3) {
		for (int i=0; i<14; i++) {
			if (i != skip) {
				if (ans[i] >= 2) {
					cout << "Yes";
					flg2 = 1;
					break;
				}
			}
		}
	}
	if (!flg2 || !flg3)
		cout << "No";
	cout << endl;
}

