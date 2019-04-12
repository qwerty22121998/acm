#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 5e5;

ll f[MAXN] = {0};
ll g[MAXN] = {0};
int n;


void solve() {
    for(int i = MAXN - 10; i >= 0; i--) {
        f[i] = f[i+1] + g[i];
    }
    ll res = 0;
    for(int i = 1; i < MAXN/2;i++) {
        if (g[i]) {
            ll now = 0;
            for(ll j = i; j < MAXN/2; j += i) {
                now += j*(f[j] - f[i + j]);
            }
            res = max(res, now);
        }
    }

    cout << res;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        g[tmp]++;
    }
    
    solve();
}