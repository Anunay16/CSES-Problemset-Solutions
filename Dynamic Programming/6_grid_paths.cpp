// link to the problem: https://cses.fi/problemset/task/1638
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
 
vector<vector<char>> grid;
vvi visited, dp;
 
int dfs(int row, int col) {
	if (row >= grid.size() or col >= grid[0].size() or visited[row][col] or grid[row][col] == '*') {
		return 0;
	}
	int &val = dp[row][col];
	if (val != -1) {
		return val;
	}
	if (row == grid.size() - 1 and col == grid[0].size() - 1) {
		return val = 1;
	}
	visited[row][col] = 1;
	int paths = (dfs(row, col + 1) + dfs(row + 1, col)) % mod;
	visited[row][col] = 0;
	return val = paths;
}
 
void solve() {
	int n;
	cin >> n;
	grid.resize(n, vector<char>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}
	visited.resize(n, vi (n, 0));
	dp.resize(n, vi (n, -1));
	int ans = dfs(0, 0);
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
