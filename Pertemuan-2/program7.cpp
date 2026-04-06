#include <stdbool.h>
#include <stdio.h>

bool isPrime(int n) {
    if (n <= 1)
        return false;

    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

void findPrimes(int l, int r) {
    bool found = false;

    for (int i = l; i <= r; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
            found = true;
        }
    }

    if (!found) {
        printf("No prime numbers found in the given range.");
    }
}

int main() {
    int l = 10, r = 30;

    findPrimes(l, r);

    return 0;
}
