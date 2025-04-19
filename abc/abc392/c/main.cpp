#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct type{
	int a;
	int b;
	int d;
	int count = 2;
};


int main() {
	int n;
	cin >> n;
	vector<type> c(n);
	for (int i=0; i<n; i++)
		cin >> c[i].a;
	for (int i=0; i<n; i++) {
		cin >> c[i].b;
		c[i].d = i + 1;
	}
	sort(c.begin(), c.end(), [](const type &x, const type &y ) { return x.b < y.b; });/*
	for (int i=0; i<n; i++)
		cout << c[i].a << ' ' << c[i].b << ' ' << c[i].d << endl;*/
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (c[j].d == c[i].a) {
				cout << c[j].b;/*
				c[j].count--;
				if (!c[j].count)
					c.erase(c.begin() + j);*/
				break;
			}
		}/*
		c[i].count--;
		if (!c[i].count)
			c.erase(c.begin() + i);*/
		if (i != n - 1)
			cout << ' ';
	}
	cout << endl;
}
