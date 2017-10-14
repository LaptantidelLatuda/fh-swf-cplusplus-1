/*=========================================================

  Filename: main.cpp

  Author: Tobias Steppan

  Date: 14.10.2017

  Description: "Aufgabe 2 - Verwendung von Schleifen"

==========================================================*/

#include <iostream>
#include <iomanip>

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
}

int main()
{
/*  description:    c++ main method
    parameters:
    return value:
*/
    cout<<"Aufgabe 2.1:"<<endl<<endl;
    TabelleMitGrundstruktur();
    AsciiTabelleKomplett();
    return 0;
}
