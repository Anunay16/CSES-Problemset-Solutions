// link to the problem: https://cses.fi/problemset/task/1145
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
#define print(v) for (auto &x : v) cout << x << " ";
#define mod 1000000007
 
void solve() {
    int n;
    cin >> n;
    vi arr(n);
    input(arr);
    vi ans;
    ans.pb(arr[0]);
    rep (i, 1, n) {
        if (ans.back() < arr[i]) {
            ans.pb(arr[i]);
        }
        else {
            int idx = lower_bound(all(ans), arr[i]) - ans.begin();
            ans[idx] = arr[i];
        }
    }
    cout << ans.size() << nline;
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
