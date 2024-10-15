#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int max_n = 11;
int a[max_n][max_n], visited[max_n][max_n];
int n;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int mini = 9876;
int cost = 0;

vector<pair<int,int>>v;
int check(vector<pair<int, int>>b) {
	cost = 0;
	fill(&visited[0][0], &visited[0][0] + max_n*max_n, 0);
	for (auto i : b) {
		if (visited[i.first][i.second] == 1)return -1;
		visited[i.first][i.second] = 1;
		cost += a[i.first][i.second];
		for (int j = 0; j < 4; j++) {
			int ny = i.first + dy[j];
			int nx = i.second + dx[j];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx] != 0) return -1;
			visited[ny][nx] = 1;
			cost += a[ny][nx];

		}
	}
	return cost;
}
void comb(int start, vector<pair<int, int>>b) {
	if (b.size() == 3) {
		if (check(b) != -1) {
			mini = min(cost, mini);
		}
		return;
	}
	for (int i = start + 1; i < v.size(); i++) {
		b.push_back(v[i]);
		comb(i, b);
		b.pop_back();
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			v.push_back({ i,j });
		}
	}
	vector<pair<int, int>>b;
	comb(-1, b);

	cout << mini;

}