#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

typedef pair<int,int> ii;

string vowel = "aeiouy";

int n;
string s;
string result = "012";
int isVowel(char a) {
    return vowel.find(a) != string::npos;
}


void solve() {
    int rep = 0;
    char crep = 0;
    for(auto e : s) {
        if (!isVowel(e)) {
            result.push_back(e); 
            crep = 0;
            rep = 0;
            continue;
        }
        if (e == 'e' || e == 'o') {
            if (e != crep) {
                rep = 1;
                crep = e;
                result.push_back(e);
            } else {
                rep++;
                if (rep > 2) while (result.back() == crep) result.pop_back();
                result.push_back(e);
            }
        } else {
            crep = 0;
            rep = 0;
            if (result.back() != e) {
                result.push_back(e);
            }
        }        
    }
    result.erase(result.begin(), result.begin()+3);
    cout << result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> s;
    
    solve();
}