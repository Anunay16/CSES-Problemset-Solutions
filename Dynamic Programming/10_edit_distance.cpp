// link to the problems: https://cses.fi/problemset/task/1639
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
	string word1, word2;
    cin >> word1 >> word2;
	int n = word1.length();
	int m = word2.length();
	vvi dp(n + 1, vi (m + 1, 0));
	for (int i = 0; i < dp.size(); i++) {
		for (int j = 0; j < dp[0].size(); j++) {
			if (i == 0) {
				dp[i][j] = j;
			}
			else if (j == 0) {
				dp[i][j] = i;
			}
			else {
				if (word1[i - 1] == word2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
				}
			}
		}
	}
	cout << dp[n][m] << nline;
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
