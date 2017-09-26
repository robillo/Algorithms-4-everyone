#ifndef Define
#define Define

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <random>
#define MAXN 10
#define MAXS 10 //max string lenght

using namespace std;

random_device rd;
mt19937 eng(rd());

void stampa(int v[], int N)
{
    for(int i = 0; i < N; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void stampaS(char v[][MAXS+1], int N)
{
    for(int i = 0; i < N; i++)
            printf("%s\n", v[i]);
}

void stampaSI(char v[][MAXS+1], int indici[], int N)
{
    for(int i = 0; i < N; i++)
            printf("%s\n", v[indici[i]]);
}

#endif //Define
