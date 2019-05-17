#include<bits/stdc++.h>
using namespace std;

const int MAXN = 60;

typedef long long ll;

typedef pair<int,int> ii;

int n;
int cnt[MAXN] = {0};

vector<int> a;

void solve() {
    for(auto e : a) cnt[e]++;
    for(int i = 0; i < MAXN; i++) {
        if (cnt[i]) {
            cout << (cnt[i] > n/2 ? "Bob":"Alice");
            return;
        }
    }
    
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    a.resize(n);
    for(auto &e : a) cin >> e;
    
    solve();
}