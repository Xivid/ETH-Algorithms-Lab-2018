#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define debug_printf(...) ;
using namespace std;

int x[1000010];  // 10^6
vector<int> coords;

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", x + i);

    // sort by positions
    sort(x, x + n);

    int l = 0, r = 0, maxcover = -1, minradius = 300;
    coords.clear();
    while (r != n - 1) {
        if (x[r+1] - x[l] > 200) {
            ++l;
        }
        while (r < n-1 && x[r+1] - x[l] <= 200) { 
            ++r;
        }       
        int cover = r - l + 1;
        int mid = (x[r] + x[l]) / 2;
        int radius = max(x[r] - mid, mid - x[l]);
        if (cover >= maxcover) {
            if (cover > maxcover || radius < minradius) {
                maxcover = cover;
                minradius = radius;
                coords.clear();
            }
            if (radius == minradius) {
                if (x[r] - mid > mid - x[l]) {
                    coords.push_back(mid);
                    coords.push_back(mid + 1);
                } else if (x[r] - mid < mid - x[l]) {
                    coords.push_back(mid - 1);
                    coords.push_back(mid);
                } else {
                    coords.push_back(mid);
                }
            }
        }
    }

    // output answer
    printf("%d %d\n", maxcover, minradius);
    bool first = true;
    for (auto c: coords) {
        if (first) {
            first = false;
            printf("%d", c);
        } else {
            printf(" %d", c);
        }
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}
