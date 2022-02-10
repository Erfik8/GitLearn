#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>

/*
	algorytm rekurencyjny na rozkład liczby na sumę nierosnących liczb
	Algorytm ma tą ważną cechę, że obliczane rozkłady w kolejnych przebiegach 
	funkcji są już w porządku leksykograficznym
	Skrótowe przedstawienie funkcji
	
	recursive_addition(1,5,'') = "1 " + recursive_addition(1,4,"1 ") = "1 1 " + recursive_addition(1,3,"1 1 ") + ....
	...
	recursive_addition(2,5,'') = "2 " + recursive_addition(2,3,"2 ") = "2 2 " + recursive_addition(2,1,"2 2 ") = BRAK TAKIEGO TEKSTU
				   = "2 " + recursive_addition(3,3,"2 ") = "2 3 "
	...
	recursive_addition(3,5,'') = "3 " + recursive_addition(3,2,"3 ") = BRAK TAKIEGO TEKSTU

	BUDOWA FUNKCJI 
	recursive_function(sub_value,n_actual_value,end_string)
		sub_value - aktualny czynnik, który ma być zapisany w dalszej części wynikowego tekstu
		n_actual_value - aktualna liczba, która ma być rozłożona na czynniki
		end_string - tekst, do którego są doklejane dalsze rozwiązania
*/

void recursive_addition(int sub_value, int n_actual_value, char *end_string)
{
	int part_sum = n_actual_value - sub_value;
	/*
		rezerwacja odpowiedniej długości tekstu w zależności od ilości cyfr danego czynnika
	*/
	size_t new_size = sizeof(char)*(strlen(end_string) + ceil(log10(sub_value))+3);
	char *temp = (char*)malloc(new_size);
	sprintf(temp, "%s%d ", end_string,sub_value);
	
	/*
		może być sytuacja, gdy podczas rozkładu na czynniki, następny czynnik musiałby być mniejszy od poprzedniego
		co jest niezgodne z założeniami zadania. W tej sytuacji dany rozkład jest niepoprawny i należy go pominąć
		jeśli następny czynnik byłby równy 0, to znaczy że dana liczba została rozłożona na czynniki i można wypisać go 
		na standardowe wyjscie
	*/

	if(part_sum == 0)
	{
		printf("%s\n",temp);
		return;
	}
	else if(part_sum < sub_value)return;
	for(int a = sub_value; a <= part_sum; a++) recursive_addition(a,part_sum,temp);
}

int main()
{
	int i = 0;
	scanf("%d",&i);
	for(;i>0;i--)
	{
		short n;
		scanf("%hd",&n);
		for(int a = 1; a <= n ; a++)recursive_addition(a,n,"");
		if (i != 1)printf("\n");
	}
	//printf("%s",list[0]);
	return 0;
}
