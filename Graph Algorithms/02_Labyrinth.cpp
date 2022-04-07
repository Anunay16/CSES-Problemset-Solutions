/*
    Link to the problem: https://cses.fi/problemset/task/1193/
    
    idea: BFS
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
const int nax = 1005;
vector<vector<char>> mat;
int track[nax][nax];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};
char dir[] = {'U', 'L', 'D', 'R'};

void test_case() {
	cin >> n >> m;
	mat.resize(n, vector<char> (m));
	pii start, end;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 'A') {
				start = {i, j};
			}
			else if (mat[i][j] == 'B') {
				end = {i, j};
			}
		}
	}
	queue<pii> q;
	q.push(start);
	track[start.ff][start.ss] = -1;
	mat[start.ff][start.ss] = '#';
	
	while (!q.empty()) {
		int r = q.front().ff;
		int c = q.front().ss;
		q.pop();
		
		if (r == end.ff and c == end.ss) {
			yes();
			string path = "";
			int d = track[r][c];
			while (d != -1) {
				path.push_back(dir[d]);
				r -= dr[d];
				c -= dc[d];
				d = track[r][c];
			}
			reverse(all(path));
			cout << sz(path) << nline << path << nline;
			return;
		}
		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];
			if (nr < 0 or nc < 0 or nr >= n or nc >= m or mat[nr][nc] == '#'){
				continue;
			}
			mat[nr][nc] = '#';
			track[nr][nc] = k;
			q.push({nr, nc});
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
