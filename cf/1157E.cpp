#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

typedef pair<int,int> ii;

int n;
vector<int> a, b;
vector<int> res;
multiset<int> m;
void solve() {
    for(auto e : b) m.insert(e);
    for(int i = 0; i < n; i++) {
        multiset<int>::iterator it = m.lower_bound(n - a[i]);
        if (it == m.end()) it = m.begin();
        res.push_back((a[i] + *it) % n);
        m.erase(it);
    }
    for(auto e : res) cout << e << ' ';
   
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    a.resize(n);
    b.resize(n);
    for(auto &e : a) cin >> e;
    for(auto &e : b) cin >> e;
    
    solve();
}