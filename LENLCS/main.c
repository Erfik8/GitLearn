/// BEZPRZEC
/// AUTOR - DARIUSZ SURDEL
/// GRUPA 14
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

int main()
{
    int D;
    scanf("%d", &D);
    int k;
    int lenU, lenV;  //zmienne zawierajace dlugosci danych slow
    for(k = 0; k < D; k++)
    {
        //pierwsze slowo
        scanf("%d", &lenU);
        char *u = malloc(lenU * sizeof(char));  //dynamiczna tablica znakow - tekst
        scanf("%s", u);
        //drugie slowo
        scanf("%d", &lenV);
        char *v = malloc(lenV * sizeof(char));  //dynamiczna tablica znakow - tekst
        scanf("%s", v);

        ///Algorytm NWP
        int w[2][lenV + 1];  //deklaracja tablicy dwuwymiarowej na potrzeby algorytmu
        int i, j, l, m;   //zmienne do pętli for
        w[0][0] = w[1][0] = 0;
        for(i = 0; i <= lenV; i++)  w[0][i] = 0;

        for(l = 0; l < lenU; l++)
        {
            for(j = 1, m = 0; j <= lenV; j++, m++)
            {
                if(u[l] == v[m])
                {
                    if(l%2 == 0)
                        w[1][j] = w[0][j-1]+1;
                    else
                        w[0][j] = w[1][j-1]+1;
                }
                else
                {
                    if(l%2 == 0)
                        w[1][j] = max(w[0][j], w[1][j-1]);
                    else
                        w[0][j] = max(w[0][j-1], w[1][j]);
                }

            }
        }
        printf("%d\n", max(w[1][lenV], w[0][lenV]));
        free(u);
        free(v);
    }

    return 0;
}
