#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MODULO = 1e9+7;
ll n, a, b, k;
vector<ll> f,g;

int main(){

	cin >> n >> a >> b >> k;
	if(a > b) {
		a = n - a + 1;
		b = n - b + 1;
	}
	f.assign(b, 0);
	g.assign(b, 0);
	f[a]=1;

	for(int i = 0; i < k; i++) {
		for(int j = 1; j < b; j++) g[j] = (MODULO - f[j]) % MODULO;
		for(int j = 1; j < b; j++) {
			f[j] += f[j-1];
			f[j] %= MODULO;
		}
		for(int j = 1; j < b; j++) {
			g[j] += f[(j + b - 1) / 2];
			g[j] %= MODULO;
		}
		vector<ll> temp = f; f = g; g = f;
	}
	ll result = 0;
	for(int j = 1; j < b; j++) {
		result += f[j];
		result %= MODULO;
	}
	cout << result;

}