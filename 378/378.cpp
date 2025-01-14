#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, Q;

	cin >> N;
	vector <int> q(N), r(N);
	for (int i = 0; i < N; i++) {
		cin >> q[i] >> r[i];
		}
	cin >> Q;
	vector <int> t(Q), d(Q);
	for (int i = 0; i < Q; i++) {
		cin >> t[i] >> d[i];
		}

	int type = 0;
	int answer = 0;
	for (int i = 0; i < Q; i++) {
		type = t[i] - 1;
		if ((r[type] - d[i] % q[type]) >= 0)
			answer = d[i] + (r[type] - d[i] % q[type]);
		else
			answer = (d[i] / q[type] + 1) * q[type] + r[type];
		cout << answer << endl;
		}
}
