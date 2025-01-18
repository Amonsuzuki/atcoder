#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)

int main() {
	ll q;
	cin >> q;
	vector<ll> type(q);
	vector<ll> length(q);
	for (ll i=0; i<q; i++) {
		cin >> type[i];
		if (type[i] != 2)
			cin >> length[i];
	}
	ll currentMinus = 0;
	ll currentMinusCount = 0;
	ll currentOneCount = -1;
	vector<ll> set;
	ll p = 0;
	for (ll i=0; i<q; i++) {
		if (type[i] == 1) {
			if (i == 0)
				set.emplace_back(length[i]);
			else
				set.emplace_back(set[currentOneCount] + length[i]);
			p++;
			currentOneCount++;
		}
		if (type[i] == 2) {
			currentMinus = set[currentMinusCount];
			currentMinusCount++;
		}
		if (type[i] == 3) {
			if (length[i] == 1)
				cout << 0 << endl;
			else
				cout << set[length[i] - 2 + currentMinusCount] - currentMinus << endl;
		}/*
		for (ll j=0; j<p; j++) {
			cout << "set " << set[j] << ", ";
		}
		cout << "Minus " << currentMinus << ", " << currentMinusCount << endl;
		*/
	}
}




