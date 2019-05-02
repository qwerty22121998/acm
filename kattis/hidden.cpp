#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

typedef pair<int,int> ii;

int first['Z'+1] = {-1};

void solve() {
    for(int i = 0; i < s.size(); i++) {
        if (first[s[i]] == -1) {
            first[s[i]] = i;
        }
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> pass >> s;
    
    solve();
}