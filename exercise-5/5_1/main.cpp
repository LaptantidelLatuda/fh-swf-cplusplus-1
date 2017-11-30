/* 
 * File:   main.cpp
 * Author: Tobias Steppan
 * Description: Lösung zur Aufgabe: 5.1. Die Verschiebechiffre ROT13
 * Created on 21. November 2017, 12:54
 */

//Standard General Utilities Library
#include <cstdlib>
//Input/Output stream class 
#include <fstream> 
//IO Stream Objects
#include <iostream>

using namespace std;

int main()
{
    //Konsolenausgabe
    cout << "Aufgabe 5.1: Die Verschiebechiffre ROT13" << endl << endl;

    //ifstream Objekt erstellen
    ifstream eingabeDatei;

    //ofstream Objekt erstelln algorithmischer Lösungsweg
    ofstream ausgabeDateiLoesungsweg1;

    //Datei öffnen
    eingabeDatei.open("klartext.txt");

    //Abfragen ob eingabeDatei geöffnet werden konnte
    if (!eingabeDatei)
    {
        cerr << endl << "Error: failed to open input file ! " << endl;
        exit(1);
    }

    //Datei öffnen
    ausgabeDateiLoesungsweg1.open("geheimLoesungsweg1.txt");

    //Abfrage ob ausgabeDateien geöffnet werden können
    if (!ausgabeDateiLoesungsweg1)
    {
        cerr << endl << "Error: failt to open output file! " << endl;
        exit(2);
    }

    //Einlese-Variable
    char c;

    //Lösungsweg 1 algorithmisch
    //Anweisung zum Einlesen der Datei, charweise dekodierung sowie der Speicherung
    //in einer ausgabeDatei
    while ((c = eingabeDatei.get()) != EOF)
    {
        //falls c ein Großbuchstabe ist ROT13 dekodieren:
        if (isupper(c))
        {
            //Offset 'A' zu DEC 0 subtrahieren und im fotlaufenden Alphabet um 
            //13 stellen nach links schieben
            c = c - 13 - 65;

            //Falls der dekodierte Buchstabe kleiner als 0 wird um 26 Buchstaben springen
            if (c < 0)
            {
                c = c + 26;
            }

            //Offset wieder addieren um das korrekte Zeichen zu erhalten
            c = c + 65;

        }
        //schreiben des dekodierten Zeichens in die ausgabeDatei
        ausgabeDateiLoesungsweg1 << c;
    }
    
    //Streamsschließen
    eingabeDatei.close();
    ausgabeDateiLoesungsweg1.close();

    //ofstream Objekt erstelln vorgegebener Lösungsweg
    ofstream ausgabeDateiLoesungsweg2;
    
    //ausgabeDateiLoesungsweg2 öffnen
    ausgabeDateiLoesungsweg2.open("geheimLoesungsweg2.txt");

    //Abfragen ob ausgabeDateiLoesungsweg2 geöffnet werden konnte
    if (!ausgabeDateiLoesungsweg1)
    {
        cerr << endl << "Error: failt to open output file! " << endl;
        exit(2);
    }

    //Datei öffnen
    eingabeDatei.open("klartext.txt");

    //Das zur verschlüsselung genutzte Feld
    char rot13[] = {'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'};

    //Lösungsweg 2 vorgegeben
    while ((c = eingabeDatei.get()) != EOF)
    {
        //falls c ein Großbuchstabe ist ROT13 dekodieren:
        if (isupper(c))
        {
            c = rot13[c - 'A'];
        }
        //schreiben des dekodierten Zeichens in die ausgabeDatei
        ausgabeDateiLoesungsweg2 << c;
    }

    //Schließen der File Stream Objekt
    ausgabeDateiLoesungsweg2.close();
    return 0;
}

