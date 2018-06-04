#include "countingSort.h"

int countingSortMain(void)
{
    int num =0, i = 0, j = 0, input = 0;
    int *arr = NULL;

    scanf("%d", &num);

    arr = (int*)calloc(num, sizeof(int));

    for(i=0; i<num; i++)
    {
        scanf("%d", &input);
        arr[input]++;
    }

    countingSort(arr, num);

    for(i=0;  i<num; i++)
    {
        printf("%d\n", arr[i]);
    }

    free(arr);
    arr = NULL;
    return 0;
}

void countingSort(int *count, int inputNum)
{
    int i = 0;

    for(i=1; i<=inputNum; i++)
    {
        //to do..
    }
}
