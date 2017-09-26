#include "Define.cpp"


void InsertionSort(int v[], int N)
{
    for(int i = 1; i < N; i++)
    {
        for(int j = i; j > 0; j--)
        {
            if(v[j] < v[j-1])
                swap(v[j], v[j-1]);
        }
    }
}
