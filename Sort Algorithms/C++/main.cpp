#include "Define.cpp"

#include "BubbleSort.cpp"
#include "AdaptiveInsertionSort.cpp"
#include "InsertionSort.cpp"
#include "SelectionSort.cpp"
#include "QuickSort.cpp"
#include "RandomizedQuickSort.cpp"
#include "RandomizedQuickSort with strings.cpp"
#include "RandomizedQuickSort with strings and pointers.cpp"
#include "Print.cpp"

int arr[MAXN];
char arrS[MAXN][MAXS+1];
int indici[MAXN];
char *puntatoriIndici[MAXN];

int main()
{
    int a;
    srand(time(NULL));

    for(int i = 0; i < MAXN; i++)
        for(int j = 0; j < MAXS; j++)
            arrS[i][j] = rand()%(90 - 65+1) + 65;

    for(int i = 0; i < MAXN; i++)
        arrS[i][MAXS] = '\0';

    for(int i = 0; i < MAXN; i++)
        puntatoriIndici[i] = arrS[i];

    print_Strings_Pointers(puntatoriIndici, MAXN);
    QuickSortSP(puntatoriIndici, MAXN);
    print_Strings_Pointers(puntatoriIndici, MAXN);

}
