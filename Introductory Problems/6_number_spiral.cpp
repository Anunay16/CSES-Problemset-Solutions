//link to the problem: https://cses.fi/problemset/task/1071
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
#define sizee 6
 
vvi arr;
 
void tableFill() {
	arr[0][0] = 1;
	for (int j = 1; j < sizee; j++) {
		if (j % 2 == 1) {
			int start = arr[0][j - 1] + 1;
			for (int i = 0; i <= j; i++) {
				arr[i][j] = start;
				start++;
			}
			for (int k = j - 1; k >= 0; k--) {
				arr[j][k] = start;
				start++;
			}
		}
		else {
			int start = arr[j - 1][0] + 1;
			for (int k = 0; k <= j; k++) {
				arr[j][k] = start;
				start++;
			}
			for (int i = j - 1; i >= 0; i--) {
				arr[i][j] = start;
				start++;
			}
		}
	}
}
 
void print(vvi const &arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << nline;
	}
}
 
void solve() {
	int row, col;
	cin >> row >> col;
	if (row > col) {
		if (row % 2 == 0) {
			int start = row * row;
			cout << start - col + 1 << nline;
		}
		else {
			int start = (row - 1) * (row - 1) + 1;
			cout << start + col - 1 << nline;
		}
	}
	else {
		if (col % 2 == 0) {
			int start = (col - 1) * (col - 1) + 1;
			cout << start + row - 1 << nline;
		}
		else {
			int start = col * col;
			cout << start - row + 1 << nline;
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
	arr.resize(sizee, vi (sizee, 0));
	//tableFill();
	int T;
	T = 1;
	cin >> T;
	while (T--)
		solve();
	return 0;
}
