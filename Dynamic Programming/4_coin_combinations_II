//link to the problem: https://cses.fi/problemset/task/1636
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
#define input(v) for (auto &x : v) cin >> x;
#define m 1000000007;
 
void solve() {
	int n, amount;
	cin >> n >> amount;
	vi coins(n);
	input(coins);
	vi dp(amount + 1, 0);
	dp[0] = 1;
	for (auto coin : coins) {
		for (int i = 1; i < dp.size(); i++) {
			if (i >= coin) {
				dp[i] = (dp[i] + dp[i - coin]) % m;
			}
		}
	}
	cout << dp[amount] << nline;
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
