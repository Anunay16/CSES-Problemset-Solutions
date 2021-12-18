// link to the problem: https://cses.fi/problemset/task/1648

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
vector<ll> tree;
void buildTree(vector<ll>& arr, int n) {
    //3. first fill the main arr elements to the tree
    for (int i = 0; i < (int) arr.size(); i++) {
        tree[n + i] = arr[i];
    } 
    //4. now fill for n - 1 to 1th index backwards
    for (int i = n - 1; i >= 1; i--) {
        tree[i] = tree[2*i] + tree[2*i+1]; 
    }
}
 
//function to update values in segment tree
void update(int pos, int val, int n) {
    //first update the val at leaf
    tree[n + pos] = val;
 
    //then for every parent, update their values in logn time
    for (int i = (n + pos) / 2; i >= 1; i /= 2) {
        tree[i] = tree[2*i] + tree[2*i + 1];
    } 
}
 
//funtion to find the range values using segment tree
ll find(int node, int node_low, int node_high, int q_low, int q_high) {
    //base cases
    if (q_low <= node_low and node_high <= q_high) {
        return tree[node];
    }
    if (node_high < q_low or node_low > q_high) {
        return 0;
    }
 
    int last_in_left = ((node_low + node_high) >> 1);
    return find(2*node, node_low, last_in_left, q_low, q_high) + 
           find(2*node + 1, last_in_left + 1, node_high, q_low, q_high);
}
 
void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
 
    //build segment tree
    //1. change the n to the next power of 2
    while (__builtin_popcount(n) != 1) {
        n++;
    }
    //2. we make the tree array size of 2*nx
    tree.resize(2*n);
    buildTree(arr, n);
    //building finished in O(2n) time
 
    //now let's do the query
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos, val;
            cin >> pos >> val;
            pos--;
            update(pos, val, n);
        }
        else {
            int a, b;
            cin >> a >> b;
            a--; b--;
            cout << find(1, 0, n - 1, a, b) << "\n";
        }
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
