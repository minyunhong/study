#include "statistics.h"
#include <math.h>

#define MAX_VAL 4000

//#define HONG_DEBUG    0

int statisticsMain(void)
{
    int i = 0, num = 0;
    int tot = 0, min = 0, max = 0;
    int mean = 0, median = 0, mode = 0, range = 0;
    int *sort = NULL, *cnt = NULL, *arr = NULL;
#if HONG_DEBUG
    #if 0
    int num = 5;
    int arr[5] = {1, 3, 8, -2, 2};
    printf("input 1 : 5 || 1, 3, 8, -2, 2\n");
    #endif
    #if 0
    int num = 1;
    int arr[2] = {4000, 0};
    printf("input 2 : 1 || 4000\n");
    #endif
    #if 0
    int num = 5;
    int arr[5] = {-1, -2, -3, -1, -2};
    printf("input 3 : 5 || -2, -2, -3, -1, -2\n");
    #endif
#endif

    scanf("%d", &num);
    arr = (int*)calloc(num+1, sizeof(int));
    sort = (int*)calloc(num+1, sizeof(int));
    cnt = (int*)calloc((MAX_VAL*2)+1, sizeof(int));

    for(i=0; i<num; i++)
    {
        scanf("%d", &arr[i]);

        if( i == 0 )
            tot = min = max = arr[0];
        else
            tot += arr[i];

        if( min > arr[i] )
            min = arr[i];

        if( max < arr[i] )
            max = arr[i];

        cnt[arr[i]+MAX_VAL]++;
    }

    mean = calcAverage(num, tot);
    mode = calcMode(num, cnt);
    median = calcMedian(num, arr, cnt, sort);
    range = calcRange(min, max);
#if HONG_DEBUG
    printf("num: %d, tot: %d, min: %d, max: %d \n", num, tot, min, max);
    printf("mode: %d, median: %d \n", mode, median);
#endif
    printf("%d\n%d\n%d\n%d\n", mean, median, mode, range);

#if HONG_DEBUG
    printf("result 1: 2, 2, 1, 10\n");
    printf("result 2: 4000, 4000, 4000, 0\n");
    printf("result 3: -2, -2, -1, 2\n");
#endif

#if !HONG_DEBUG
    free(arr);
    free(cnt);
    free(sort);
#endif

    return 0;
}

int calcAverage(int inputNum, int tot)
{
    int average = 0;

    if( tot > 0 )
        average = (int)(tot/(float)inputNum + 0.5);
    else
        average = (int)(tot/(float)inputNum - 0.5);

    return average;
}

int calcMode(int inputNum, int *cnt)
{
    int i = 0, index = 0, count = 0;

    for(i=MAX_VAL; i<MAX_VAL*2+1; i++)
    {
        if( count < cnt[i] )
        {
            index = i;
            count = cnt[i];
        }
    }

    for(i=MAX_VAL; i>0; i--)
    {
        if( count < cnt[i] )
        {
            index = i;
            count = cnt[i];
        }
    }

    if( index >= MAX_VAL )
        return index-MAX_VAL;
    else
        return (-1)*(MAX_VAL-index);
}

int calcMedian(int inputNum, int *arr, int *cnt, int* sort)
{
    int i = 0, median = 0;
    int *countSum = NULL;

#if HONG_DEBUG
    printf("cnt\n");
    for(i=7997; i<8002; i++)
        printf("%4d ", i);
    printf("\n");
    for(i=7997; i<8002; i++)
        printf("%4d ", cnt[i]);
    printf("\n");

    printf("arr\n");
    for(i=0; i<inputNum+1; i++)
        printf("%4d ", arr[i]);
    printf("\n");
#endif

    countSum = (int*)calloc((MAX_VAL*2)+1, sizeof(int));

    //누적합 구성.
    countSum[0] = cnt[0];
    for(i=1; i<MAX_VAL*2+1; i++)
    {
        countSum[i] = countSum[i-1]+cnt[i];

#if HONG_DEBUG
        if( i > 7997 && i < 8002 )
                printf("~~ countSum: [%d][%d] \n", i, countSum[i]);
#endif
    }

    //sort 순회.
    for(i=inputNum; i>=0; i--)
    {
        sort[countSum[arr[i]+MAX_VAL]] = arr[i];
        countSum[arr[i]+MAX_VAL]--;
    }

#if HONG_DEBUG
     printf("sort: ");
    for(i=0; i<=inputNum; i++)
        printf("%d ", sort[i]);
    printf("\n");
#endif

    median = sort[inputNum/2+1];

    return median;
}

int calcRange(int min, int max)
{
    int range = 0;

    if( min != max )
        range = abs(max - min);

    return range;
}
