
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int f[50], p, i, j, k, a, st, len, c;

    // Initialize all 50 blocks as free
    for (i = 0; i < 50; i++)
        f[i] = 0;

    printf("Enter how many blocks are already allocated: ");
    scanf("%d", &p);

    printf("Enter the block numbers that are already allocated:\n");
    for (i = 0; i < p; i++)
    {
        scanf("%d", &a);
        if (a >= 0 && a < 50)
            f[a] = 1;
        else
            printf("Invalid block number ignored!\n");
    }

X:
    printf("\nEnter the starting index block and length of the file: ");
    scanf("%d %d", &st, &len);

    if (st < 0 || st >= 50)
    {
        printf("Invalid starting block!\n");
        goto X;
    }

    k = len;

    for (j = st; j < (st + k) && j < 50; j++)
    {
        if (f[j] == 0)
        {
            f[j] = 1;
            printf("\n%d -> Allocated", j);
        }
        else
        {
            printf("\n%d -> Already allocated", j);
            k++;  
        }
    }

    if (j >= 50)
        printf("\nReached end of block range. Allocation incomplete!");

    printf("\n\nDo you want to enter one more file? (1 = Yes / 0 = No): ");
    scanf("%d", &c);

    if (c == 1)
        goto X;
    else
        exit(0);
}

