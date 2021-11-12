// link to the problem: https://cses.fi/problemset/task/1092
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
 
void print(vi const &v) {
	for (auto x : v) {
		cout << x << " ";
	}
	cout << nline;
}
 
void solve() {
	int n;
	cin >> n;
	int sum = (n * (n + 1)) / 2;
	if (sum % 2 == 1) {
		cout << "NO" << nline;
	}
	else {
		cout << "YES" << nline;
		vi partA, partB;
		sum /= 2LL;
		while (n) {
			if (sum >= n) {
				partA.pb(n);
				sum -= n;
			}
			else {
				partB.pb(n);
			}
			n--;
		}
		cout << partA.size() << nline;
		print(partA);
		cout << partB.size() << nline;
		print(partB);
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
