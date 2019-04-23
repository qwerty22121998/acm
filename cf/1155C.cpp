#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

typedef pair<int,int> ii;

int n, m;
vector<ll> x;
vector<ll> p;
vector<ll> f;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a%b);
}

ll gcd(vector<ll> a) {
    
    ll res = a[0];
    for(int i = 1; i < a.size(); i++) {
        res = gcd(res, a[i]);
    }
    return res;
}

void solve() {
    for(int i = 1; i < x.size(); i++) {
        f.push_back(x[i] - x[i-1]);
    }
    ll now = gcd(f);
    for(int i = 0; i < p.size(); i++) {
        ll e = p[i];
        if (now % e == 0) {
            cout << "YES\n" << x[0] << ' ' << i+1;
            return;
        }
    }
    cout << "NO";
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    cin >> n >> m;
    x.assign(n, 0);
    p.assign(m, 0);
    for(auto & e : x) cin >> e;
    for(auto & e : p) cin >> e;
    
    solve();
}