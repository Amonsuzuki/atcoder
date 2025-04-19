#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	vector<int> s_i, t_i;
	for (long unsigned int i = 0; i < s.size(); i++)
		s_i.push_back((char)s[i] - 'a');
	for (long unsigned int i = 0; i < t.size(); i++)
		t_i.push_back((char)t[i] - 'a');

	for (long unsigned int i = 1; i < s_i.size(); i++) {
		int key = s_i[i];
		int j = i - 1;
		while (j >= 0 && s_i[j] > key) {
			s_i[j + 1] = s_i[j];
			j--;
		}
		s_i[j + 1] = key;
	}/*
	for (long unsigned int i = 0; i < s_i.size(); i++)
		cout << s_i[i] << ' ';
	cout << endl;*/

//reverse

	for (long unsigned int i = 1; i < t_i.size(); i++) {
		int key = t_i[i];
		int j = i - 1;
		while (j >= 0 && t_i[j] < key) {
			t_i[j + 1] = t_i[j];
			j--;
		}
		t_i[j + 1] = key;
	}/*
	for (long unsigned int i = 0; i < t_i.size(); i++)
		cout << t_i[i] << ' ';
	cout << endl;*/
	
	int flg = 0;
	int eqflg = 0;
	long unsigned int size = s_i.size();
	if (s_i.size() == t_i.size())
		eqflg = -1;
	if (s_i.size() > t_i.size()) {
		size = t_i.size();
		eqflg = 1;
	}
	for (long unsigned int i = 0; i < size; i++) {
		if (s_i[i] < t_i[i]) {
			flg = 1;
			break;
		}
		if (s_i[i] > t_i[i]) {
			flg = -1;
			break;
		}
	}
	if (flg == 0) {
		if (eqflg == 1)
			flg = -1;
		else if (eqflg != -1)
			flg = 1;
	}
	if (flg == 1)
		cout << "Yes" << endl;
	if (flg == -1 || flg == 0)
		cout << "No" << endl;

}
