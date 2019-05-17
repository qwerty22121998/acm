#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9
struct PT {
    double x, y;
    PT() : x(0), y(0) {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT& p) : x(p.x), y(p.y) {}
    int operator<(const PT& rhs) const {
        return make_pair(y, x) < make_pair(rhs.y, rhs.x);
    }
    int operator==(const PT& rhs) const {
        return make_pair(y, x) == make_pair(rhs.y, rhs.x);
    }
    PT operator+(const PT& p) const { return PT(x + p.x, y + p.y); }
    PT operator-(const PT& p) const { return PT(x - p.x, y - p.y); }
    PT operator*(double c) const { return PT(x * c, y * c); }
    PT operator/(double c) const { return PT(x / c, y / c); }
};
double cross(PT p, PT q) { return p.x * q.y - p.y * q.x; }

int LinesParallel(PT a, PT b, PT c, PT d) {
    return fabs(cross(b - a, c - d)) < EPS;
}
int LinesCollinear(PT a, PT b, PT c, PT d) {
    return LinesParallel(a, b, c, d) && fabs(cross(a - b, a - c)) < EPS &&
           fabs(cross(c - d, c - a)) < EPS;
}
PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
    b = b - a; d = c - d; c = c - a;
    return a + b * cross(c, d) / cross(b, d);
}


typedef long long ll;

typedef pair<int, int> ii;

typedef pair<PT, PT> Line;

int n;
vector<PT> a;
vector<Line> l;
map<double, int> z;


void solve() {
    for (int i = 0; i < a.size() - 1; i++) {
        for (int j = i + 1; j < a.size(); j++) {
            l.push_back(Line(a[i], a[j]));
        }
    }

    int res = (l.size() * (l.size()-1))/2;
    int pal = 0;
    for(int i = 0; i < l.size(); i++) {
        if (LinesParallel(l[i].first, l[i].second, PT(0,0), PT(1, 0))) {
            pal++;
            continue;
        }
        PT o = ComputeLineIntersection(l[i].first, l[i].second, PT(0,0), PT(1,0));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back(PT(x, y));
    }

    solve();
}