#include <algorithm>
#include <cstdio>

const int N = 1000005;

int n, m, ans, b[N], a[N];

int main() {
    freopen("inp.inp", "r", stdin);
    freopen("out.out", "w", stdout);
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        ans += a[i];
        b[i] = (b[i - 1] + a[i]) % m;
    }
    b[n] = m;
    std::sort(b + 1, b + n + 1);
    printf("%d\n", ans = (ans - 1) / m + 1);
    for (int i = n; i; i--) {
        b[i] -= b[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
    while(ans--) {
        for (int i = 1, j = 1; i <= n; i++) {
            while (j < n && a[j] <= 0) {
                j++;
            }
            printf("%d ", j);
            a[j] -= b[i];
        }
        printf("\n");
    }
    return 0;
}  //