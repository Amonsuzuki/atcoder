#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	vector<int> a(5);
	int count =0;
	int count2 = 0;
	for(int i=0; i<5; i++) {
		cin >> a[i];
		if (a[i] == i + 1)
			count++;
		if (i != 0 && a[i - 1] > a[i])
			count2++;
	}
	if (count == 3 && count2 == 1)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
