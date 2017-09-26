#include "Define.cpp"


int partitionSP(char *indici[], int l, int r)
{
    int i = l-1, j = r;
    while(1)
    {
        while(strcmp(indici[++i], indici[r]) < 0);
        while(strcmp(indici[--j], indici[r]) > 0) if(j == l) break;
        if(i >= j) break;
        swap(indici[i], indici[j]);
        //stampaP(indici, MAXN);
    }
    swap(indici[i], indici[r]);
    return i;
}

void sortSP(char *indiciP[], int l, int r)
{
    if(r <= l) return;
    uniform_int_distribution<> distr(l, r-1);
    int temp = distr(eng);
    swap(indiciP[temp], indiciP[r]);
    int mid = partitionSP(indiciP, l, r);
    sortSP(indiciP, l, mid - 1);
    sortSP(indiciP, mid + 1, r);
}


void QuickSortSP(char *indiciP[], int N)
{
    sortSP(indiciP, 0, N-1);
}
