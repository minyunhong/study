#include "countingSort.h"

#define MAX_NUM 10000

int countingSortMain(void)
{
    int maxinput =0, i = 0;
    int *arr = NULL, *sort = NULL;

    scanf("%d", &maxinput);

    arr = (int*)calloc(maxinput, sizeof(int));
    sort = (int*)calloc(maxinput+1, sizeof(int));

    for(i=0; i<maxinput; i++)
    {
        scanf("%d", &arr[i]);
    }

    countingSort(arr, maxinput, sort);

    for(i=1;  i<=maxinput; i++)
        printf("%d", sort[i]);

    printf("\n");
    free(arr);
    free(sort);
    return 0;
}

void countingSort(int *num, int inputNum, int *sort)
{
    int i = 0;
    int *count = NULL;

    count = (int*)calloc(MAX_NUM, sizeof(int));
    for(i=0; i<inputNum; i++)
        count[num[i]]++;

    for(i=1; i<=MAX_NUM; i++)
        count[i] += count[i-1];

    for(i=0; i<=MAX_NUM; i++)
    {
        sort[count[num[i]]] = num[i];
        count[num[i]]--;
    }

    free(count);
}
