#include <iostream>
#include "pytanie.h"

using namespace std;

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    Pytanie p[5];

    int suma = 0;
    for (int i=0; i<5; i++)
    {
        p[i].nr_pytania = i + 1;
        p[i].wczytaj();
        p[i].zadaj();
        p[i].sprawdz();
        suma += p[i].punkt;
    }

    cout<<"\nKONIEC QUIZU!\nZdobyte punkty = "<<suma<<"\n";

    return 0;
}
