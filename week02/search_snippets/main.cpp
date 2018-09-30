#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define debug_printf(...) ;
using namespace std;

int m[3000];  // 2^11
struct Word {
    int id;
    int position;
} words[70000];

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", m + i);

    int tot = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m[i]; ++j) {
            words[tot].id = i;
            scanf("%d", &words[tot++].position);
        }
    }

    // sort by positions
    sort(words, words + tot, [](const Word& a, const Word& b) { return a.position < b.position; });

    int l = 0, r = -1, minlen = 0x7fffffff;
    int found = 0;
    memset(m, 0, sizeof(int) * n);
    while (r < tot - 1) {
        if (found != n) {
            if (m[words[++r].id]++ == 0) ++found;
        } else {
            if (words[r].position - words[l].position + 1 < minlen) {
                minlen = words[r].position - words[l].position + 1;
            }
            if (l < r && m[words[l].id] > 1) {
                --m[words[l++].id];
            } else if (l < r && r < tot - 1) {
                ++m[words[++r].id];
            }
        }
    }
    printf("%d\n", minlen);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}
