void print_Int(int v[], int N)
{
    for(int i = 0; i < N; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void print_Strings(char v[][MAXS+1], int N)
{
    for(int i = 0; i < N; i++)
        printf("%s\n", v[i]);
    printf("\n");
}

void print_Strings_Indices(char v[][MAXS+1], int indici[], int N)
{
    for(int i = 0; i < N; i++)
        printf("%s\n", v[indici[i]]);
    printf("\n");
}

void print_Strings_Pointers(char *v[], int N)
{
    for(int i = 0; i < N; i++)
        printf("%s\n", v[i]);
    printf("\n");
}
