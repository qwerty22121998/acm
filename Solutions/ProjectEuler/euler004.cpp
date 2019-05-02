#include<bits/stdc++.h>
using namespace std;


int isPalindrome(int x) {
    int a = x;
    int b = 0;
    while (x) {
        b = b * 10 + x % 10;
        x /= 10;
    }
    return a == b;

}

vector<int> palindrome;

void gen() {
    for(int i = 100; i <= 999; i++) {
        for(int j = i+1; j <= 999; j++) {
            int now = i * j;
            if (isPalindrome(now))
                palindrome.push_back(now);
        }
    }
    sort(palindrome.begin(), palindrome.end());
}

void solve() {
    int n;
    cin >> n;
    cout << *(lower_bound(palindrome.begin(), palindrome.end(), n)-1) << '\n';
}

int main() {
    gen();
    int T;
    cin >> T;
    while (T--) solve();
}
