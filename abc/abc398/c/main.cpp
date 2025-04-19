#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, vector<int>> d;

    // 入力とマッピング
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        d[A[i]].push_back(i);
    }

    // 値が大きい順に見るため reverse iterator
    for (auto it = d.rbegin(); it != d.rend(); ++it) {
        if (it->second.size() == 1) {
            // 1-based index で出力
            cout << it->second[0] + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}

