/*=========================================================

  Filename: main.cpp

  Author: Tobias Steppan

  Date: 23.10.2017

  Description: "Aufgabe 3 Verwendung von Feldern"

==========================================================*/

#include <iostream>
#include <cstdlib>
#include<fstream>
#include<vector>

using namespace std;

int ZufallszahlNullBisFuenfzig()
{
/*  description:    siehe name
    parameters:     n/a
    return value:   int 0-50 Zufallszahl
*/
    double zufallsZahl=0;
    zufallsZahl=rand()%51;
    return zufallsZahl;
}

void Aufgabe3_1()
{
    //Feld deklarieren
    double a[100];

    //Feld füllen
    for(int i = 0; i<100; i++)
    {
        a[i]=ZufallszahlNullBisFuenfzig();
    }
    cout<<"Aufgabe 3.1:"<<endl;
    int counter = 0;
    double summeAllerElemente=0.0;

    //Ausgabe aller Elemente über 10 Reihen
    for(int i=1; i<=10;i++)
    {
        for(int j=1;j<=10;j++)
        {
            summeAllerElemente+=a[counter];
            cout<<a[counter]<<" ";
            counter++;
        }
        cout<<endl;
    }

    //Arithmetisches Mittel
    cout<<endl<<"Arithmetisches Mittel: "<<summeAllerElemente/counter<<endl<<endl;

    //Kleinstes/groesstes Element finden
    int kleinsterWert=a[0];
    int groessterWert=a[0];
    for(int i = 0; i<100;i++)
    {
        if(kleinsterWert>a[i])
        {
            kleinsterWert=a[i];
        }
        if(groessterWert<a[i])
        {
            groessterWert=a[i];
        }
    }

    //Ausgabe kleinster/groesster Wert
    cout<<"Kleinstes Feldelement: "<<kleinsterWert<<endl<<"Groesstes Feldelement: "<<groessterWert<<endl<<endl;
}

void Aufgabe3_2()
{
    //dynamisch erweiterbares Array
    //vector<double> aVector;

    //File stream objekt
    ifstream Datei;
    Datei.open("C:\\Projects\\fh-swf-cplusplus-1.git\\exercise-3\\daten-3-2.txt");

    double element=0.0;
    //erstes element ist mit 0.0 initialisiert, man muss sich allerdings von hohen werten annähern
    double kleinsterWert=999999999999999;
    double groessterWert=0.0;
    int zaehler=0;
    double summeAllerElemente=0.0;
    //lese zahlen ein und fuege sie mit push_back an den vector
    while(Datei>>element)
    {
        summeAllerElemente+=element;
        if(kleinsterWert>element)
        {
            kleinsterWert=element;
        }
        if(groessterWert<element)
        {
            groessterWert=element;
        }

        //aVector.push_back(element);
        zaehler++;
    }
    Datei.close();
    cout<<"Aufgabe 3.2: "<<endl;
    cout<<"Anzahl der Eingelesen Elemente: "<<zaehler<<endl<<"Kleinster Wert: "<<kleinsterWert<<endl<<"Groesster Wert: "<<groessterWert<<endl<<"Arithmetische Mittel: "<<summeAllerElemente/zaehler<<endl<<endl;
}

void Aufgabe3_3()
{
    int naechsterZufallswert;
    int aktuellerZufallsWert=0;
    int a=16333;
    int b=25887;
    int m=2;

    //2^15
    for(int i=0;i<14;i++)
    {
        m=2*m;
    }
    cout<<"Aufgabe 3.3"<<endl<<endl<<"10 Zufallszahlen:"<<endl;

    //Kongruenz Generator nach Lehmer für die ersten 10 elemente
    for(int i =0;i<10;i++)
    {
        naechsterZufallswert=(a*aktuellerZufallsWert+b)%m;
        aktuellerZufallsWert=naechsterZufallswert;
        cout<<naechsterZufallswert<<endl;
    }
    cout<<endl;
}

void Aufgabe3_4()
{
    int naechsterZufallswert;
    int aktuellerZufallsWert=0;
    int a=16333;
    int b=25887;
    int m=2;
    int zaehler=0;

    //2^15
    for(int i=0;i<14;i++)
    {
        m=2*m;
    }
    cout<<"Aufgabe 3.4"<<endl;

    //Kongruenz Generator nach Lehmer für die ersten 10 elemente
    while(true)
    {
        naechsterZufallswert=(a*aktuellerZufallsWert+b)%m;
        aktuellerZufallsWert=naechsterZufallswert;
        if(naechsterZufallswert==0)
        {
            break;
        }
        zaehler++;
    }

    cout<<"Nach: "<<zaehler<<" Zufallszahlen taucht der Startwert 0 erneut auf";
}

int main()
{
   Aufgabe3_1();
   //Aufgabe3_2();
   //Aufgabe3_3();
   //Aufgabe3_4();
    return 0;
}
