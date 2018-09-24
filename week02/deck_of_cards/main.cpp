/* Some corner cases:
 * [case 0]
 * 5 0
 * 0 0 0 0 0
 * [case 1]
 * 5 2
 * 0 0 1 1 0
 * [case 2]
 * 5 8
 * 0 0 5 4 0
 */
#include <cstdio>
#include <cstring>

#define abs(x) ((x) >= 0 ? (x) : (-(x)))
int v[100010];
void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", v + i);
    int l = 0, r = 0, sum = 0;
    int bestval = 0x7fffffff, bestl = 0, bestr = 0;
    while (r < n) {
        sum += v[r];
        if (abs(k - sum) < abs(bestval)) {
            bestval = k - sum;
            bestl = l;
            bestr = r;
            if (k == sum) break;
        }
        while (sum > k) {
            sum -= v[l++];
        }
        if (sum == k) {
            bestval = k - sum;
            bestl = l;
            bestr = r;
            break;
        }
        r++;
    }
    printf("%d %d\n", bestl, bestr);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}
