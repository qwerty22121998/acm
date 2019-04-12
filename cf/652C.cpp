#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;

vector<vector<int> > res;
int m, n;
vector<int> a;

map<ii, int> mp;


void solve() {
    vector<int> tmp;
    tmp.push_back(a[0]);
    for(int i = 1; i < a.size(); i++) {
        if (mp[ii(a[i], tmp.back())]) {
            res.push_back(tmp);
            tmp.clear();
        }
        tmp.push_back(a[i]);
    }
    res.push_back(tmp);
    ll result = 0;
    for(auto e : res) {
        ll s = e.size();
        result += s*(s+1)/2;
    }
    cout << result;
}

int main() {
    cin >> n >> m;
    a.assign(n, 0);
    for(auto &e : a) cin >> e;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        mp[ii(u, v)] = 1;
        mp[ii(v, u)] = 1;
    }
    solve();


}