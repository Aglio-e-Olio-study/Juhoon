#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
const int max_n = 202;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int a[max_n][max_n], visited[max_n][max_n];
int r, c, n;
string temp;
void exp(int y,int x) {
	a[y][x] = -1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		a[ny][nx] = -1;
	}
}
int main() {
	cin >> r >> c >> n;
	for (int i = 0; i < r; i++) {
		cin >> temp;
		for (int j = 0; j < c; j++) {
			if (temp[j] == '.')a[i][j] = -1;
			else a[i][j] = 2;	
		}
	}

	for (int time = 1; time < n; time++) {
		if (time % 2 == 0) { //터질때
			vector<pair<int,int>>v;
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (a[i][j] == 0)v.push_back({ i,j });
					a[i][j]--;
					if (a[i][j] == 0)v.push_back({ i,j });
				}
			}
			for (auto i : v) {
				exp(i.first, i.second);
			}
		}
		else {//채울때
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {

					if (a[i][j] < 0) {
						a[i][j] = 2;
					}
					else {
						if (a[i][j] == 0)continue;
						a[i][j]--;
					}
				}
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j] >= 0)cout << 'O';
			else cout << '.';
		}cout << endl;
	}
	
}