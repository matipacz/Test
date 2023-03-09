#include <iostream>
#include <stdlib.h>

using namespace std;

void pobranie(int *l , int *&stui , string *&stuk , float *&stus)
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
                    cout << "Dostepne kierunki do wpisania, nie wpisuj czesci w nawiasie:" << endl;
                    cout << "elektrotechnika" << endl;
                    cout << "informatyka" << endl;
                    cout << "inzynieriab(iomedyczna)" << endl;
                    cout << "inzynierskie(zastosowania informatyki w elektrotechnice)" << endl;
                    cout << "inzynieriam(ultimediow)" << endl;
                    cout << "mechatronika" << endl;

                    cout << "Podaj kierunek "<< i+1 <<" studenta:" << endl;
                    cin >> stuk[i];

                    if ((stuk[i]=="elektrotechnika") || (stuk[i]=="informatyka") || (stuk[i]=="inzynieriab") || (stuk[i]=="inzynierskie") || (stuk[i]=="inzynieriam") || (stuk[i]=="mechatronika"))
                    {
                        break;
                    }
                    else
                    {
                        system("cls");
                        cout << "Niepoprawny kierunek" << endl;
                    }
                }

                system("cls");
                while(1)
                {
                    cout << "Podaj srednia " << i+1 <<" studenta:" << endl;
                    cin >> stus[i];
                    if (stus[i]>=2 && stus[i]<=5)
                    {
                        break;
                    }
                    else
                    {
                        system("cls");
                        cout << "Niepoprawna srednia" << endl;
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
        cout <<stuk[i]<<",";
        cout <<stus[i];
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

void wyszukiwaniebinarne(int liczba,float *stus)
{
    float sr;
    while (1)
    {
        cout << "Jakiej sredniej szukasz?:";
        cin >> sr;
        if (sr>=2 && sr<=5)
        {
            break;
        }
        else
        {
            system("cls");
            cout << "Niepoprawna srednia" << endl;
        }

    }
    int l,ce,p;
    l=0;
    p=liczba-1;
    while(1)
    {
        ce = (l + p)/2;
        if (l>p)
        {
            cout << "Nie istnieje student o podanej sredniej" << endl;
            break;
        }
        if(stus[ce] == sr)
        {
            cout << "Istnieje student o podanej sredniej" << endl;
            break;
        }
        if(stus[ce] > sr)
        {
            p = ce - 1;
        }
        else
        {
            l = ce + 1;
        }

    }
}

void ilekierunek(int liczba,string *stuk)
{

    while(1)
    {
        cout << "Dostepne kierunki do wyszukania, nie wpisuj czesci w nawiasie:" << endl;
        cout << "elektrotechnika" << endl;
        cout << "informatyka" << endl;
        cout << "inzynieriab(iomedyczna)" << endl;
        cout << "inzynierskie(zastosowania informatyki w elektrotechnice)" << endl;
        cout << "inzynieriam(ultimediow)" << endl;
        cout << "mechatronika" << endl;
        string szk;
        cout << "Podaj kierunek ktorego szokasz" << endl;
        cin >> szk;

        if ((szk=="elektrotechnika") || (szk=="informatyka") || (szk=="inzynieriab") || (szk=="inzynierskie") || (szk=="inzynieriam") || (szk=="mechatronika"))
        {
            int ile=0;
            for (int i=0; i<liczba; i++)
            {
                if (szk==stuk[i])
                {
                    ile++;
                }
            }
            system("cls");
            cout << "Jest " << ile << " podanych kierunkow"<< endl;
            break;
        }
        else
        {
            system("cls");

            cout << "Niepoprawny kierunek" << endl;
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

    while (wybor!=6)
    {
        cout << "1) pobieranie danych" << endl;
        cout << "2) wyswietl dane" << endl;
        cout << "3) sortowanie" << endl;
        cout << "4) wyszukiwanie binarne (musi byc posortowane)" << endl;
        cout << "5) liczba danych kierunkow" << endl;
        cout << "6) koniec programu" << endl;
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
            wyswietl(liczba,stui,stuk,stus);
            wyszukiwaniebinarne(liczba,stus);
        }
        else if (wybor==5)
        {
            system("cls");
            ilekierunek(liczba,stuk);
        }
        else if (wybor==6)
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
