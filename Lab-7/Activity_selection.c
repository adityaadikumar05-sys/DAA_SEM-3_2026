#include <stdio.h>

typedef struct {
    int id;
    int start;
    int finish;
} Activity;

// Sort activities according to finish time
void sortActivities(Activity a[], int n) {
    int i, j;
    Activity temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j].finish > a[j + 1].finish) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void activitySelection(Activity a[], int n) {
    sortActivities(a, n);

    printf("\nSelected Activities:\n");

    // Always select the first activity
    printf("A%d (%d, %d)\n",
           a[0].id, a[0].start, a[0].finish);

    int lastFinish = a[0].finish;

    for (int i = 1; i < n; i++) {

        // Select activity if it does not overlap
        if (a[i].start >= lastFinish) {
            printf("A%d (%d, %d)\n",
                   a[i].id, a[i].start, a[i].finish);

            lastFinish = a[i].finish;
        }
    }
}

int main() {
    int n;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    Activity a[n];

    printf("Enter start and finish time of each activity:\n");

    for (int i = 0; i < n; i++) {
        a[i].id = i + 1;

        printf("Activity A%d: ", i + 1);
        scanf("%d %d", &a[i].start, &a[i].finish);
    }

    activitySelection(a, n);

    return 0;
}