#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

void solve() {
    
    sort(a.begin(), a.end());
    for(int i = 1; i < n; i++) {
        if (a[i-1] == a[i]) {
            cout << ":(";
            return;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << a[i] - i << " ";
    }


}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	a.assign(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]+=i;
	}
	solve();
}