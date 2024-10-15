#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

const int max_n = 10;
char input[max_n];
bool visited[10];
int n;
vector<int> v;
long long maxi = -9999999999;
long long mini = 9999999999;

bool result(int a, int b, char c) {
    switch (c) {
    case '>':
        return a > b;
    case '<':
        return a < b;
    }
    return false; // 기본적으로 false 반환
}

void go(int index) {
    if (v.size() == n + 1) {
        string ret = "";
        for (int i = 0; i <= n; i++) {
            ret += to_string(v[i]);
        }
        long long num = stoll(ret);
        mini = min(mini, num);
        maxi = max(maxi, num);
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (visited[i]) continue;
        if (v.empty() || result(v.back(), i, input[index])) {
            visited[i] = true;
            v.push_back(i);
            go(index + 1);
            v.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    for (int i = 0; i < 10; i++) {
        visited[i] = true;
        v.push_back(i);
        go(0);
        v.pop_back();
        visited[i] = false;
    }
    string maximum = to_string(maxi);
    string minimum = to_string(mini);

    if (maximum.size() != n + 1)maximum = "0" + maximum;
    if (minimum.size() != n + 1)minimum = "0" + minimum;

    cout << maximum << endl;
    cout << minimum << endl;
    return 0;
}
