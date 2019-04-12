#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
vector<ll> a;
void solve() {
    for(int i = 0; i < m; i++) {
        int q, l , r;
        cin >> q >> l >> r;
        if (q == 1) {
            ll result = 0;
            for(int j = l-1; j < r; j++) result+=a[j];
            cout << result << '\n';
            continue;
        }
        ll t;
        cin >> t;
        for(int j = l-1; j < r; j++) a[j] ^= t;
        
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.assign(n, 0);
    for(auto &e : a) cin >> e;
    cin >> m;
    solve();
}