/* link: https://cses.fi/problemset/task/1083 */
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
 
void solve() {
	int n;
	cin >> n;
	int size = n - 1;
	unordered_set<int> s;
	rep (i, 0, size) {
		int x;
		cin >> x;
		s.insert(x);
	}
	for (int i = 1; i <= n; i++) {
		//if not present
		if (s.find(i) == s.end()) {
			cout << i;
			return;
		}
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
