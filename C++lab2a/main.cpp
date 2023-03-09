#include <iostream>
#include <stdlib.h>

using namespace std;

void pobranie(int *l, int *&stui, string *&stuk , float *&stus)
{
    while(1)
    {
        int liczba;
        cout << "Podaj liczbe studentow:";
        cin >> *l;

        if (*l>0)
        {
            stui = new int [*l];
            stuk = new string [*l];
            stus = new float [*l];
            for (int i=0;i<*l;i++)
            {
                system("cls");
                while(1)
                {
                    cout << "Podaj 5 lub 6 cyfrowy indeks " << i+1 <<" studenta:" << endl;
                    cin >> stui[i];
                    if (i==0)
                    {
                        if (stui[i]>9999 && stui[i]<1000000)
                        {
                            break;
                        }
                        else
                        {
                            system("cls");
                            cout << "Niepoprawny numer" << endl;
                        }
                    }
                    else
                    {
                        int cz=0;
                        for (int l=0;l<i;l++)
                        {
                            if (stui[l]==stui[i])
                            {
                                cz=1;
                            }
                        }
                        if (cz==1)
                        {
                            system("cls");
                            cout << "Duplikat indeksu" << endl;
                        }
                        else if (stui[i]>9999 && stui[i]<1000000)
                        {
                            break;
                        }
                        else
                        {
                            system("cls");
                            cout << "Niepoprawny numer" << endl;
                        }
                    }
                }

                system("cls");
                while(1)
                {
                    cout << "Skala ocen: 2, 3, 3.5, 4, 4.5, 5" << endl;

                    cout << "Podaj ocene "<< i+1 <<" studenta:" << endl;
                    cin >> stus[i];

                    if ((stus[i]==2) || (stus[i]==3) || (stus[i]==3.5) || (stus[i]==4) || (stus[i]==4.5) || (stus[i]==5))
                    {
                        if (stus[i]==2)
                        {
                            stuk[i]="niezdal";
                            break;
                        }
                        else
                        {
                            stuk[i]="zdal";
                            break;
                        }
                    }
                    else
                    {
                        system("cls");
                        cout << "Niepoprawna ocena" << endl;
                    }
                }
            }
            system("cls");
            break;
        }
        else
        {
            system("cls");
            cout << "Niepoprawna liczba" << endl;
        }
    }
}

void wyswietl(int liczba,int *stui,string *stuk,float *stus)
{
    cout << "Dane:" << endl;
    for (int i=0; i<liczba; i++)
    {
        cout <<stui[i]<<",";
        cout <<stus[i]<<",";
        cout <<stuk[i];
        cout << endl;
    }
}

void sortowanie(int liczba,int *stui,string *stuk,float *stus)
{
    for(int i=0;i<liczba;i++)
    {
        for(int j=1;j<liczba-i;j++)
        {
            if(stus[j-1]>stus[j])
            {
                swap(stui[j-1], stui[j]);
                swap(stuk[j-1], stuk[j]);
                swap(stus[j-1], stus[j]);
            }
        }
    }
}

void wypiszmaks(int liczba,int *stui,float *stus)
{
    float max = 0;
    for(int i=0;i<liczba;i++)
    {
        if  (stus[i]>max)
        {
            max = stus[i];
        }
    }
    for(int i=0;i<liczba;i++)
    {
        if  (stus[i]==max)
        {
            cout <<stui[i]<<",";
            cout <<stus[i]<<",";
            cout << endl;
        }
    }
}

int main()
{
    int liczba;
    int *stui;
    string *stuk;
    float *stus;

    int wybor=1;

    while (wybor!=5)
    {
        cout << "1) pobieranie danych" << endl;
        cout << "2) wyswietl dane" << endl;
        cout << "3) sortowanie" << endl;
        cout << "4) maksymalne wyniki" << endl;
        cout << "5) koniec programu" << endl;
        cout << "Wybiez co chcesz zrobic:";
        cin >> wybor ;
        if (wybor==1)
        {
            system("cls");
            pobranie(&liczba,stui,stuk,stus);
        }
        else if (wybor==2)
        {
            system("cls");
            wyswietl(liczba,stui,stuk,stus);
        }
        else if (wybor==3)
        {
            system("cls");
            sortowanie(liczba,stui,stuk,stus);
        }
        else if (wybor==4)
        {
            system("cls");
            wypiszmaks(liczba,stui,stus);
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
