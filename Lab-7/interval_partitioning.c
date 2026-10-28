#include <stdio.h>

typedef struct {
    int id;
    int start;
    int finish;
} Interval;

// Sort intervals according to start time
void sortIntervals(Interval a[], int n) {
    int i, j;
    Interval temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {

            if (a[j].start > a[j + 1].start) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void intervalPartition(Interval a[], int n) {

    sortIntervals(a, n);

    // Stores finish time of last interval in each room
    int roomFinish[n];

    int rooms = 0;

    printf("\nInterval Assignment:\n");

    for (int i = 0; i < n; i++) {

        int assigned = 0;

        // Check existing rooms
        for (int j = 0; j < rooms; j++) {

            if (a[i].start >= roomFinish[j]) {

                printf("Interval I%d (%d, %d) -> Room %d\n",
                       a[i].id,
                       a[i].start,
                       a[i].finish,
                       j + 1);

                roomFinish[j] = a[i].finish;

                assigned = 1;
                break;
            }
        }

        // If no existing room is available,
        // create a new room
        if (!assigned) {

            roomFinish[rooms] = a[i].finish;

            printf("Interval I%d (%d, %d) -> Room %d\n",
                   a[i].id,
                   a[i].start,
                   a[i].finish,
                   rooms + 1);

            rooms++;
        }
    }

    printf("\nMinimum number of rooms required = %d\n", rooms);
}

int main() {

    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    Interval a[n];

    printf("Enter start and finish time of each interval:\n");

    for (int i = 0; i < n; i++) {

        a[i].id = i + 1;

        printf("Interval I%d: ", i + 1);
        scanf("%d %d", &a[i].start, &a[i].finish);
    }

    intervalPartition(a, n);

    return 0;
}