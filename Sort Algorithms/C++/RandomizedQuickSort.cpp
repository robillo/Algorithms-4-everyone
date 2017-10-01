#include "Define.cpp"

int partitionR(int v[], int l, int r){
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

void sortR(int v[], int l, int r){
    if(r <= l) return;
    uniform_int_distribution<> distr(l, r-1);
    int temp = distr(eng);
    swap(v[temp], v[r]);
    //printf("%d %d %d\n", temp, l, r);
    int mid = partitionR(v, l, r);
    sortR(v, l, mid - 1);
    sortR(v, mid + 1, r);
}

void QuickSortR(int v[], int N)
{
    sortR(v, 0, N-1);
}
