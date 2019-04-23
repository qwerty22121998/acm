#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

typedef pair<int,int> ii;

int n, b, a;
vector<int> f;
int solve() {
    int maxa = a, maxb = b;
    for(int i = 0; i < n; i++) {
        if (!a && !b) return i;
        if (f[i]) {
            if (b) {
                a++;
                b--;
            } else {
                a--;
            }
        } else {
            if (a) a--;
            else b--;
        }
        a = min(a, maxa);
        b = min(b, maxb);
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> b >> a;
    f.assign(n, 0);
    for(auto &e : f) cin >> e;
    cout << solve();
    solve();
}