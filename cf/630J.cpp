#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

typedef pair<int,int> ii;
ll n;

void solve() {
    ll lcm = 2 * 2 * 2 * 3 * 3 * 5 * 7;
    cout << n / lcm;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    
    solve();
}