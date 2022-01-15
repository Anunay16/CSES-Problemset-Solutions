// link to the problem: https://cses.fi/problemset/task/1674/

// DP on trees....

#include <bits/stdc++.h>
using namespace std;

const int SIZE = 2 * 1e5;
vector<int> tree[SIZE];

int dfs(int cur, int parent, vector<int>& subordinates) {
    int subs = 0;
    for (auto& nbr: tree[cur]) {
        if (nbr != parent) {
            subs += 1 + dfs(nbr, cur, subordinates);
        }
    }
    return subordinates[cur] = subs;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        tree[i].push_back(x);
        tree[x].push_back(i);
    }
    vector<int> subordinates(n + 1);
    int totalSubsOfRoot = dfs(1, 0, subordinates);
    for (int i = 1; i < n + 1; i++) {
        cout << subordinates[i] << " ";
    }
    cout << "\n";
}

void FIO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

int main() {
    FIO();
    solve();
    return 0;
}
