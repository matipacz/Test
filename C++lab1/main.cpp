#include <iostream>

using namespace std;

void pobranie(int *&tab, int *n)
{
    cout << "Podaj lie bedzie liczb:" << endl;
    cin >> *n;
    tab = new int [*n];
    cout << "Podaj te liczby:" << endl;

    for (int i=0; i<*n; i++)
    {
        cin >> tab[i];
    }

}

void wypisz(int*tab,int n)
{
    cout << "Elementy tablicy:" << endl;

    for (int i=0; i<n; i++)
    {
        cout <<tab[i]<<",";
    }
    cout << endl;
}

void sortowanie_babelkowe(int *tab,int n)
{
	for(int i=0;i<n;i++)
		for(int j=1;j<n-i;j++)
		if(tab[j-1]>tab[j])
            swap(tab[j-1], tab[j]);

}
void sortowanie_przez_wstawianie(int *tab,int n)
{
     int pom, j;
     for(int i=1; i<n; i++)
     {
             pom = tab[i];
             j = i-1;
             while(j>=0 && tab[j]>pom)
             {
                        tab[j+1] = tab[j];
                        --j;
             }
             tab[j+1] = pom;
     }
}

void quick_sort(int *tab, int lewy, int prawy)
{
	int i = lewy - 1, j = prawy + 1,
	pivot = tab[(lewy+prawy)/2];
	while(1)
	{

		while(pivot>tab[++i]);

		while(pivot<tab[--j]);

		if( i <= j)
			swap(tab[i],tab[j]);
		else
			break;
	}

	if(j > lewy)
	quick_sort(tab, lewy, j);
	if(i < prawy)
	quick_sort(tab, i, prawy);
}

int main()
{
    int k;
    int *T;
    cout << "1) pobieranie danych" << endl;
    cout << "2) sortowanie babelkowe" << endl;
    cout << "3) sortowanie poprzez wstawianie - InsertSort" << endl;
    cout << "4) sortowanie szybkie - Quicksort" << endl;
    cout << "5) koniec programu" << endl;
    cout << "Wybiez co chcesz zrobic:";
    int wybor=1;

    while (wybor!=5)
    {
        cin >> wybor ;
        if (wybor==1)
        {
            pobranie (T, &k);
            wypisz(T,k);
        }
        else if (wybor==2)
        {
            sortowanie_babelkowe(T,k);
            wypisz(T,k);
        }
        else if (wybor==3)
        {
            sortowanie_przez_wstawianie(T,k);
            wypisz(T,k);
        }
        else if (wybor==4)
        {
            quick_sort(T,0, k-1);
            wypisz(T,k);
        }
        else if (wybor==5)
        {
            return 0;
        }
        else
        {
            cout << "Niepoprawny wybor" << endl;
        }
    }

    return 0;
}
