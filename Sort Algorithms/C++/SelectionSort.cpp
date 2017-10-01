#include "Define.cpp"


void SelectionSort(int v[], int N)
{
    for(int i = 0; i < N; i++)
    {
        int indiceMinimo = i;
        for(int j = i; j < N; j++)
            if(v[j] < v[indiceMinimo])
                indiceMinimo = j;
        swap(v[i], v[indiceMinimo]);
    }
}
