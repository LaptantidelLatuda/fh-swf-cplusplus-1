/*=========================================================

  Filename: main.cpp

  Author: Tobias Steppan

  Date: 23.10.2017

  Description: "Aufgabe 3 Verwendung von Feldern"

==========================================================*/

#include <iostream>
#include <cstdlib>

using namespace std;

double ZufallszahlNullBisFuenfzig()
{
/*  description:    siehe name
    parameters:     n/a
    return value:   Zufallszahl 0-50
*/
    double zufallsZahl=0.0;
    zufallsZahl=rand()%51;
    return zufallsZahl;
}

int main()
{
    //Feld deklarieren
    double a[99];
    //Feld füllen
    for(int i = 0; i<100; i++)
    {
        a[i]=ZufallszahlNullBisFuenfzig();
    }
    cout<<"Aufgabe 3.1:"<<endl;
    for(int i=1; i<=10;i++)
    {
        for(int j=1;j<=10;j++)
        {
            cout<<a[i*j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
