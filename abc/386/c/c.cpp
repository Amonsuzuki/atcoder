#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	string s, t;

	cin >> k;
	cin >> s;
	cin >> t;

	if (s.size() == t.size()) {
		int count = 0;
		for (size_t i = 0; i < s.size(); i++) {
			if (s[i] != t[i])
				count++;
			if (count == 2)
				break;
		}
		if (count < 2)
			cout << "Yes";
		else
			cout << "No";
	}
	else if (s.size() == t.size() + 1) {
		int initial = 0;
		size_t charnum = 0;
		for (size_t i = 0; i < s.size(); i++) {
			size_t j = i + initial;
			if (s[j] == t[i])
				charnum++;
			else if (s[j] != t[i])
				initial = 1;
		}
		if (t.size() == charnum)
			cout << "Yes";
		else
			cout << "No";
	}
	else if (s.size() + 1 == t.size()) {
		int initial = 0;
		size_t charnum = 0;
		for (size_t i = 0; i < s.size() + 1; i++) {
			size_t j = i + initial;
			if (t[j] == s[i])
				charnum++;
			else if (t[j] != s[i])
				initial = 1;
		}
		if (s.size() == charnum)
			cout << "Yes";
		else
			cout << "No";
	}
	else
		cout << "No";
	return (0);
}





