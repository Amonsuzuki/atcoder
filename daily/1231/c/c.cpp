#include <bits/stdc++.h>
using namespace std;

struct top {
	int num = 0;
	int index = 0;
};

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	top fst;
	top snd;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (fst.num < a[i]) {
			top tmp = fst;
			fst.num = a[i];
			fst.index = i;
			snd = tmp;
		}
		else if (snd.num < a[i]) {
			snd.num = a[i];
			snd.index = i;
			ans = i;
		}
		//cout << "fst " << fst.num << " _ " << fst.index << " snd " << snd.num << " _ " << snd.index << endl;
	}
	cout << snd.index + 1;
}
