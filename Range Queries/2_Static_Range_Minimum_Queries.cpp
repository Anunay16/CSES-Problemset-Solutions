//link to the problem: https://cses.fi/problemset/task/1647

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9 + 5;
 
vector<ll> tree;
void buildTree(vector<ll>& arr, int n) {
    for (int i = 0; i < n; i++) {
        tree[n + i] = arr[i];
    }
    for (int i = n - 1; i >= 1; i--) {
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }
}
 
ll find(int node, int node_low, int node_high, int q_low, int q_high) {
    if (q_low <= node_low and node_high <= q_high) {
        return tree[node];
    }
    if (node_high < q_low or q_high < node_low) {
        return inf;
    }
    int last_in_left = ((node_low + node_high) >> 1);
    ll left_min = find(node * 2, node_low, last_in_left, q_low, q_high);
    ll right_min = find(node * 2 + 1, last_in_left + 1, node_high, q_low, q_high);
    return min(left_min, right_min);
}
 
void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (auto &x: arr) cin >> x;
 
    while (__builtin_popcount(n) != 1) {
        arr.push_back(inf);
        n++;
    }
    tree.resize(2 * n);
    buildTree(arr, n);
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << find(1, 0, n - 1, l, r) << "\n";
    }
}
 
void FIO()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
 
int main()
{
    FIO();
    solve();
    return 0;
}
