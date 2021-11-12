/* link to the problem: https://cses.fi/problemset/task/1094 */
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
 
void solve() {
	int n;
	cin >> n;
	vi nums(n);
	for (auto &x : nums) cin >> x;
	int moves = 0;
	for (int i = 1; i < n; i++) {
		if (nums[i] < nums[i - 1]) {
			moves += nums[i - 1] - nums[i];
			//update the element in the array
			nums[i] = nums[i - 1];
		}
	}
	cout << moves << nline;
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
