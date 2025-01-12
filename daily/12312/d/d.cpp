#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, t;
	bool ans = false;
	cin >> s >> t;
	int w = s.size() / t.size();
	int o = s.size() % t.size();
	for (int i = o; i < w; i++) {
		string made;
		for(int j = 0; j < t.size(); j++) {
			made.push_back(s[i + j * w]);
		}
		if (made == t)
			ans = true;
		cout << made << endl;
	}
	if (t.size() == 1)
		ans = false;
	if (ans)
		cout << "Yes";
	else
		cout << "No";
}
