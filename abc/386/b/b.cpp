#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	int ans;

	cin >> s;
	ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '0')
			ans++;
		else {
			int zeronum = 1;
			for (int j = i + 1; j < s.size(); j++) {
				if (s[j] != '0')
					break;
				zeronum++;
			}
			ans += zeronum / 2;
			if (zeronum % 2 == 1)
				ans++;
			i = i + zeronum - 1;
		}
	}
	cout << ans;
	return (0);
}


