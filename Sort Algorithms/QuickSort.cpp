#include "Define.cpp"


int partition(int v[], int l, int r){
    int i = l-1, j = r;
    while(1){
        while(v[++i] < v[r]);
        while(v[--j] > v[r]) if(j == l) break;
        if(i >= j) break;
        swap(v[i], v[j]);
    }
    swap(v[i], v[r]);
    return i;
}

void sort(int v[], int l, int r){
    if(r <= l) return;
    int mid = partition(v, l, r);
    sort(v, l, mid - 1);
    sort(v, mid + 1, r);
}

void QuickSort(int v[], int N)
{
    sort(v, 0, N-1);
}
