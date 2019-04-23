#include<bits/stdc++.h>
using namespace std;


int n, t;

void solve() {
    int res = -1;
    int space = 1e6;
    for(int i = 0; i < n; i++) {
        int s, d;
        cin >> s >> d;
        if (s > t) {
            if (s-t < space) {
                space = s-t;
                res = i;
            }
            continue;
        }
        if ((t-s)%d < space) {
            space = (t-s)%d;
            res = i;
        }
    }
    cout << res + 1;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;
    
    solve();
}