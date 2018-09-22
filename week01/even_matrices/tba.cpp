/* This solution is not finished */
#include <iostream>
using namespace std;

int sum[210][210];
int numEvenRow[210], numOddRow[210], numEvenCol[210], numEvenCol[210];
int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        memset(sum, 0, sizeof(int) * 210 * 210);
        memset(numEvenRow, 0, sizeof(int) * 210);
        memset(numOddRow, 0, sizeof(int) * 210);
        memset(numEvenCol, 0, sizeof(int) * 210);
        memset(numOddCol, 0, sizeof(int) * 210);
        int n;
        cin >> n;
        bool x;
        int sum = 0, numEven = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> x;

                if (sum[i][j] & 1 == 0) {
                    ++numEven;  // numOdd = n - numEven
                }
            }
        }
    }
    return 0;
}
