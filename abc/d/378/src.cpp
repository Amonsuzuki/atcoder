#include <bits/stdc++.h>
using namespace std;


int countPath(vector<vector<char>> area, int H, int W, int K){
};



int main () {
	int H, W, K;
	cin >> H >> W >> K;
	vector<vector<char>> area(H, vector<char> (W));

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++){
			cin >> area[i][j];
			//cout << area[i][j];
		}
		//cout << endl;
	}
	countPath(area, H, W, K);
	
	}
