//2. Write a program to count the frequency of each distinct element in an array.

#include<stdio.h>

void countFrequency(int arr[], int n) {  //created a function called countfrequency
    int visited[n];
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Element | Frequency\n");
    printf("-------------------\n");
    for (int i = 0; i < n; i++) {
        if (visited[i] == 1) {
            continue;
        }

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = 1;
                count++;
            }
        }
        printf("%-7d | %-9d\n", arr[i], count);
    }
}

int main() {
    int arr[] = {10, 20, 20, 10, 10, 20, 5, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    countFrequency(arr, n);
    return 0;
}
