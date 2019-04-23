#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

typedef pair<int,int> ii;

int n;
vector<int> a;
set<int> f;

int op(int a, int b, int des) {
    if (abs(a - des) == abs(b-des)) {
        return abs(a- des);
    }
    return -1;
}


int solve() {
    for(auto e : a) {
        f.insert(e);
    }
    vector<int> g;
    for(auto e : f) {
        g.push_back(e);
    }
    if (g.size() == 1) {
        return 0;
    }
    if (g.size() == 2) {
        int m = (g[0] + g[1]) / 2;
        if (abs(g[0] - m) == abs(g[1]-m)) return abs(g[0] - m);
        return abs(g[0] - g[1]);
    }
    if (g.size() > 3) {
        return -1;
    }
    sort(g.begin(), g.end());
    do {
        int res = op(g[0], g[1], g[2]);
        if (res != -1) return res;
    } while (next_permutation(g.begin(), g.end()));
    
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    a.assign(n, 0);
    for(auto &e : a) cin >> e;
    cout << solve();
}