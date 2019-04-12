#include <bits/stdc++.h>
using namespace std;
vector<int> a, f;
int n;



int calc(int l, int r) {
	if (f[l] >= (r-l+1))
		return r - l + 1;
	int m = (l+r)/2;
	return max(calc(l, m), calc(m+1,r));
}

void solve() {
	f.back() = 1;
	for(int i = f.size()-2; i >= 0; i--) {
		f[i] = 1;
		if (a[i] <= a[i+1]) f[i] += f[i+1];
	}
    cout << calc(0, a.size()-1);
}

int main() {
	cin >> n;
	a.assign(n, 0);
	f.assign(n, 0);
	for(auto &e : a) cin >> e;
	solve();


}