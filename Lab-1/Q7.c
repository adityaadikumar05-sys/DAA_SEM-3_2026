/**7. Write a C program to rotate an array to the right by K positions without using another array.
Array: 1 2 3 4 5 6 K = 2
Output: 5 6 1 2 3 4
 */


#include <stdio.h>

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotateArray(int arr[], int n, int k) {
    k = k % n; // In case k is greater than n
    if (k < 0) { // Handle negative k
      k = k + n;
    }

    reverse(arr, 0, n - 1);
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    printf("Original array: ");
    printArray(arr, n);

    rotateArray(arr, n, k);

    printf("Rotated array: ");
    printArray(arr, n);

    return 0;
}
