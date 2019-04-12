#include<bits/stdc++.h>
using namespace std;

// char median(char a, char b) {
//     return (a + b)/2;
// }

void fix(vector<int> & a) {
    a.push_back(0);
    for(int i = 0;i < a.size()-1; i++) {
        a[i+1] += a[i]/26;
        a[i]%=26;
        if (a[i] < 0) {
            a[i]+=26;
            a[i+1]--;
        }
    }
    while (a.size() > 1 && a.back() == 0) a.pop_back();
}

vector<int> convert(string a) {
    vector<int> result;
    for(auto e : a) {
        result.push_back(e - 'a');
    }
    reverse(result.begin(), result.end());
    return result;
}

vector<int> add(vector<int> a, vector<int> b) {
    while (a.size() < b.size()) a.push_back(0);
    while (b.size() < a.size()) b.push_back(0);
    for(int i = 0; i < a.size(); i++) {
        a[i] += b[i];
    }
    fix(a);
    return a;
}

vector<int> div(vector<int> a, int b) {
    vector<int> c;
    int carry = 0;
    for(int i = a.size() - 1; i >= 0; i--) {
        carry = carry * 26 + a[i];
        c.push_back(carry / b);
        carry %= b;
    }
    reverse(c.begin(), c.end());
    fix(c);
    return c;
}

int main() {
    int n;
    string a, b;
    cin >> n;
    
    cin >> a >> b;
    vector<int> res = div(add(convert(a), convert(b)), 2);
    for(int i = n-1; i >= 0; i--) {
        cout << char(res[i] + 'a');
    }

}
