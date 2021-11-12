//link to the problem: https://cses.fi/problemset/task/1634
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
 
void print(const vvi v);
 
void solve() {
	int n, amount;
	cin >> n >> amount;
	vi coins(n);
	for (auto &coin : coins) cin >> coin;
	vvi dp(n + 1, vi (amount + 1));
	rep (i, 0, dp.size()) {
		rep (j, 0, dp[0].size()) {
			if (i == 0) {
				dp[i][j] = INT_MAX - 5;
			}
			else if (j == 0) {
				dp[i][j] = 0;
			}
			else {
				if (j < coins[i - 1]) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
				}
			}
		}
	}
	int ans = dp[dp.size() - 1][dp[0].size() - 1];
	// print(dp);
	if (ans == INT_MAX - 5) cout << -1 << nline;
	else cout << ans << nline;
}
 
void print(const vvi v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[0].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << nline;
	}
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
