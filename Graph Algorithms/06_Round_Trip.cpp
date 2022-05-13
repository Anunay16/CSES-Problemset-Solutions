// link to the problem: https://cses.fi/problemset/task/1669/

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
#define sz(z)    ((int)(z).size())
#define cc(ans)  cout << ans << "\n"
#define all(z)   (z).begin(), (z).end()
#define input(v) for (auto& z: v) cin >> z
#define print(v) for (auto& z: v) cout << z << " "

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

//==========================MAIN CODE===============================

const int nax = 1e5 + 7;
int n, m, u, v, i, sp, ep, temp;
vector<vector<int>> adj;
vector<int> parent, visited, ans;
 
bool dfs(int cur, int par) {
    visited[cur] = 1;
    parent[cur] = par;
    for (int nb: adj[cur]) {
        if (nb == par) continue;
        if (visited[nb]) {
            sp = nb;
            ep = cur;
            return true;
        }
        else {
            if (dfs(nb, cur)) return true;
        }
    }
    return false;
}
 
void test_case() {
    cin >> n >> m;
    adj.resize(n + 1);
    parent.resize(n + 1, -1);
    visited.resize(n + 1);
    sp = ep = -1;
    for (i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
 
    for (i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                break;   
            }
        }
    }
    if (sp == -1) {
        cc("IMPOSSIBLE");
        return;
    }
    debug(parent);
    debug(sp);
    debug(ep);
    
    ans.clear();
    ans.pb(ep);
    temp = ep;
    while (temp != sp) {
      ans.pb(parent[temp]);
      temp = parent[temp];
    }
    ans.pb(ep);
    cc(sz(ans));
    print(ans);
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
