#include "Define.cpp"


void AdaptiveInsertionSort(int v[], int N)
{
    int indiceMinimo = 0;
    for(int i = 1; i < N; i++)
        if(v[i] < v[indiceMinimo])
            indiceMinimo = i;
    swap(v[0], v[indiceMinimo]);

    for(int i = 1; i < N; i++)
    {
        int j = i, a = v[i];
        while(a < v[j-1])
        {
            v[j] = v[j-1];
            j--;
        }

        v[j] = a;
    }
}
