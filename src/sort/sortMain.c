#include "sortMain.h"

void printSortMenu(void)
{
    printf("\n=== sort menu ===\n");
    printf("1. counting sort\n");
    printf("2. radix sort\n");
    printf("3. quick sort\n");
    printf("4. statistics\n");
    printf("ff. go previous menu\n");
    printf("ee. exit\n");
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

            case 3:
                quickSortMain();
                break;

            case 4:
                statisticsMain();

            default:
                break;
        }

        if( input == 0xff )
            break;

        if( input == 0xee )
            exit(0);
    }
}
