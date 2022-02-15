//---------------------------------------------------
//
// Autor: Kamil Urbanowski
// Politechnika Krakowska - Informatyka Rok I
// Grupa ćwieczeniowa: 4, labolatoryjna: 7
//
//---------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int nwd(int, int);

int main()
{
    int tests, i;
    printf("Podaj liczbe testow: ");
    scanf("%d", &tests);
    //---------------------------------------------------
    //## pobieramy liczbe badanych testow do wykonania
    //---------------------------------------------------

    for (i = 0; i < tests; i++)
    {
        int wanted_number;
        printf("Podaj poszukiwana cyfre: ");
        scanf("%d", &wanted_number);
        //---------------------------------------------------
        //## pobieramy od użytkownika numery którcyh chcemy poznać pozycje w ciągu ekg

        //## jeśli te numery to 1 lub 2 to wypisujemy od razu ponieważ znamy pozycje
        //---------------------------------------------------
        if (wanted_number == 1)
        {
            printf("Twoja cyfra znajduje sie na miejscu 1\n");
        }
        else if (wanted_number == 2)
        {
            printf("Twoja cyfra znajduje sie na miejscu 2\n");
        }
        else
        {
            //---------------------------------------------------
            //## rozważamy pozostałe przypadki
            //---------------------------------------------------
            int array_lenght = 0;
            int j, k, l, m, m_bool = 1, array_lenght = wanted_number * 3 - 1, array[array_lenght];

            //---------------------------------------------------
            //## tworzymy tablice z wczesniej zapisanymi wartościami 1 i 2, które jak w.w. "już znamy"
            //---------------------------------------------------
            for (j = 0; j < 2; j++)
            {
                array[j] = j + 1;
                //printf("%d ", array[j]);
            }

            //---------------------------------------------------
            //## reszte tablicy wypełniamy zerami
            //---------------------------------------------------
            for (j = 2; j < array_lenght; j++)
            {

                array[j] = 0;
            }
            //printf("\n");

            //---------------------------------------------------
            //## potrzebna jest pętla w pętli w celu przeadania każdego możliwego przypadku i kombinacji liczb
            //## pętla zaczyna się od indeksu 2, ponieważ pomijamy wartości 1 i 2 jak w.w.
            //---------------------------------------------------
            for (j = 2; j < wanted_number * 3 + 3; j++)
            {
                //printf("pierwszy for poczatek\n");

                //---------------------------------------------------
                //## ta pętla zaczyna się od 3 ponieważ nie potrzebujemy już zaczynać od 2 (brak nadmiernych powtórzeń)
                //---------------------------------------------------
                for (k = 3; k < wanted_number * 3 + 2; k++)
                {
                    //printf("%d %d\n", j, k);
                    //printf("drugi for poczatek\n");

                    //---------------------------------------------------
                    //## sprawdzamy czy już dana wartość nie występuję w naszeym ciągu
                    //---------------------------------------------------
                    for (m = 0; m < array_lenght; m++)
                    {
                        if (array[m] == k)
                            m_bool = 0;
                    }

                    //---------------------------------------------------
                    //## jeżeli nie ma, szukamy nwd i sprawdzamy czy liczby nie są takie same
                    //---------------------------------------------------
                    if (nwd(j, k) != 1 && j != k && m_bool == 1)
                    {
                        for (l = 0; l < array_lenght; l++)
                        {
                            if (array[l] == 0)
                            {
                                //printf("znalazl puste miejsce\n");
                                //printf("warunek dodawania do tablicy poprzedni element: %d  elemnt do wsadzenia: %d  jego indeks: %d\n", array[l-1], k, l);

                                //---------------------------------------------------
                                //## szukamy najblższego indeksu o wartości zero (po to wypełnialiśmy wcześniej talice zerami)
                                //---------------------------------------------------
                                array[l] = k;

                                //---------------------------------------------------
                                //## potrzebujemy cofnąć się do niektórych liczb i ta linijka właśnie to robi
                                //## (np. liczba 3, która jest za 6)
                                //---------------------------------------------------
                                j = k - 1;
                                break;
                                //---------------------------------------------------
                                //## nie potrzebujemy iterować się dalej więc przerywamy
                                //---------------------------------------------------

                                //printf("podmiana tablicy po %d\n", array[l]);
                            }
                        }
                        break;
                    }
                    m_bool = 1;
                    //---------------------------------------------------
                    //## zmieniamy wartośc na 'true' aby kolejne liczby mogły wejść w instrukcje 'if'
                    //---------------------------------------------------
                    //printf("koniec fora drugiego\n");
                }
            }
            //-------------------------------------------------------------------------
            //## jak w wielu miejscach jest tu dużo printf'ów w celach informacyjnych
            //## ten akurat wypisuje całą tablicę bezbłędnych wartości ciągu
            //-------------------------------------------------------------------------
            /*for(j = 0; j < wanted_number*2+2; j++)
            {
                printf("%d ", array[j]);
            }
            printf("\n");*/
            //---------------------------------------------------
            //## końcowy wynik szukany i wypisywany jest tutaj
            //---------------------------------------------------
            for (j = 0; j < array_lenght; j++)
            {
                if (array[j] == wanted_number)
                    printf("'%d' znajduje sie na pozycji %d\n", array[j], j + 1);
            }
        }
    }
    return 0;
}

int nwd(int a, int b)
{
    //---------------------------------------------------
    //## standardowa funkcja rekurencyjna licząca nwd
    //---------------------------------------------------
    if (a != b)
        return nwd(a > b ? a - b : a, b > a ? b - a : b);
    return a;
}