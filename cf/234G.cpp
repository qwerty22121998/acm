#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

typedef pair<int,int> ii;

int n;


void solve() {
    int res = ceil(log(n)/log(2));
    cout << res << '\n';
    for(int i = 0; i < res; i++) {
        vector<int> res;
        for(int j = 0; j <= n; j++) {
            if (j & (1 << i)) res.push_back(j);
        }
        cout << res.size() << ' ';
        for(auto e : res) cout << e << ' ';
        cout << '\n';
    }
    
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    solve();
}