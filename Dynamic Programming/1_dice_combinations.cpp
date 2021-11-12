// link to the problem: https://cses.fi/problemset/task/1633
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
#define rep(i, start, end) for(int i = start; i < end; i++)
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define all(x) (x).begin(), (x).end()
#define m 1000000007
 
void solve() {
    int n;
    cin >> n;
    vi dp(n + 1, 0);
    int sum = 0;
    rep (i, 1, 7) {
        dp[i] = sum + 1;
        sum += dp[i];
    }
    rep (i, 7, n + 1) {
        int j = i - 1;
        sum = 0;
        int cnt = 6;
        while (cnt--) {
            sum = (sum + dp[j]) % m;
            j--;
        }
        dp[i] = sum;
    }
    cout << dp[n] << nline;
}
 
void FIO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
signed main()
{
    fast;
    FIO();
    int T;
    T = 1;
    //cin >> T;
    while (T--)
        solve();
    return 0;
}
