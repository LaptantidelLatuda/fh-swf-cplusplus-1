/* 
 * File:   main.cpp
 * Author: Tobias Steppan
 * Description: Lösung zur Aufgabe: 5.2. Caesar-Verschlüsselung
 * Created on 21. November 2017, 12:54
 */

//Standard General Utilities Library
#include <cstdlib>
//Input/Output stream class 
#include <fstream> 
//IO Stream Objects
#include <iostream>

using namespace std;

//Testfelder
char a[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'Y', 'Z'};
char feldWenden[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'Y', 'Z'};
char feldLinksSchieben[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'Y', 'Z'};
char feldRechtsSchieben[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'Y', 'Z'};

/* Beschreibung: wendet einen Bereich in einem Array 
 * Übergabeparameter: a: zu wendendes Feld; n: Länge des zu wendenden Bereichs 
 */
void feld_wenden(char a[], unsigned int n)
{
    //Hilfsvariable
    char c;

    //Über die Hälfte der Länge des Feldes iterieren
    //n-1 => da bei a[0] angefangen wird
    for (int i = 0; i < n / 2; i++)
    {
        //Stelle merken die im nächsten schritt überschrieben wird
        c = a[i];
        //Erste Hälfte des Bereichs wenden
        a[i] = a[n - 1 - i];
        //Zweite Hälfte des Bereichs wenden
        a[n - 1 - i] = c;
    }
}

/* Beschreibung: lässt ein Feld zyklisch nach links rotieren 
 * Übergabeparameter: 
 * a: Feld, welches zyklisch nach links verschoben werden soll
 * n: Länge des Feldes
 * shift: Plätze, um die verschoben werden soll  
 */
void feld_links_rotieren(char a[], unsigned int n, unsigned int shift)
{
    //Verlassen falls shift=0
    if (shift == 0)
    {
        return;
    }

    //verschiebung muss kleiner als feldlänge sein
    shift = shift % n;

    //dreimaliger aufruf analog zu Abbildung 5.2 Lerneinheit 2
    feld_wenden(a, shift);
    feld_wenden(a, n);
    feld_wenden(a, n - shift);
}

/* Beschreibung: lässt ein Feld zyklisch nach rechts rotieren 
 * Übergabeparameter: 
 * a: Feld, welches zyklisch nach rechts verschoben werden soll
 * n: Länge des Feldes
 * shift: Plätze, um die verschoben werden soll  
 */
void feld_rechts_rotieren(char a[], unsigned int n, unsigned int shift)
{
    //Verlassen falls shift=0
    if (shift == 0)
    {
        return;
    }

    feld_wenden(a, n);
    feld_wenden(a, shift);
    feld_wenden(a, n - shift);

    //verschiebung muss kleiner als feldlänge sein
    shift = shift % n;

}

int main()
{
    //!!Testszenario

    //Originales Test Feld ausgeben
    cout << "Test-Feld: " << endl;
    for (int i = 0; i<sizeof (a); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    
    feld_wenden(feldWenden, 5);

    //Gewendetes Feld ausgeben
    cout << "feld_wenden:" << endl;
    for (int i = 0; i<sizeof (feldWenden); i++)
    {
        cout << feldWenden[i] << " ";
    }
    cout << endl;
    
    feld_links_rotieren(feldLinksSchieben, sizeof (feldLinksSchieben), 2);

    //Ausgabe
    cout << "feld_links_rotieren" << endl;
    for (int i = 0; i<sizeof (feldLinksSchieben); i++)
    {
        cout << feldLinksSchieben[i] << " ";
    }
    cout<<endl;
    
    feld_rechts_rotieren(feldRechtsSchieben, sizeof(feldRechtsSchieben), 2);

    //Ausgabe
    cout << "feld_rechts_rotieren" << endl;
    for (int i = 0; i<sizeof (feldRechtsSchieben); i++)
    {
        cout << feldRechtsSchieben[i] << " ";
    }

    return 0;
}

