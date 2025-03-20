#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, Q;
	cin >> N >> Q;
	vector<int> x(Q);
	for (int i=0; i<Q; i++)
		cin >> x[i];
	vector<int> val(N + 1), pos(N + 1);
	for (int i=0; i<N+1; i++) {
		val[i] = i;
		pos[i] = i;
	}
	for (int i=0; i<Q; i++) {
		int pl = pos[x[i]];
		int pr = pl;
		if (pl != N)
			pr++;
		else
			pr--;
		int vl = val[pl];
		int vr = val[pr];
		int tmpv = val[pl];
		val[pl] = val[pr];
		val[pr] = tmpv;
		int tmpp = pos[vl];
		pos[vl] = pos[vr];
		pos[vr] = tmpp;
		/*
		cout << "val:\n";
		for (int i=1; i<N+1; i++) {
			if (i != 1)
				cout << ' ';
			cout << val[i];
		}
		cout << endl;
		cout << "pos:\n";
		for (int i=1; i<N+1; i++) {
			if (i != 1)
				cout << ' ';
			cout << pos[i];
		}
		cout << endl;
		cout << endl;*/
	}
	for (int i=1; i<N+1; i++) {
		if (i != 1)
			cout << ' ';
		cout << val[i];
	}
	cout << endl;
}

