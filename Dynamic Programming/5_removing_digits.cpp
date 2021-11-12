// link to the problem: https://cses.fi/problemset/task/1637

// 1. DP Solution:

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
	int n;
	cin >> n;
	vi dp(n + 1, INT_MAX - 2);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (char ch: to_string(i)) {
			dp[i] = min(dp[i], dp[i - (ch - '0')] + 1);
		}
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
 
/*
dp[x] = minimum number of operations to go from x to zero.
 
When considering a number x, for each digit in the decimal representation of x, we can try to remove it. The transition is therefore: dp[x] = mind∈digits(x) dp[x-d].
 
We initialize dp[0] = 0.
 
The complexity is O(n).
 
Note that the greedy solution of always subtracting the maximum digit is also correct, but we are practicing DP :)
*/


//2. Greedy solution:

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
 
int findMaxDig(int n) {
	int maxDig = -1;
	while (n) {
		int lastDig = n % 10;
		n /= 10;
		maxDig = max(maxDig, lastDig);
	}
	return maxDig;
}
 
void solve() {
	int n;
	cin >> n;
	int ans = 0;
	while (n) {
		int maxDig = findMaxDig(n);
		n -= maxDig;
		ans++;
	}
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
