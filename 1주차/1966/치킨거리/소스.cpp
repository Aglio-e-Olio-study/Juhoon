#include<iostream>
#include<queue>
#include<algorithm>
#include<tuple>
#include<vector>
#include<set>
using namespace std;
int temp;
int x, y;
// // // // // // //
int search(int a[]) {
	for (int i = 9; i >= 0; i--) {
		if (a[i] != 0)return i;
	}
	return 0;
}
int main() {
	int n,len,target;
	cin >> n;
	for (int i = 0; i < n; i++) {
		queue<pair<int, int>>q;
		int a[10] = { 0 };
		int maxi = -98765;
		cin >> len >> target;
		for (int j = 0; j < len; j++) {
			cin >> temp;
			a[temp]++;
			maxi = max(maxi, temp);
			q.push({ temp,j });
		}
		int cnt = 0;
		while (q.size()) {
			 tie(x,y)= q.front(); q.pop();
			 if (maxi > x)q.push({ x,y });
			 else {
				 cnt++;
				 if (y == target) break;
				 a[x]--;
				 if (a[x] == 0)maxi = search(a);
			 }
		}
		cout << cnt<<endl;


	}
}

