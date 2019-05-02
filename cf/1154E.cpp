#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5+5;
typedef long long ll;

typedef pair<int,int> ii;

prioty_queue<int> heap;
int nxt[maxn] = -1;
int pre[maxn] = -1;
int n, k;
vector<int> a;
void solve() {
    nxt[a[0]] = a[1];
    pre[a.back()] = a[a.size()-2];
    for(int i = 1; i < a.size() - 1; i++) {
        pre[a[i]] = a[i-1];
        nxt[a[i]] = a[i+1];
    }
    
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    a.assign(n, 0);
    for(auto &e : a) cin >> e;
    
    solve();
}