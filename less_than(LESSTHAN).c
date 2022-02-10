#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
	Program dzieli się na 2 częsci
	1. Wczytanie wszystkich liczb do tablicy wraz z posortowaniem (sortowanie quick_sort)
	2. Policzenie dla każdej liczby 'i' liczby elementów w tablicy, które są mniejsze od tej liczby

	Posortowanie tablicy ułatwia i przyśpiesza znalezienie takiej liczby elementów w tablicy, które są mniejsze
*/

void quick_sort(char **tab, int left, int right)
{
	/*
		Wariant algorytmu quick sort bez elementu pivot
		sprawdza tylko elementy na znacznikach 'left' i 'right'
		do momentu, kiedy oba znaczniki się ze sobą spotkają
		Przy zamianie elementów przesuwany jest drugi znacznik
	*/
	if(left >= right) return;
	int save_left = left;
	int save_right = right;
	int swap_order = 0; // 0 - move left pointer, 1 - move right pointer;
	while(left != right)
	{
		if(strlen(tab[left]) > strlen(tab[right]))
		{
			/*
				Warunek, kiedy któraś liczba ma więcej cyfr
			*/
			char *temp = strdup(tab[left]);
			tab[left] = strdup(tab[right]);
			tab[right] = strdup(temp);
			swap_order = swap_order == 0 ? 1 : 0;
		}
		else if(strlen(tab[left]) == strlen(tab[right]))
		{
			/*
				Jeśli obie 'liczby' są tej samej długości, pozostaje sprawdzić 
				cyfra po cyfrze, który z tych ciągów jest większy w porządku 
				alfabetycznym
			*/
			int comp_verdict = strcmp(tab[left],tab[right]);
			if(comp_verdict > 0)
			{
				char *temp = strdup(tab[left]);
				tab[left] = strdup(tab[right]);
				tab[right] = strdup(temp);
				swap_order = swap_order == 0 ? 1 : 0;
			}
		}
		if(swap_order == 0)++left;
		else --right;
	}
	/*
		Quick sort jest funkcją rekurencyjną, zatem w momencie
		kiedy oba znaczniki ze sobą się spotkają, wywołuje
		sortowanie dwóch podtablic za pomocą tej samej funkcji
	*/
	quick_sort(tab,save_left,left-1);
	quick_sort(tab,left,save_right);
}

int quick_search(char **tab, int left, int right, char *value)
{
	/*
		quick_search również działa zgodnie z zasadą dziel i zwyciężaj
		sprawdzam czy dany element (w tym przypadku środkowy z tablicy)
		jest większy od szukanego elementu. 
			Jeśli tak, to muszę przeszukać pierwszą połowę tablicy
			Jeśli nie, dodatkowo sprawdzam, czy następny element tablicy jest większy
				Jeśli tak, znalazłem miejsce w tablicy, od którego wszystkie poprzednie 
				Liczby również są mniejsze
				Jeśli nie, przeszukuję drugą połowę tablicy
	*/
	if(left == right)
	{
		/*
			warunek skrajny, to znaczy że wszystkie elementy tablicy są mniejsze lub większe od szukanej liczby
			Oba znaczniki wskazują na pierwszy lub ostatni elememt tablicy
		*/
		int comp_verdict = strcmp(tab[left],value);
		if(strlen(tab[left]) == strlen(value))
		{
			if(left != 0 && comp_verdict <= 0) return right +1;
			else if (left == 0 || comp_verdict > 0) return 0;	
		}
		else if(strlen(tab[left]) < strlen(value))return right +1;
		else return 0;
	}
	int middle = ((right + left)/2)+1;
	int comp_verdict = strcmp(tab[middle-1],value);
	if(strlen(tab[middle-1]) > strlen(value))quick_search(tab,left,middle-1,value);
	else if(strlen(tab[middle-1]) == strlen(value) && comp_verdict >= 0)quick_search(tab,left,middle-1,value);
	else
	{
		int comp_verdict = strcmp(tab[middle],value);
		if(strlen(tab[middle]) > strlen(value))return middle;
		else if(strlen(tab[middle]) == strlen(value) && comp_verdict >= 0) return middle;
		else quick_search(tab,middle,right,value);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	/*
		Ze względu na specyfikę danych wejściowych (liczby z zakresu [1...10^31 - 1])
		wszystkie liczby musiałem zapisać jako ciąg tekstów. Wszystkie pozostałe 
		funkcje również bazują na operacjach na ciągach tekstów
	*/
	char **elementy = malloc(sizeof(char*)*n);
	for(int i = 0; i < n; i++)
	{
		elementy[i] = malloc(sizeof(char)*30);
		scanf("%s",elementy[i]);
	}
	/*
		Sortuję tablicę rosnąco
	*/
	quick_sort(elementy,0,n-1);
	/*
		2 następne linijki to pozostałość ze specyfiki wejścia - prawdopodobnie trzeba rozdzielić dane jedną linijką
	*/
	char empty;
	scanf("%c",&empty);
	int k;
	scanf("%d",&k);
	for(int j = 0; j < k; j++)
	{
		char val[30];
		scanf("%s",&val);
		printf("%d\n",quick_search(elementy,0,n-1,val));
	}
	for(int i = 0; i < n; i++)free(elementy[i]);
	free(elementy);
}

