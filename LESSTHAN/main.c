/// LESSTHAN
/// AUTOR - DARIUSZ SURDEL
/// GRUPA 14
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int czy_mniejsza(char *a, char *b)
{
    if(strlen(a) == strlen(b))  //jesli ilosc cyfr jest taka sama to porownywanie kazdej kolejnej
        {
            for(int i = 0; i < strlen(a); i++)
            {
                if(a[i] < b[i]) return 1;
                else if(a[i] > b[i]) return 0;
            }
        }
    else if(strlen(a) < strlen(b)) return 1;    //jesli pierwsza liczba ma mniej cyfr to znaczy ze jest mniejsza
    return 0;   //jesli ma wiecej to znaczy ze wieksza
}

int main()
{
/////////////////////////////////tablica a
    int n;
    scanf("%d", &n);

    char **tabA = (char**)malloc(n * sizeof(char*));   //tworze tablice A na n napisow, bo typy liczbowe maja za maly zakres
    for(int i = 0; i < n; i++)
    {
        tabA[i] = (char*)malloc(30 * sizeof(char)); //napis/liczba max 29 cyfr
        scanf("%s", tabA[i]);
    }

/////////////////////////////////tablica b
    int k;
    scanf("%d", &k);

    char **tabB = (char**)malloc(k * sizeof(char*));
    for(int i = 0; i < k; i++)
    {
        tabB[i] = (char*)malloc(30 * sizeof(char)); //napis/liczba max 29 cyfr
        scanf("%s", tabB[i]);
    }
/////////////////////////////////
//tu testowalem czy sie dobrze tablice wypelnily
    /*for(int i = 0; i < n; i++)
    {
        printf("TAB A   %s - %d\n", tabA[i], strlen(tabA[i]));
    }
    for(int i = 0; i < k; i++)
    {
        printf("TAB B   %s - %d\n", tabB[i], strlen(tabB[i]));
    }*/

    int suma = 0;
    //porownywanie kazdej liczby z tablicyB z ka¿d¹ z tablicyA
    for(int i = 0; i < k; i++)  //tabB
    {
        suma = 0;
        for(int j = 0; j < n; j++)  //tabA
        {
            suma += czy_mniejsza(tabA[j], tabB[i]);
        }
        printf("%d\n", suma);
    }


//////////////////////////////////Zwalnianie pamieci
    for(int i = 0; i < n; i++)
    {
        free(tabA[i]);   //usuwanie kazdego napisu
    }
    for(int i = 0; i < k; i++)
    {
        free(tabB[i]);   //usuwanie kazdego napisu
    }
    free(tabA);  //usuwanie calej tabeli
    free(tabB);

    return 0;
}
