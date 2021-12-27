// link to the problem: https://cses.fi/problemset/task/1618/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, ans, base;
void solve() {
    cin >> n;
    base = 5;
    ans = 0;
    while (true) {
        ans += (n / base);
        base *= 5;
        if (base > n) {
            break;
        }
    }
    cout << ans << "\n";
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
