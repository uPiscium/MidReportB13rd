#include "sort.h"

void Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void BubbleSort(int *arr, int n) {
    if (n == 1) {
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            Swap(&arr[i], &arr[i + 1]);
        }
    }
    BubbleSort(arr, n - 1);
}

void QuickSort(int *arr, int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    while (1) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i >= j) {
            break;
        }
        Swap(&arr[i], &arr[j]);
        i++;
        j--;
    }

    if (left < i - 1) {
        QuickSort(arr, left, i - 1);
    }
    if (j + 1 < right) {
        QuickSort(arr, j + 1, right);
    }
}
