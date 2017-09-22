#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "BubbleSort.cpp"
#include "AdaptiveInsertionSort.cpp"
#include "InsertionSort.cpp"
#include "SelectionSort.cpp"
#define MAXN 10


void stampa(int v[], int N)
{
    for(int i = 0; i < N; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int arr[MAXN];

int main()
{
    srand(time(NULL));
    for(int i = 0; i < MAXN; i++)
        arr[i] = rand()%100;

    //stampa(arr, MAXN);
    SelectionSort(arr,MAXN);
    stampa(arr, MAXN);

    for(int i = 0; i < MAXN; i++)
        arr[i] = rand()%100;

    //stampa(arr, MAXN);
    InsertionSort(arr,MAXN);
    stampa(arr, MAXN);

    for(int i = 0; i < MAXN; i++)
        arr[i] = rand()%100;

    //stampa(arr, MAXN);
    AdaptiveInsertionSort(arr,MAXN);
    stampa(arr, MAXN);

    for(int i = 0; i < MAXN; i++)
        arr[i] = rand()%100;

    //stampa(arr, MAXN);
    BubbleSort(arr,MAXN);
    stampa(arr, MAXN);

}
