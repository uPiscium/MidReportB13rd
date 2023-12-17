#include "Q1.h"
#include "Q2.h"
#include <time.h>

// #define USE_QUICK_SORT

void MeasureTime(void (*func)()) {
    clock_t start = clock();
    func();
    clock_t end = clock();
    printf("Time : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
}

int main() {
    Q2S2();
    return 0;
}
