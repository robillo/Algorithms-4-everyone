#include "Define.cpp"


int partitionS(char s[][MAXS+1], int indici[], int l, int r){
    int i = l-1, j = r;
    while(1){
        while(strcmp(s[indici[++i]], s[indici[r]]) < 0);
        while(strcmp(s[indici[--j]], s[indici[r]]) > 0) if(j == l) break;
        if(i >= j) break;
        swap(indici[i], indici[j]);
    }
    swap(indici[i], indici[r]);
    return i;
}

void sortS(char s[][MAXS+1], int indici[], int l, int r){
    if(r <= l) return;
    uniform_int_distribution<> distr(l, r-1);
    int temp = distr(eng);
    swap(indici[temp], indici[r]);
    int mid = partitionS(s, indici, l, r);
    sortS(s, indici, l, mid - 1);
    sortS(s, indici, mid + 1, r);
}


void QuickSortS(char s[][MAXS+1], int indici[], int N)
{
    sortS(s, indici, 0, N-1);
}
