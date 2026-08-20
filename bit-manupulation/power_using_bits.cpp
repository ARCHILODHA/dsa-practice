#include <iostream>
using namespace std;

// Calculate a^b using binary exponentiation
long long power(long long a, long long b) {
    long long result = 1;

    while (b > 0) {
        if (b & 1)
            result *= a;

        a *= a;
        b >>= 1;
    }

    return result;
}

int main() {
    long long base = 3;
    long long exponent = 5;

    cout << base << "^" << exponent << " = "
         << power(base, exponent) << endl;

    return 0;
}
