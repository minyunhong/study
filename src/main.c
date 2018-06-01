#include "../include/sortMain.h"

void printMainMenu(void)
{
    printf("\n=== main menu ===\n");
    printf("1. sort\n");
    printf("ff. exit\n");
}

int main(void)
{
    int input = 0;

    while(1)
    {
        printMainMenu();
        scanf("%x", &input);

        switch(input)
        {
            case 1:
                sortMain();
                break;

            default:
                break;
        }

        if( input == 0xff )
            break;
    }

    return 0;
}
