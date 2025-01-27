#include <bits/stdc++.h>
using namespace std;


int validatelength(vector<vector<char>> area, int H, int W, int K, int di, int dj) {
	int steps = 0;
	for (int i = 0; i < H, i++) {
		for (int j = 0; j < W, j++) {
			if (area[di][dj] == ".")
				steps++;
			//wrong algorithm, it should be 3 candidates to move

int countPath(vector<vector<char>> area, int H, int W, int K){
	int pathcount = 0;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (validatelength(area, H, W, K, i, j))
				pathcount++;
		}
	}
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
