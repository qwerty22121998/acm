#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;

ll x;
ll res = 9;
void solve() {
    if (x > 9) res++;
    while (x > 9) {
        res += 9 - x%10;
        x/=10;
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> x;

    solve();
}