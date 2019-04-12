#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> p;
vector<int> a;

int check(vector<int> a) {
    vector<int> c(a.size()+1, 0);
    for(auto e : a) {
        if (e > a.size()) return 0;
        if (c[e]) return 0;
        c[e]++;
    }
    for(int i = 1; i < c.size(); i++) {
        if (!c[i]) return 0;
    }
    return 1;
}

void solve() {
    a.push_back(1);
    int minn = 1;
    for(auto e : p) {
        int now = a.back() + e;
        a.push_back(now);
        minn = min(minn, now);
    }
    if (minn != 1) {
        int add = abs(minn) +1;
        for(auto &e : a) e += add;
    }
    if (check(a)) {
        for(auto e : a) cout << e << ' ';
    } else {
        cout << -1;
    }
    
}


int main() {
    cin >> n;
    p.assign(n-1, 0);
    for(auto &e : p) cin >> e;
    solve();
}