#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

ll a, b ,c;
ll result = 0;
typedef pair<int,int> ii;
ll aa[7] = {-1, 0, 0,-1, 0, 0,-1};
ll bb[7] = { 0,-1, 0, 0, 0,-1, 0};
ll cc[7] = { 0, 0,-1, 0,-1, 0, 0};

ll calc(ll a, ll b, ll c,ll before, ll after) {
    for(int i = 0; i < before; i++) {
        int pos = 7 - i -1;
        a += aa[pos];
        b += bb[pos];
        c += cc[pos];
    }
    for(int i = 0; i < after; i++) {
        a += aa[i];
        b += bb[i];
        c += cc[i];
    }
    if (a >= 0 && b >= 0 && c >= 0) return before + after;
    return 0;
}

ll calc2(ll a, ll b, ll c, ll l, ll r) {
    for(int i = l; i <= r; i++) {
        a += aa[i%7];
        b += bb[i%7];
        c += cc[i%7];
    }
    if (a >= 0 && b >= 0 && c >= 0) return (r - l + 1);
    return 0;
}

void solve() {
    ll week = min(min(a/3, b/2), c/2);
    if (week != 0) {
        a -= week*3;
        b -= week*2;
        c -= week*2;
        ll maxx = 0;
        for(int i = 0; i <= 7; i++) {
            for(int j = 0; j <= 7; j++) {
                maxx = max(maxx, calc(a, b, c, i, j));
            }
        }
        cout << week*7 + maxx;
    } else {
        ll res = 0;
        for(int i = 0; i <= 14; i++) {
            for(int j = i; j <= 14; j++) {
                res = max(res, calc2(a, b, c, i, j));
            }
        }
        cout << res;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> c;
    
    solve();
}