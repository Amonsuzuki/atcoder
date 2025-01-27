#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    bool out = false;
    cin >> n >> m;
    vector<int> x(m), y(m);
    vector<char> c(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i] >> c[i];
        x[i]--;
        y[i]--;
    }
    vector<bool> rowBlocked(n, false), colBlocked(n, false);
    for (int i = 0; i < m && !out; i++) {
        if (c[i] == 'B') {
            if (x[i] == 0) {
                for (int j = 0; j <= y[i]; j++) {
                    if (colBlocked[j]) {
                        out = true;
                        break;
                    }
                    colBlocked[j] = true;
                }
            } else if (y[i] == 0) {
                for (int j = 0; j <= x[i]; j++) {
                    if (rowBlocked[j]) {
                        out = true;
                        break;
                    }
                    rowBlocked[j] = true;
                }
            } else {
                for (int k = 0; k <= x[i] && !out; k++) {
                    if (rowBlocked[k]) {
                        out = true;
                        break;
                    }
                    for (int l = 0; l <= y[i]; l++) {
                        if (colBlocked[l]) {
                            out = true;
                            break;
                        }
                    }
                }
            }
        } else if (c[i] == 'W') {
            rowBlocked[x[i]] = true;
            colBlocked[y[i]] = true;
        }
    }

    if (!out)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}

