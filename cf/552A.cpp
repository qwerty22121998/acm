#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

typedef pair<int,int> ii;
vector<int> f(4);
int a, b, c;
bool ok(int ab, int ac, int bc, int abc) {
    a = abc - bc;
    c = ac - a;
    b = ab - a;
    return bc == b + c;
}

void solve() {
    sort(f.begin(), f.end());
    do {
        if (ok(f[0], f[1], f[2], f[3])) {
            cout << a << ' ' << b << ' ' << c;
            return;
        }
    } while (next_permutation(f.begin(), f.end()));
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i < 4; i++) cin >> f[i];
    
    solve();
}