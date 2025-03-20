#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)

struct s{
	ll position = 0;
	ll right_value = 0;
};

int main() {
	ll n, q;
	cin >> n >> q;
	vector<ll> x(q);
	for (ll i=0; i<q; i++) {
		cin >> x[i];
		x[i]--;
	}
	vector<s> ans(n);
	for (ll i=0; i<n; i++) {
		ans[i].position = i;
		if (i != n - 1)
			ans[i].right_value = i + 1;
		else
			ans[i].right_value = i - 1;//-1 シンプルに間違ってる
	}
	vector<ll> output(n);
	for (ll i=0; i<n; i++)
		output[i] = i + 1;
	ll current = n - 2;
	ll current_minus = n -3;

	for (ll e=0; e<n; e++) {
		cout << e;
		if (e != n - 1)
			cout << ' ';
	}
	cout << "value" << endl;
	for (ll e=0; e<n; e++) {
		cout << ans[e].position;
		if (e != n - 1)
			cout << ' ';
	}
	cout << "position" << endl;
	for (ll e=0; e<n; e++) {
		cout << ans[e].right_value;
		if (e != n - 1)
			cout << ' ';
	}
	cout << "right_value" << endl;
	cout << current;
	cout << "current" << endl;
	for (ll e=0; e<n; e++) {
		cout << output[e];
		if (e != n - 1)
			cout << ' ';
	}
	cout << "output" << endl;
	cout << endl;

	for (ll i=0; i<q; i++) {
		if (ans[x[i]].position != n - 1) {
			ll right1 = ans[x[i]].right_value;
			ll right2 = ans[right1].right_value;
			if (ans[x[i]].position == n - 2)
				current = ans[x[i]].right_value;
			if (ans[x[i]].position == n - 3) {
				current = x[i];
				current_minus = ans[x[i]].right_value;
			}
			if (ans[x[i]].position == n - 4)
				current_minus = x[i];

			ans[x[i]].position++;
			ans[right1].position--;
			ans[x[i]].right_value = right2;
			ans[right1].right_value = x[i];

			output[ans[x[i]].position] = x[i] + 1;
			output[ans[right1].position] = right1 + 1;
			//cout << right1 << ' ' << right2 << endl;
		}
		else {
			ans[x[i]].position--;
			ans[current].position++;
			ans[x[i]].right_value = current;
			ans[current].right_value = x[i];//-1
			ans[current_minus].right_value = x[i];

			output[ans[x[i]].position] = x[i] + 1;
			output[ans[current].position] = current + 1;
			current = x[i];
		}

		for (ll e=0; e<n; e++) {
			cout << e;
			if (e != n - 1)
				cout << ' ';
		}
		cout << "value" << endl;
		for (ll e=0; e<n; e++) {
			cout << ans[e].position;
			if (e != n - 1)
				cout << ' ';
		}
		cout << "position" << endl;
		for (ll e=0; e<n; e++) {
			cout << ans[e].right_value;
			if (e != n - 1)
				cout << ' ';
		}
		cout << "right_value" << endl;
		cout << current;
		cout << "current" << endl;
		cout << current_minus;
		cout << "current_minus" << endl;
		for (ll e=0; e<n; e++) {
			cout << output[e];
			if (e != n - 1)
				cout << ' ';
		}
		cout << "output" << endl;
		cout << endl;

	}
	for (ll i=0; i<n; i++) {
		cout << output[i];
		if (i != n - 1)
			cout << ' ';
		else
			cout << endl;
	}
}
