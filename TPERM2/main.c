#include <stdio.h>
#include <stdlib.h>

//funkcja do zamiany elementów miejscami
void inline swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char* abc, int l, int dlugosc)
{
    int i;
    if(l == dlugosc)
    {
        printf("%s\n", abc);
    }
    else
        for(i = l; i < dlugosc; i++)
        {
            swap(&abc[i], &abc[l]);
            permute(abc, l+1, dlugosc);
            swap(&abc[i], &abc[l]);
        }
}
int main()
{
    int k;    //ile liter alfabetu do permutacji; k<10
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &k);
        char abc[k];
        short i;
        for(i = 0; i < k; i++)
        {
            abc[i] = (char)(97+i);  //wypelnienie tablicy abc k pierwszymi literami alfabetu
            abc[i+1] = '\0';
        }
        //printf("%s\n", abc);
        permute(abc, 0, k);
    }
    return 0;
}
