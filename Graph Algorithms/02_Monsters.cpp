/*
link to the problem: https://cses.fi/problemset/task/1194
 
Approach: MULTI SOURCE BFS
*/

#include <bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#include "debug.h"
#else 
#define debug(...) 42
#endif
 
#define	int      long long
#define vi       vector<int>
#define vvi      vector<vector<int>>
#define vs       vector<string>
#define pii      pair<int, int>
#define ff       first
#define ss       second
#define nline    "\n"
#define pb       push_back
#define ppb      pop_back
#define no()     cout << "NO\n"
#define yes()    cout << "YES\n"
#define sz(x)    ((int)(x).size())
#define cc(ans)  cout << ans << "\n"
#define all(x)   (x).begin(), (x).end()
#define input(v) for (auto& x: v) cin >> x
#define print(v) for (auto& x: v) cout << x << " "
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
 
//==========================MAIN CODE===============================
 
int n, m;
vector<vector<char>> mat;
const int nax = 1005;
int track[nax][nax];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};
int dir[] = {'U', 'L', 'D', 'R'};
 
void test_case() {
	cin >> n >> m;
	int A_i = -1, A_j = -1;
	queue<pii> q;
	mat.resize(n, vector<char> (m));
	for (int i = 0; i < n; i++) {
		for (int j = 0 ;j < m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 'M') {
				q.push({i, j});
			}
			else if (mat[i][j] == 'A') {
				A_i = i;
				A_j = j;
			}
		}
	}
	q.push({A_i, A_j});
	track[A_i][A_j] = -1;
	while(!q.empty()) {
		int x = q.front().ff;
		int y = q.front().ss;
		q.pop();
		
		if (mat[x][y] == 'A' and (x == n - 1 or y == m - 1 or x == 0 or y == 0)) {
			yes();
			string path = "";
			int d = track[x][y];
			while (d != -1) {
				path.push_back(dir[d]);
				x -= dr[d];
				y -= dc[d];
				d = track[x][y];			
			}
			debug(path);
			reverse(all(path));
			cout << sz(path) << nline << path << nline;
			return;
		}
		
		for (int k = 0; k < 4; k++) {
			int ni = x + dr[k];
			int nj = y + dc[k];
			if (ni < 0 or nj < 0 or ni >= n or nj >= m or mat[ni][nj] != '.'){
				continue;
			}
			mat[ni][nj] = mat[x][y];
			if (mat[ni][nj] == 'A') {
				track[ni][nj] = k;
			}
			q.push({ni, nj});
		}
	}
	no();
}
 
 
signed main()
{
    ios_base::sync_with_stdio(false);
	  cin.tie(0);cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) test_case();
    return 0;
}
