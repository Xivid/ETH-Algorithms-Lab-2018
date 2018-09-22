#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int t, n, x, stop;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        stop = 2;
        int i;
        for (i = 1; i < stop && i <= n; ++i) {
            scanf("%d", &x);
            stop = max(stop, i + x);
        }
        printf("%d\n", i - 1);
        for (; i <= n; ++i) 
            scanf("%d", &x);
    }

    return 0;
}
