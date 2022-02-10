#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
	Do wyliczenia średniej wszystkich dzielników właściwych skorzystałem z dwóch wzorów
	 - funkcja sigma (suma dzielników)
	 - funkcja theta (liczba dzielników)
	Obie funkcje biorą pod uwagę też liczbę 1 i samą liczbę, co dodatkowo trzeba było uwzględnić w obliczeniach
	Obie funkcje opierają się o rozkład liczby na czynniki pierwsze oraz obliczenie krotności tych czynników
	Wymagało to zaimplementowania struktury danych do przechowywania 2 wartości w 1 elemencie tablicy

	Specyfika wejścia wymaga, żeby podał liczbę liczb znaczących w danym przedziale. Przedziały mogą się wzajemnie pokrywać, 
	więc mógłbym dany przedział sprawdzać kilka razy
	Dlatego dodatkowo stworzyłem inną strukturę, do przechowywania wszystkich zadanych przedziałów tak, żeby w ramach tego przedziału
	policzyć ile jest liczb znaczących 

	Liczby znaczące wyliczam tylko raz, dla przedziału, który jest wspólnych dla wszystkich danych przedziałów
*/


struct triplet
{
	int x;
	int y;
	int z;
};

struct pair
{
	int x;
	int y;
};


int main()
{
	int num_of_tests;
	scanf("%d",&num_of_tests);
	/*
		dana tablica wyznacza przedział wspolny dla wszystkich przedziałów
	*/
	int min_max_tab[2] = {-1,-1};
	struct triplet *tab = malloc(sizeof(struct triplet)*num_of_tests);
	/*
		tablica tab z elementami 'struct triplet' służy do przechowywania zadanych przedziałów oraz do 
		liczenia ilości liczb znaczących w danym przedziale
		tab.x - początek przedziału
		tab.y - koniec przedziału
		tab.z - liczba liczb znaczących w danym przedziale
	*/
	for(int j = 0; j < num_of_tests; j++)
	{
		int a,b;
		scanf("%d",&a);
		scanf("%d",&b);
		if(min_max_tab[0]==-1){
			min_max_tab[0] = a;
			min_max_tab[1] = b;
		}
		if(a < min_max_tab[0])min_max_tab[0] = a;
		if(b > min_max_tab[1])min_max_tab[1] = b;
		struct triplet temp;
		temp.x = a;
		temp.y = b;
		temp.z = 0;
		tab[j] = temp;
	}
	/*
		deklaruje tablicę ze wszystkim liczbami znaczącymi w tym przedziale
		Ponieważ nie znam ich dokładnej liczby w danym przedziale, dla 
		bezpieczeństwa deklaruję tablicę o takiej samej liczbie elementów, 
		ile występuje liczb w danym przedziale. Wszystkie przyjmują wartość 0
	*/
	int *num_tabs = (int*)calloc((min_max_tab[1]-min_max_tab[0]+1),sizeof(int));
	int num_tabs_iterator = 0;
	for(int start = min_max_tab[0]; start <= min_max_tab[1];start++)
	{
		/*
			tablica do przechowywania wszystkich czynników pierwszych
			Działanie następnej pętli sprawia, że tablica od razy powstaje uporządkowana
		*/
		int *temp_primes = (int*)calloc(ceil(sqrt(start)),sizeof(int));
		int iter = 0;
		int temp_num = start;
		int number_of_primes = 0;
		int number_is_prime = 0; // bool for check, if number is prime. 0 - maybe is prime, 1 - not prime, 2 - is prime
		/*
			pętla rozkłada liczbę na czynniki pierwsze. 
		*/
		while(temp_num != 1)
		{
			for(int divisor = 2; divisor <= temp_num; divisor++)
			{
				if(number_is_prime != 1 && divisor >= sqrt(start))
				{
					number_is_prime = 2;
				}
				if(temp_num%divisor == 0)
				{
					number_is_prime = 1;
					temp_primes[iter] = divisor;
					++iter;
					temp_num /= divisor;
					if(number_of_primes == 0)++number_of_primes;
					else
					{
						if(temp_primes[iter-1] != temp_primes[iter-2])++number_of_primes;
					}
					break;		
				}
			}
		}
		if(number_is_prime == 2)continue;
		/*
			tablica przechowywuje kombinacje czynnika pierwszego i potęgi
			tego czynnika. Jest to poptrzebne do zastosowania wzorów
		*/
		struct pair *prime_factorization_tab = (struct pair*)malloc(sizeof(struct pair)*number_of_primes);
		iter = 0;
		int prime_facto_tab_iter = 0;
		while(temp_primes[iter] != 0)
		/*
			pętla zlicza potęgę dla każdego czynnika pierwszego i zapisuje parę liczb
			do tablicy
		*/
		{
			if(iter == 0)
			{
				struct pair new_prime;
				new_prime.x = temp_primes[iter];
				new_prime.y = 1;
				prime_factorization_tab[prime_facto_tab_iter] = new_prime;
			}
			else if(temp_primes[iter] == temp_primes[iter-1]) prime_factorization_tab[prime_facto_tab_iter].y += 1;
			else 
			{
				struct pair new_prime;
				new_prime.x = temp_primes[iter];
				new_prime.y = 1;
				++prime_facto_tab_iter;
				prime_factorization_tab[prime_facto_tab_iter] = new_prime;
			}
			++iter;
		}
		/*
			nastepna petla oblicza sumy i ilosc dzielnikow
		*/
		double sum_of_dividors = 1.0;
		double number_of_dividors = 1.0;
		for(int i = 0; i < number_of_primes; i++)
		{
			sum_of_dividors *= (pow(prime_factorization_tab[i].x,prime_factorization_tab[i].y+1)-1)/(prime_factorization_tab[i].x - 1);
			number_of_dividors *= (prime_factorization_tab[i].y+1);
		}
		sum_of_dividors -= (start+1);
		number_of_dividors -= 2;
		if(sum_of_dividors/number_of_dividors <= sqrt((double)start))
		{
			num_tabs[num_tabs_iterator] = start;
			++num_tabs_iterator;
		}
	}
	/*
		wyswietlenie wszystkich rozwiazan
	*/
	for(int i = 0; num_tabs[i] != 0; i++)
	{
		for(int j = 0; j < num_of_tests; j++)
		{
			if(num_tabs[i] >= tab[j].x && num_tabs[i] <= tab[j].y) 
			{
				++tab[j].z;
			}
		}
	}	
	for(int i = 0; i < num_of_tests; i++)printf("%d\n",tab[i].z);
	return 0;
}
