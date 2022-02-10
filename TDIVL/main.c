#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(char a[], char b[])
{
    //printf("%s - %s\n", a, b);
    int lenA = strlen(a);
    int lenB = strlen(b);
    printf("%s %i - %s %i\n", a, lenA, b, lenB);
    //jesli a jest wieksze to zwroc 1, jesi nie 0
    if(lenA < lenB) return 0;           //koniec odejmowania, nie
    else if(lenA > lenB) return 1;      //odejmuj dalej
    else
    {
        for(int i = 0; i < lenA; i++)
        {
            if(a[i] > b[i]) return 1;   //odejmuj dalej
            else if(a[i] < b[i]) return 0;  //koniec odejmowania, nie
        }
    }
    return 2;   //a = b, jest podzielna
}
void odejmij_liczbe(char *a, char *b)
{
    char *result = a;
    char znak;
    for(int i = strlen(a) - 1, j = strlen(b) - 1; i >= 0; i--, j--)   //i - index odjemnej,,,,,, j - index odjemnika
    {
        if(j < 0)
            {
                if(result[i] <= '0') {result = realloc(result+1, strlen(a)-1);i--;}
                result[i] = a[i];
                continue;
            }
        if((a[i] - b[j]) >= 0) znak = (char)(a[i] - b[j] + 48);
        else
        {
            znak = (char)(10 + (int)a[i] - (int)b[j] + 48);
            a[i-1] -= 1;
        }
        result[i] = (char)znak;
    }
}
int czy_podzielna(char a[], char b[])
{
    int resultat = max(a, b);
    if(resultat == 2) return 1;
    while(resultat != 0)
    {
        odejmij_liczbe(a, b);
        resultat = max(a, b);
        if(resultat == 2) return 1;
    }
    return 0;
}

int main()
{
    char aaa[] = "500";
    char bbb[] = "10";
    if(czy_podzielna(aaa, bbb) == 0) printf("TAK\n");
    int t;  //liczba testow
    scanf("%d", &t);

    char liczbaA[10000];
    char liczbaB[10000];
/////////////podzielnosc liczbyB przez A sprawdze odejmuj¹c rekurencyjnie b od a
    for(int i = 0; i < t; i++)
    {
        scanf("%s %s", liczbaA, liczbaB);
//        if(czy_podzielna(liczbaA, liczbaB)) printf("TAK\n");
      //  else printf("NIE\n");
    }
    return 0;
}
