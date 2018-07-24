#ifndef STATISTICS
#define STATISTICS

#include "sortMain.h"

int statisticsMain(void);
int calcAverage(int num, int tot);
int calcMode(int inputNum, int *cnt);
int calcMedian(int inputNum, int *arr, int *cnt, int* sort);
int calcRange(int min, int max);

#endif
