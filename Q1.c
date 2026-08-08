//1. Write a C program to find the second-largest distinct element in an array without sorting it

#include <stdio.h>
#include <limits.h> //to limit the array elements

void findSecondLargest(int arr[], int n) {
    if (n < 2) {
        printf("Array should have at least two elements.\n");
        return;
    }

    int first = INT_MIN, second = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] < first) {
            second = arr[i];
        }
    }

    if (second == INT_MIN) {
        printf("There is no second-largest element.\n");
    } else {
        printf("The second-largest distinct element is %d\n", second);
    }
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    findSecondLargest(arr, n);
    return 0;
}
