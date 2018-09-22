#include <cstdio>

int main() {
    int t, n, x, s;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        s = 0;
        while (n--) {
            scanf("%d", &x);
            s += x;
        }
        printf("%d\n", s);
    }
    return 0;
}
