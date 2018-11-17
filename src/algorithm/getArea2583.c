#include "getArea2583.h"
#include <stdbool.h>

bool map[101][101];
bool visit[101][101];
int result[101];
int cnt = 0, area = 0;

#define TC 0
#if TC
int m = 5, n = 7, k = 3;
int tc[101][101] = {{0,2,4,4}, {1,1,2,5}, {4,0,6,2}};
#else
int m = 0, n = 0, k = 0;
#endif

void makeMap()
{
#if TC
	for(int i=0; i<k; i++)
	{
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		x1 = tc[i][0];
		y1 = tc[i][1];
		x2 = tc[i][2];
		y2 = tc[i][3];
		for(int k=y1; k<y2; k++)
		{
			for(int l=x1; l<x2; l++)
				map[k][l] = true;
		}
	}
#else
	scanf("%d%d%d", &m,&n,&k);
	for(int i=0; i<k; i++)
	{
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		scanf("%d%d%d%d", &x1,&y1,&x2,&y2);
		for(int k=y1; k<y2; k++)
		{
			for(int l=x1; l<x2; l++)
				map[k][l] = true;
		}
	}
#endif
}

void printMap()
{
	printf("map--------------------------------\n");
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("map--------------------------------\n");
}

void printVisit()
{
	printf("visit*****************************\n");
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("%d ", visit[i][j]);
		}
		printf("\n");
	}
	printf("visit*****************************\n");
}

int globaltemp = 0;

void calcArea(int i, int j)
{
	visit[i][j] = true;
	area++;

	//오른쪽
	if( j < n-1 && !map[i][j+1] && !visit[i][j+1] )
		calcArea(i,j+1);
	//왼쪽
	if( j > 0 && !map[i][j-1] && !visit[i][j-1] )
		calcArea(i,j-1);
	//위
	if( i > 0 && !map[i-1][j] && !visit[i-1][j] )
		calcArea(i-1,j);
	//아래
	if( i < m-1 && !map[i+1][j] && !visit[i+1][j] )
		calcArea(i+1,j);
}

int getArea()
{
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
#if TC
			printMap();
			printVisit();
			printf("i:%d j: %d\n", i,j);
#endif
			if( map[i][j] != true && !visit[i][j])
			{
				area = 0;
				calcArea(i, j);
				result[cnt++] = area;
			}
		}
	}
}

int compareFunc(const void* a, const void* b)
{
    if( *(int*)a > *(int*)b )
        return 1;
    else if( *(int*)a < *(int*)b )
        return -1;
    else
        return 0;
}

void printResult(void)
{
	printf("%d\n", cnt);

	qsort(result, cnt, sizeof(int), compareFunc);

	for(int i=0; i<cnt; i++)
		printf("%d ", result[i]);

}

int getAreaMain(void)
{
	makeMap();
	getArea();
	printResult();

	return 0;
}