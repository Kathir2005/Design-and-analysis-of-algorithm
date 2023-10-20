#include <stdio.h>
#include <stdbool.h>
void generatePrimes(int limit) {
    if (limit < 2) {
        printf("No prime numbers within the specified limit.\n");
        return;
    }
    bool isPrime[limit + 1];
    for (int i = 0; i <= limit; i++) {
        isPrime[i] = true;
    }

    isPrime[0] = isPrime[1] = false; 

    for (int p = 2; p * p <= limit; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                isPrime[i] = false;
            }
        }
    }
    printf("Prime numbers up to %d are: ", limit);
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
int main() {
    int limit;
    printf("Enter a limit to generate prime numbers: ");
    scanf("%d", &limit);

    generatePrimes(limit);

    return 0;
}

