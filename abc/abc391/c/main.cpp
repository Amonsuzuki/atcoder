#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct query{
	int s0 = 0;
	int s1 = 0;
	int s2 = 0;
};


int main() {
	int n, q;
	cin >> n >> q;
	vector<query> s(q);
	vector<int> place(n);
	for (int i=0; i<n; i++)
		place[i] = i + 1;
	vector<int> num(n, 1);
	int ans = 0;
	for (int i=0; i<q; i++) {
		cin >> s[i].s0;
		if (s[i].s0 == 1) {
			cin >> s[i].s1 >> s[i].s2;

			num[place[s[i].s1 - 1] - 1]--;
			if (num[place[s[i].s1 - 1] - 1] == 1)
				ans--;

			place[s[i].s1 - 1] = s[i].s2;

			num[place[s[i].s1 - 1] - 1]++;
			if (num[place[s[i].s1 - 1] - 1] == 2)
				ans++;
/*
			cout << "----" << endl;
			for (int i=0; i<n; i++) {
			cout << place[i] << ' ' << num[i] << endl;
			}*/
		}
		if (s[i].s0 == 2)
			cout << ans << endl;
	}/*
	for (int i=0; i<n; i++)
		cout << place[i] << ' ' << num[i] << endl;*/
}
