#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int,int> ii;
double a, b, c;

vector<double> solve(double a, double b, double c) {
    vector<double> res;
    double sdel = sqrt(b * b - 4 * a * c);
    res.push_back((-b + sdel )/ (2.0 * a));
    res.push_back((-b - sdel )/ (2.0 * a));
    sort(res.begin(), res.end(), std::greater<double>());
    return res;
}

void solve() {
    auto res = solve(a, b, c);
    cout << fixed << setprecision(10) << res[0] << '\n' << res[1];
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> c;
    
    solve();
}