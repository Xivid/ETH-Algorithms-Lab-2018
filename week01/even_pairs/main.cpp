#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, numEvenSum = 0, numOddSum = 0;
        cin >> n;
        numOddSum = n;
        // get input numbers and update state one by one
        bool a, currentSumIsEven = true;
        while (n--) {
            cin >> a;
            if (a) {
                currentSumIsEven = !currentSumIsEven;
            }
            if (currentSumIsEven) {
                ++numEvenSum;
            }
        }
        numOddSum -= numEvenSum;
        // output result (negativity doesn't matter if a num is 0: the product will always be 0)
        cout << numEvenSum * (numEvenSum - 1) / 2 + numOddSum * (numOddSum - 1) / 2 + numEvenSum << endl;
    }
    return 0;
}
