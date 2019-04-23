#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

typedef pair<int,int> ii;

ll n;
vector<ll> a;
ll x, f;


void solve() {
    ll res = 0;
    for(auto e : a) {
        if (e <= f) continue;
        res += (e + x - 1)/(f+x);
    }
    cout << res*x;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    a.assign(n, 0);
    for(auto & e : a) cin >> e;
    cin >> f >> x;
    
    solve();
}