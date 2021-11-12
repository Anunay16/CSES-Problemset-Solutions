// link to the problem: https://cses.fi/problemset/task/1158
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
#define rep(i, start, end) for(int i = start; i < end; i++)
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define all(x) (x).begin(), (x).end()
#define input(v) for (auto &x: v) cin >> x
#define print(v) for (auto &x : v) cout << x << " "; nline
#define mod 1000000007
 
void solve() {
    int n, amount;
    cin >> n >> amount;
    vi prices(n), pages(n);
    input(prices);
    input(pages);
    vvi dp(n + 1, vi (amount + 1, 0));
    rep (i, 1, n + 1) {
        rep (j, 0, amount + 1) {
            //if excluded
            dp[i][j] = dp[i - 1][j];
 
            //now check if we can include, if yes then include and take the maximum
            if (j >= prices[i - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - prices[i - 1]] + pages[i - 1]);
            }
        }
    }
    cout << dp[n][amount] << nline;
}
 
//memoization method also looks correct, donno why it was showing TLE   
 
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
