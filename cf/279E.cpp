#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;

ll f[2] = {0};
void solve() {

	f[0] = 1;
	f[1] = 0;
	for(auto e : s) {
		ll now = min(f[1], f[0]);
		if (e == '0') f[0] = now+1;
		else f[1] = now + 1;
	}
	cout << f[1];
}

int main() {
	cin >> s;
	solve();
}