#include<bits/stdc++.h>
using namespace std;


string s;

void solve() {
    int now = 0, minn = 0, maxx = 0;
    for(auto e : s) {
        if (e == '+') now++;
        else now--;
        maxx = max(maxx, now);
        minn = min(minn, now);
    }
    cout << maxx - minn;
    
}

int main() {
    cin >> s;
    solve();
}