/*=========================================================

  Filename: main.cpp

  Author: Tobias Steppan

  Date: 14.10.2017

  Description: "Aufgabe 2 - Verwendung von Schleifen"

==========================================================*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void TabelleMitGrundstruktur()
{
    /*  description:    Erstellt Tabelle in der Form von Liste 2.2 Aus Aufgabe "2.1. ASCII-Tabelle"
        parameters:     n/a
        return value:   n/a
    */
    cout<<"Tabelle mit Grundstruktur:"<<endl<<endl;
    for(int i=0; i<32; i++)
    {
        cout<<setfill('0')<<setw(3)<<i<<"  "<<setfill('0')<<setw(3)<<i+32<<"  "<<setfill('0')<<setw(3)<<i+64<<"  "<<setfill('0')<<setw(3)<<i+96<<"  "<<endl;
    }
    cout<<endl;
}

void AsciiTabelleKomplett()
{
    /*  description:    Erstellt Tabelle in der Form von Liste 2.1 aus Aufgabe "2.1. ASCII-Tabelle"
        parameters:     n/a
        return value:   n/a
    */
    cout<<"*** ASCII-Tabelle ***"<<endl<<endl;//überschrift

    cout<<setfill('0')<<setw(3)<<"Okt Dez Hex  Zch"<<"   "; //Kopfzeile
    cout<<setfill('0')<<setw(3)<<"Okt Dez Hex  Zch"<<"   ";
    cout<<setfill('0')<<setw(3)<<"Okt Dez Hex  Zch"<<"   ";
    cout<<setfill('0')<<setw(3)<<"Okt Dez Hex  Zch"<<"   "<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;

    for(int i=0; i<32; i++) //tabelle
    {
        for(int j=0; j<4;j++)
        {
            char asciiSymbol =i+32*j;
            if(j==0||i+32*j==127) //0-31 sowie 127 sollen drei punkte sein
            {
                asciiSymbol='.';
                cout<<setfill('0')<<setw(3)<<oct<<i+32*j<<" "<<setfill('0')<<setw(3)<<dec<<i+32*j<<" "<<setfill('0')<<setw(3)<<hex<<i+32*j<<"  "<<dec<<asciiSymbol<<asciiSymbol<<asciiSymbol<<"   ";
            }else //symbole ausgeben
            {
                cout<<setfill('0')<<setw(3)<<oct<<i+32*j<<" "<<setfill('0')<<setw(3)<<dec<<i+32*j<<" "<<setfill('0')<<setw(3)<<hex<<i+32*j<<"  "<<dec<<asciiSymbol<<"     ";
            }
        }
        cout<<endl;//nächste zeile
    }
    cout<<endl;
}

void RundungsfehlerDurchFortgesetzteMultiplikation()
{
    /*  description:    Aufgabe 2.2 float x=10^6 10 mal mit float k=0.1693 multiplizieren, danach 10 mal durch k dividieren um gleichheit zu überprüfen
        parameters:     n/a
        return value:   n/a
    */
    float x = 1000000;
    float k = 0.1693;
    for(int i=0; i<10; i++) //zehnfache multiplikation
    {
        x=k*x;
    }
    cout<<setprecision(9)<<"Ergebnis nach zehnfacher Multiplikation: "<<x<<endl;
    for(int i=0; i<10; i++)
    {
        x=x/k;
    }
    cout<<setprecision(9)<<"Ergebnis nach zehnfacher Division: "<<x<<endl;
    float result = 1000000-x;
    cout<<setprecision(9)<<"Entstandener Rundungsfehler: "<<result<<endl<<endl;
}

void FlaechenberechnungDreieck(float a, float b, float c)
{
    /*  description:    flaecheninhalt berechnen (formel 2.1 und 2.2), diskriminante auf negativität prüfen, ergebnis ausgeben
        parameters:     Kanten eines Dreiecks
        return value:   n/a
    */
    float result = 0.0;
    float s = 0.0;
    s=(a+b+c)/2.0; //größe für formel 1, halber umfang
    if((s*(s-a)*(s-b)*(s-c))<0)
    {
        cout<<"Die Eingabewerte entsprechen nicht denen eines Dreiecks"<<endl<<endl;
    }else
    {
        result = sqrt(s*(s-a)*(s-b)*(s-c)); //formel 2.1
        cout<<"Der Flaecheninhalt nach Formel 2.1 betraegt: " <<result<<endl<<endl;
        result=(1.0/4.0)*sqrt((a+b+c)*(a+b-c)*(b+c-a)*(c+a-b)); //formel 2.2
        cout<<"Der Flaecheninhalt nach Formel 2.2 betraegt: " <<result<<endl<<endl;
    }
}

int main()
{
/*  description:    c++ main method
    parameters:
    return value:
*/
    //Aufgabe 2.1
    cout<<"Aufgabe 2.1:"<<endl<<endl;
    TabelleMitGrundstruktur();
    AsciiTabelleKomplett();
    //Aufgabe 2.2
    cout<<endl<<"Aufgabe 2.2: Rundungsfehler:"<<endl;
    RundungsfehlerDurchFortgesetzteMultiplikation();
    //Aufgabe 2.3
    float a=0.0;
    float b=0.0;
    float c=0.0;
    cout<<"Aufgabe 2.3 Flaeche eines Dreiecks: "<<endl;
    cout<<"Dieses Programm errechnet den Flaecheninhalt eines Dreiecks anhand dessen Kanten a, b und c"<<endl<<"Bitte geben Sie Kantenlaenge a ein:"<<endl;
    cin>>a;
    cout<<"Bitte geben Sie Kantenlaenge b ein:"<<endl;
    cin>>b;
    cout<<"Bitte geben Sie Kantenlaenge c ein:"<<endl;
    cin>>c;
    cout<<"Sie haben die Kantenlaengen a="<<a<<", b="<<b<<" und c="<<c<<" eingegeben"<<endl;
    FlaechenberechnungDreieck(a,b,c);
    return 0;
}
