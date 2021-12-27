// link to the problem: https://cses.fi/problemset/task/1754/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    Let’s assume that we are removing xx number of times 22 coins from pile aa and 11 coin from pile bb.

    Let’s assume that we are removing yy number of times 11 coin from pile aa and 22 coins from pile bb.

    Mathematically we can write our assumptions as:
    a = 2x + y 
    b = x + 2y 

    We have two equations and we have two unknowns, means we can solve for xx and yy.
    After solving the above equations for xx and yy, you will get:
    
    x = (2b - a)/3 
    y = (2a - b)/3​

*/

ll t, a, b;
void solve() {
    cin >> t;
    while (t--) {
        cin >> a >> b;
        ll x = 2LL * a - b;
        ll y = 2LL * b - a;
        if (x < 0 or y < 0) {
            cout << "NO\n";
            continue;
        }
        if (x % 3 == 0 and y % 3 == 0) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
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

int main()
{
    FIO();
    solve();
    return 0;
}
