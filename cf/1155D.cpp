#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

typedef pair<int,int> ii;

const int maxn = 3e5+10;

int n;
ll x;
ll f[maxn][5] = {0};
ll a[maxn];

void solve() {

    
    f[0][0] = a[0];
    f[0][1] = a[0]*x;
    f[0][2] = a[0]*x;
    ll res = max(a[0], a[0]*x);
    res = max(res, 0ll);
    for(int i = 1; i < n; i++) {
        f[i][0] = max(f[i-1][0] + a[i], a[i]);
        f[i][1] = max(max(f[i-1][0], f[i-1][1]) + a[i]*x, a[i]*x);
        f[i][2] = max(f[i-1][2] + a[i], f[i-1][1] + a[i]*x);
        f[i][2] = max(f[i][2], f[i][1]);
        res = max(res, f[i][0]);
        res = max(res, f[i][1]);
        res = max(res, f[i][2]);
    }
    cout << res;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> a[i];
    solve();
}