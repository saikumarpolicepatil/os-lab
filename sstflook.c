#include <stdio.h>
#include <stdlib.h>

void sstf(int RQ[], int n, int initial, int TotalHeadMovement)
{     
    int count = 0,i;
     printf("Seek Sequence: ");
    while (count != n) {
        int min = 1000, d, index;

        // Find the nearest request in the queue
        for (i = 0; i < n; i++) {
            d = abs(RQ[i] - initial);
           
            if (min > d) {
                min = d;
                index = i;
            }
        }

        // Print the current request being serviced
        printf("%d ", RQ[index]);

        // Update total head movement and current head position
        TotalHeadMovement = TotalHeadMovement + min;
        initial = RQ[index];

        // Mark the processed request as visited
        RQ[index] = 1000;
        count++;
    }

    // Output the total head movement
    printf("\nTotal head movement is %d\n", TotalHeadMovement);
}

void look(int RQ[], int n, int initial, int move, int TotalHeadMovement) 
{
    // LOOK logic
    int i,j,size;
    printf("Enter total disk size\n");
    scanf("%d", &size);
     // Sorting the request array
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (RQ[j] > RQ[j + 1]) {
                int temp;
                temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }

    int index;
    for (i = 0; i < n; i++) {
        if (initial < RQ[i]) {
            index = i;
            break;
        }
    }

    printf("Seek Sequence: ");
    // If movement is towards high value
    if (move == 1) {
        for (i = index; i < n; i++) {
            printf("%d ", RQ[i]);
            TotalHeadMovement = TotalHeadMovement + abs(RQ[i] - initial);
            initial = RQ[i];
        }
        for (i = index - 1; i >= 0; i--) {
            printf("%d ", RQ[i]);
            TotalHeadMovement = TotalHeadMovement + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    // If movement is towards low value
    else {
        for (i = index - 1; i >= 0; i--) {
            printf("%d ", RQ[i]);
            TotalHeadMovement = TotalHeadMovement + abs(RQ[i] - initial);
            initial = RQ[i];
        }
        for (i = index; i < n; i++) {
            printf("%d ", RQ[i]);
            TotalHeadMovement = TotalHeadMovement + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }

    // Output the total head movement
    printf("\nTotal head movement is %d\n", TotalHeadMovement);
}

void clook(int RQ[], int n, int initial, int move, int TotalHeadMovement)
{
    // C-LOOK logic
    int i,j,size;
    printf("Enter total disk size\n");
    scanf("%d", &size);
    // Sorting the request array
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (RQ[j] > RQ[j + 1]) {
                int temp;
                temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }

    int index;
    for (i = 0; i < n; i++) {
        if (initial < RQ[i]) {
            index = i;
            break;
        }
    }

    printf("Seek Sequence: ");
    // If movement is towards high value
    if (move == 1) {
        for (i = index; i < n; i++) {
            printf("%d ", RQ[i]);
            TotalHeadMovement = TotalHeadMovement + abs(RQ[i] - initial);
            initial = RQ[i];
        }
        for (i = 0; i < index; i++) {
            printf("%d ", RQ[i]);
            TotalHeadMovement = TotalHeadMovement + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    // If movement is towards low value
    else {
        for (i = index - 1; i >= 0; i--) {
            printf("%d ", RQ[i]);
            TotalHeadMovement = TotalHeadMovement + abs(RQ[i] - initial);
            initial = RQ[i];
        }
        for (i = n - 1; i >= index; i--) {
            printf("%d ", RQ[i]);
            TotalHeadMovement = TotalHeadMovement + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }

    // Output the total head movement
    printf("\nTotal head movement is %d\n", TotalHeadMovement);
}

int main() 
{
    int choice, n, RQ[100], initial, move, i, TotalHeadMovement = 0;

    printf("Enter the number of Requests: ");
    scanf("%d", &n);

    printf("Enter the Requests sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);

    printf("Enter initial head position: ");
    scanf("%d", &initial);

    printf("Enter the head movement direction (1 for high, 0 for low): ");
    scanf("%d", &move);

    do {
        printf("\nChoose the scheduling algorithm:\n");
        printf("1. SSTF\n2. LOOK\n3. C-LOOK\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // SSTF
                sstf(RQ, n, initial, TotalHeadMovement);
                break;

            case 2: // LOOK
                look(RQ, n, initial, move, TotalHeadMovement);
                break;

            case 3: // C-LOOK
                clook(RQ, n, initial, move, TotalHeadMovement);
                break;

            case 4: // Exit
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    }while (choice != 4);

   return 0;
}
