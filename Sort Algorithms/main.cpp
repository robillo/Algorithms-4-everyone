#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "BubbleSort.cpp"
#include "InsertionSort.cpp"
#define MAXN 10


void stampa(int v[], int N)
{
    for(int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int arr[MAXN];

int main()
{
    srand(time(NULL));
    for(int i = 0; i < MAXN; i++)
        arr[i] = rand()%100;

    stampa(arr, MAXN);
    BubbleSort(arr,MAXN);
    stampa(arr, MAXN);
}
