#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;
set<ll> ms;

ll calc(ll step) {
    ll cnt = n/step;
    return (cnt*(2*1 + (cnt-1)*step))/2;
}

void solve() {
    for(ll i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            ms.insert(calc(i));
            ms.insert(calc(n/i));
        };
    }
    for(auto e : ms)
        cout << e << ' ';
}

int main() {
    cin >> n;
    solve();
}
