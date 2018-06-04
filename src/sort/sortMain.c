#include "sortMain.h"

void printSortMenu(void)
{
    printf("\n=== sort menu ===\n");
    printf("1. counting sort\n");
    printf("2. radix sort\n");
    printf("ff. exit\n");
}

void sortMain(void)
{
    int input = 0;

    while(1)
    {
        printSortMenu();
        scanf("%x", &input);

        switch(input)
        {
            case 1:
                countingSortMain();
                break;

            case 2:
                radixSortMain();
                break;

            default:
                break;
        }

        if( input == 0xff )
            break;
    }
}
