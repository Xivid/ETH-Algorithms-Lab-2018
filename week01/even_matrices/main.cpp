#include <iostream>
#include <cstring>
using namespace std;

int a[210][210], b[210];
int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }

        int ans = 0;
        // compress rows i ~ j into b[] by the sum of each column
        for (int i = 0; i < n; ++i) {
            memset(b, 0, sizeof(int) * 210);
            for (int j = i; j < n; ++j) {
                // calculate the number of even pairs in b
                int sum = 0, numEven = 0, numOdd;
                for (int k = 0; k < n; ++k) {
                    b[k] += a[j][k];
                    sum += b[k];
                    if (sum % 2 == 0) {
                        ++numEven;
                    }
                }
                numOdd = n - numEven;
                ans += numEven * (numEven - 1) / 2 + numOdd * (numOdd - 1) / 2 + numEven;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
