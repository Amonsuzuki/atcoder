#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; i++)
		cin >> a[i];
	set<int> s;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			int newone = a[i] + a[j];
			for (int p=0; p<n; p++) {
				if (p != i && p != j)
					newone ^= a[p];
			}
			if (s.find(newone) == s.end())
				s.insert(newone);
		}
	}
	cout << s.size() << endl;
	for (int x : s)
		cout << x << ' ';
	cout << endl;
}
