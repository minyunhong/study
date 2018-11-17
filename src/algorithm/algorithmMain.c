#include "algorithmMain.h"

void printAlgorithmMenu(void)
{
    printf("\n=== algorithm menu ===\n");
    printf("1. get area (2583) \n");
    printf("ee. exit\n");
}

void algorithmMain(void)
{
    int input = 0;

    while(1)
    {
        printAlgorithmMenu();
        scanf("%x", &input);

        switch(input)
        {
            case 1:
                getAreaMain();

            default:
                break;
        }

        if( input == 0xff )
            break;

        if( input == 0xee )
            exit(0);
    }
}
