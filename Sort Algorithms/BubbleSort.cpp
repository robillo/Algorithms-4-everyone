#include "Define.cpp"


void BubbleSort(int v[], int N)
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N - i - 1; j++)
            if(v[j] > v[j+1])
                swap(v[j+1], v[j]);
}
