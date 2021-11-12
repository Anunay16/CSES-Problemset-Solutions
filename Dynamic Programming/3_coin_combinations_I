// link to the problem: https://cses.fi/problemset/task/1635
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
#define m 1000000007
vi coins, dp;
 
int solve(int amount) {
	if (amount < 0) {
		return 0;
	}
	int &val = dp[amount];
	if (val != -1) {
		return val;
	}
	if (amount == 0) {
		return val = 1;
	}
	int ans = 0;
	for (auto coin: coins) {
		ans = (ans + solve(amount - coin)) % m;
	}
	return val = ans;
}
 
void solve() {
	int n, amount;
	cin >> n >> amount;
	coins.resize(n);
	dp.resize(amount + 1, -1);
	for (auto &x : coins) cin >> x;
	int ans = solve(amount);
	cout << ans << nline;
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
