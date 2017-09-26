#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "BubbleSort.cpp"
#include "AdaptiveInsertionSort.cpp"
#include "InsertionSort.cpp"
#include "SelectionSort.cpp"
#include "QuickSort.cpp"
#include "RandomizedQuickSort.cpp"
#include "RandomizedQuickSort with strings.cpp"

#include "Define.cpp"

int arr[MAXN];
char arrS[MAXN][MAXS+1];

int main()
{
    int a;
    srand(time(NULL));

    for(int i = 0; i < MAXN; i++)
        for(int j = 0; j < MAXS; j++)
            arrS[i][j] = rand()%(90 - 65+1) + 65;

    for(int i = 0; i < MAXN; i++)
        arrS[i][MAXS] = '\0';

    stampaS(arrS, MAXN);
    printf("\n");
    QuickSortS(arrS, MAXN);
    stampaSI(s, indici, N);
}
