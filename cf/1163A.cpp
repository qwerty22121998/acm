#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

typedef pair<int,int> ii;

int n, m;

void solve() {
    if (m == 0) {
        cout << 1;
        return;
    }
    cout << min(m, n-m); 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    
    solve();
}