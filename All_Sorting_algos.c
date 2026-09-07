/*
 * sort_compare.c
 * ----------------
 * Generates an array of 1000 random integers, then sorts identical
 * copies of it using Bubble Sort, Selection Sort, Insertion Sort,
 * Merge Sort, and Quick Sort. Each algorithm's execution time is measured using
 * clock() from <time.h>, printed to the console, and written to
 * "sort_times.csv" so it can be plotted later (e.g. with matplotlib).
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 1000

/* ---------- Bubble Sort ---------- */
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

/* ---------- Selection Sort ---------- */
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

/* ---------- Insertion Sort ---------- */
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/* ---------- Merge Sort ---------- */
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

/* ---------- Quick Sort ---------- */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* ---------- Helper: fill array with the same random data ---------- */
void copyArray(int dest[], int src[], int n) {
    memcpy(dest, src, n * sizeof(int));
}

int main(void) {
    srand((unsigned int)time(NULL));

    int original[SIZE];
    for (int i = 0; i < SIZE; i++) {
        original[i] = rand() % 100000;
    }

    int bubbleArr[SIZE], selectionArr[SIZE], insertionArr[SIZE], mergeArr[SIZE], quickArr[SIZE];
    copyArray(bubbleArr, original, SIZE);
    copyArray(selectionArr, original, SIZE);
    copyArray(insertionArr, original, SIZE);
    copyArray(mergeArr, original, SIZE);
    copyArray(quickArr, original, SIZE);

    clock_t start, end;
    double bubbleTime, selectionTime, insertionTime, mergeTime, quickTime;

    /* Bubble Sort */
    start = clock();
    bubbleSort(bubbleArr, SIZE);
    end = clock();
    bubbleTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    /* Selection Sort */
    start = clock();
    selectionSort(selectionArr, SIZE);
    end = clock();
    selectionTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    /* Insertion Sort */
    start = clock();
    insertionSort(insertionArr, SIZE);
    end = clock();
    insertionTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    /* Merge Sort */
    start = clock();
    mergeSort(mergeArr, 0, SIZE - 1);
    end = clock();
    mergeTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    /* Quick Sort */
    start = clock();
    quickSort(quickArr, 0, SIZE - 1);
    end = clock();
    quickTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    /* Print results to console */
    printf("Sorting %d elements:\n", SIZE);
    printf("--------------------------------\n");
    printf("Bubble Sort    : %f seconds\n", bubbleTime);
    printf("Selection Sort : %f seconds\n", selectionTime);
    printf("Insertion Sort : %f seconds\n", insertionTime);
    printf("Merge Sort     : %f seconds\n", mergeTime);
    printf("Quick Sort     : %f seconds\n", quickTime);

    /* Write results to CSV for plotting with matplotlib */
    FILE *fp = fopen("sort_times.csv", "w");
    if (fp == NULL) {
        printf("Error: could not open sort_times.csv for writing.\n");
        return 1;
    }
    fprintf(fp, "Algorithm,Time\n");
    fprintf(fp, "Bubble Sort,%f\n", bubbleTime);
    fprintf(fp, "Selection Sort,%f\n", selectionTime);
    fprintf(fp, "Insertion Sort,%f\n", insertionTime);
    fprintf(fp, "Merge Sort,%f\n", mergeTime);
    fprintf(fp, "Quick Sort,%f\n", quickTime);
    fclose(fp);

    printf("\nResults written to sort_times.csv\n");

    return 0;
}