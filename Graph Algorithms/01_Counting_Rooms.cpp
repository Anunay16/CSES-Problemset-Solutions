//link to the problem: https://cses.fi/problemset/task/1192/
#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void dfs(vector<vector<char>>& mat, int i, int j, vector<vector<bool>>& visited) {
    if (i < 0 or j < 0 or i >= (int)mat.size() or j >= (int)mat[0].size() or visited[i][j] or mat[i][j] == '#') {
        return;
    }
    visited[i][j] = true;
    for (int k = 0; k < 4; k++) {
        int new_i = i + dx[k];
        int new_j = j + dy[k];
        dfs(mat, new_i, new_j, visited);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool> (m, false));
    //we have to find no of connected components
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == '.' and !visited[i][j]) {
                dfs(mat, i, j, visited);
                cnt++; 
            }
        }
    }
    cout << cnt << "\n";
}

void FIO()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

int main()
{
    FIO();
    solve();
    return 0;
}
