#include <iostream>
using namespace std;

// Find bitwise AND of all numbers in range [left, right]
int rangeBitwiseAnd(int left, int right) {
    int shift = 0;

    while (left != right) {
        left >>= 1;
        right >>= 1;
        shift++;
    }

    return left << shift;
}

int main() {
    int left = 5, right = 7;

    cout << "Bitwise AND of range [" << left << ", " << right << "] = "
         << rangeBitwiseAnd(left, right) << endl;

    return 0;
}
