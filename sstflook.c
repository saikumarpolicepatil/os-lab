#include <stdio.h>
#include <stdlib.h>

void sstf(int RQ[], int n, int initial) {
    int TotalHeadMovement = 0;
    int count = 0;

    while (count != n) {
        int min = 1000, d, index;

        for (int i = 0; i < n; i++) {
            d = abs(RQ[i] - initial);
            if (d < min) {
                min = d;
                index = i;
            }
        }

        TotalHeadMovement += min;
        initial = RQ[index];
        RQ[index] = -1;  // Mark the request as processed
        count++;
    }

    printf("SSTF - Total head movement: %d\n", TotalHeadMovement);
}

void c_look(int RQ[], int n, int initial) {
    int TotalHeadMovement = 0;
    int count = 0;
    int current_track = initial;

    // Sort the request queue in ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (RQ[j] > RQ[j + 1]) {
                int temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }

    // Find the position of initial track in sorted queue
    int initial_pos = 0;
    while (RQ[initial_pos] < initial)
        initial_pos++;

    // Go forward from initial track to the highest request
    for (int i = initial_pos; i < n; i++) {
        TotalHeadMovement += abs(current_track - RQ[i]);
        current_track = RQ[i];
        count++;
    }

    printf("C-LOOK - Total head movement: %d\n", TotalHeadMovement);
}

void look(int RQ[], int n, int initial) {
    int TotalHeadMovement = 0;
    int count = 0;
    int current_track = initial;

    // Sort the request queue in ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (RQ[j] > RQ[j + 1]) {
                int temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }

    // Find the position of initial track in sorted queue
    int initial_pos = 0;
    while (RQ[initial_pos] < initial)
        initial_pos++;

    // Go forward from initial track to the highest request
    for (int i = initial_pos; i < n; i++) {
        TotalHeadMovement += abs(current_track - RQ[i]);
        current_track = RQ[i];
        count++;
    }

    // Go backward from highest request to the lowest request
    for (int i = initial_pos - 1; i >= 0; i--) {
        TotalHeadMovement += abs(current_track - RQ[i]);
        current_track = RQ[i];
        count++;
    }

    printf("LOOK - Total head movement: %d\n", TotalHeadMovement);
}

int main() {
    int RQ[100], n, initial,choice;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the request sequence: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &RQ[i]);

    printf("Enter initial head position: ");
    scanf("%d", &initial);
    do
    {

    printf("enter your choice:\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:sstf(RQ, n, initial);
             break;
      case 2:c_look(RQ, n, initial);
             break;
      case 3: look(RQ, n, initial);
             break;
      default:printf("Exiting...");
               break;
    }
    }while(choice != 4);

    return 0;
}

