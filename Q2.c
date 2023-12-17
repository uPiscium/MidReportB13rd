#include "Q2.h"

#define EPS 1

int IsCircular(int num) {
    int rst = 0;
    if (num < 100) {
        return 0;
    } else if (100 <= num && num < 1000) {
        return num % 100 == 0;
    } else if (1000 <= num && num < 10000) {
        return (num / 1000 == (num % 100) / 10) && (num % 10 == 0);
    } else {
        return num / 10000 == num % 10 &&
               (num % 10000) / 1000 == (num % 100) / 10;
    }
}

/*
 * Deprecated
int F(int n, int *count) {
    if (n == 0) {
        return 3;
    } else if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 2;
    } else {
        int tmp = F(n - 2, count) + F(n - 3, count);
        *count += IsCircular(tmp);
        return tmp % 100000;
    }
}
*/

int F(int n, int *memo, int *count) {
    memo[0] = 3;
    memo[1] = 0;
    memo[2] = 2;
    int j = 0;
    for (int i = 3; i <= n; i++) {
        memo[i] = (memo[i - 2] + memo[i - 3]) % 100000;
        j = IsCircular(memo[i]);
        *count += j;
    }
    return memo[n];
}

double Squart(int target) {
    double xn = (1.0 + target) / 2.0;
    while (1) {
        xn = (xn + target / xn) / 2;
        if (xn * xn - target <= EPS) {
            break;
        }
    }
    return xn;
}

int SumupPrimesList(int target) {
    int sq = (int)Squart(target);
    int *primes = malloc(sizeof(int) * ((target / 2) + 1));
    int primeCount = 0;
    int primeSum = 0;
    int isPrime = 0;
    primes[0] = 2;
    primeCount++;
    for (int i = 3; i < target + 1; i += 2) {
        isPrime = 1;
        for (int j = 0; j < primeCount; j++) {
            if (i % primes[j] == 0) {
                isPrime = 0;
                break;
            } else {
                ;
            }
        }

        if (isPrime == 1) {
            primes[primeCount++] = i;
        } else {
            ;
        }
    }

    for (int *p = primes; *p <= primeCount; p++) {
        primeSum += primes[*p - 1];
    }
    free(primes);
    return primeSum;
}

void Q2S1() {
    int count = 0;
    int n = 0;
    scanf("%d", &n);
    int *memo = (int *)malloc(sizeof(int) * (n + 1));
    if (memo == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    memset(memo, -1, sizeof(int) * (n + 1));
    F(n, memo, &count);
    printf("%d\n", count);
}

void Q2S2() {
    int n = 0;
    scanf("%d", &n);
    printf("%d\n", SumupPrimesList(n));
}
