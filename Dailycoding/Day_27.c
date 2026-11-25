#include <stdio.h>

#define ROWS 3
#define COLS 4

void parkCar(int parking[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (parking[i][j] == 0)
            {
                printf("Available spot: Row %d, Column %d\n",
                       i, j);

                parking[i][j] = 1;

                printf("Car parked successfully.\n");
                return;
            }
        }
    }

    printf("Parking is full.\n");
}

int main()
{
    int parking[ROWS][COLS] = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {0, 0, 1, 1}
    };

    parkCar(parking);

    return 0;
}
