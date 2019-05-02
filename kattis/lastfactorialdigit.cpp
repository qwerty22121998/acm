#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

typedef pair<int,int> ii;


void solve() {
    int n;
    cin >> n;
    int res = 1;
    for(int i = 1; i <= n; i++) {
        res*=i;
        res%=10;
    }
    cout << res << '\n';
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    solve();
}