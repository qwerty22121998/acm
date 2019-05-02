#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

ll ans[41];

void gen() {
    ll res = 1;
    ans[1] = 1;
    for(ll i = 2; i <= 40; i++) {
        ans[i] = lcm(ans[i-1], i);
    }
}

void solve() {
    ll n;
    cin >> n;
    cout << ans[n] << '\n';
}

int main() {
    gen();
    int T;
    cin >> T;
    while (T--) solve();
}
