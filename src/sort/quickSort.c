#include "quickSort.h"
#include <string.h>

/*
    //1181 word sort problem with quick sort
    qsort / strcmp
    p1 p2
    ret < 0 : p1 p2
    ret == 0 : p1 p2
    ret > 0 : p2 p1
*/

int compare(const void *a, const void *b)
{
    if( strlen(a) == strlen(b) )
    {
        if( strcmp(a,b) == 0 )
        {
            return 0;
        }
        else if( strcmp(a,b) > 0 )
        {
            //a가 b보다 크므로.
            //b a, 큰것을 뒤로.
            return 1;
        }
        else
        {
            //a가 b보다 작으므로.
            //a b, 작은것을 앞으로.
            return -1;
        }
    }
    else if( strlen(a) > strlen(b) )
    {
        //길이가 큰것은 뒤로.
        return 1;
    }
    else
    {
        //길이가 작은것은 앞으로.
        return -1;
    }
}

int quickSortMain(void)
{
    int i = 0;
#if 1
    int num = 0;
    scanf("%d", &num);
    char word[num][51];
    for(i=0; i<num; i++)
        scanf("%s", word[i]);
#else
    int num = 13;
    char word[13][51] = {"but", "i", "wont", "hesitate", "no"
        "more", "no", "more", "it", "cannot", "wait", "im", "yours"};
#endif

    qsort(word, num, sizeof(word[0]), compare);

    for(i=0; i<num; i++)
        printf("%s\n", word[i]);

    return 0;
}
