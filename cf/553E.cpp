#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

typedef pair<int,int> ii;

ll n;
vector<int> a;

void solve() {
    ll res = 0;
    a.insert(a.begin(), 0);

    for(int i = 0; i < n; i++) {
        ll u = a[i];
        ll v = a[i+1];
        if (u < v) res += (n-v+1)*(v-u);
        else res += (u-v)*v;  
    }

    cout << res;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    a.assign(n, 0);
    for(auto &e : a) cin >> e;
    
    solve();
}