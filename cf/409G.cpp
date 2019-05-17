#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

typedef pair<int,int> ii;

const int MAXN = 1e3+5;
double ans = 0;
double x[MAXN], y[MAXN];
int n;

void solve() {
    cout << fixed << setprecision(5) << ans/n + 5;
    
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        ans+=y[i];
    }
    
    solve();
}