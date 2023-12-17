#include "Q1.h"

void GetArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void Q1S1() {
    int M = 0, N = 0;
    printf("Input of 'M' : ");
    scanf("%d", &M);
    printf("Input of 'N' : ");
    scanf("%d", &N);
    printf("Input of Array : ");
    int *arr = (int *)malloc(sizeof(int) * M);
    GetArray(arr, M);
#ifdef USE_QUICK_SORT
    QuickSort(arr, 0, M - 1);
#else
    BubbleSort(arr, M);
#endif
    int min = 0, max = 0;
    for (int i = 0; i < ((M - N > M / 2) ? N : M - N); i++) {
        min += arr[i];
        max += arr[M - i - 1];
    }
    printf("output : %d\n", max - min);
    free(arr);
}

void Q1S2() {
    int N = 0;
    printf("Input of 'N' : ");
    scanf("%d", &N);
    int **mat = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++) {
        mat[i] = (int *)malloc(sizeof(int) * N);
        printf("Input of %d-th row : ", i + 1);
        GetArray(mat[i], N);
    }

    int *arr = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < 2 * N - 1; i++) {
        int end = 0;
        if (i < N) {
            end = i + 1;
            for (int j = 0; j < end; j++) {
                arr[j] = mat[j][N - end + j];
            }
#ifdef USE_QUICK_SORT
            QuickSort(arr, 0, end - 1);
#else
            BubbleSort(arr, end);
#endif
            for (int j = 0; j < end; j++) {
                mat[j][N - end + j] = arr[end - j - 1];
            }
        } else {
            end = 2 * N - i;
            for (int j = 0; j < end; j++) {
                arr[j] = mat[N - end + j][j];
            }
#ifdef USE_QUICK_SORT
            QuickSort(arr, 0, end - 1);
#else
            BubbleSort(arr, end);
#endif
            for (int j = 0; j < end; j++) {
                mat[N - end + j][j] = arr[end - j - 1];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    free(arr);
    for (int i = 0; i < N; i++) {
        free(mat[i]);
    }
    free(mat);
}
