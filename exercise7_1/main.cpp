/* 
 * File:   main.cpp
 * Author: Tobias Steppan
 * Description: Lösung zur Aufgabe: 7.1. Bilddatei lesen und speichern
 * Created on 12. Januar 2018, 20:59
 */

//Standard General Utilities Library
#include <cstdlib>

//Input/Output stream class 
#include <fstream> 

//IO Stream Objects
#include <iostream>

using namespace std;

//max. Bildhöhe
const int N = 1000;

//Datentyp Pixel
typedef unsigned char Pixel;

//Prototypen
void glaetten(Pixel bild1[N][N], Pixel bild2[N][N], int nz, int ns);
void invertieren(Pixel bild1[N][N], Pixel bild2[N][N], int nz, int ns, int graumax);
void kantenbildung(Pixel bild1[N][N], Pixel bild2[N][N], int nz, int ns);
void schaerfen(Pixel bild1[N][N], Pixel bild2[N][N], int nz, int ns, int graumax);

/*
 * 
 */
int main(int argc, char** argv)
{
    //Konsolenausgabe
    cout << "Aufgabe 7.1: Bilddatei lesen und speichern" << endl << endl;

    //ifstream Objekt erstellen
    ifstream eingabeDatei;

    //Datei öffnen
    eingabeDatei.open("dreifach.pgm");

    //Abfragen ob eingabeDatei geöffnet werden konnte
    if (!eingabeDatei)
    {
        cerr << endl << "Error: failed to open input file ! " << endl;
        exit(1);
    }

    //ofstream Objekt erstelln
    ofstream ausgabeDatei;

    //Datei öffnen
    ausgabeDatei.open("dreifach.out.pgm");

    //Abfrage ob ausgabeDateien geöffnet werden können
    if (!ausgabeDatei)
    {
        cerr << endl << "Error: failt to open output file! " << endl;
        exit(2);
    }

    //Feld für eingelesene Datei
    unsigned char einleseFeld[N][N];

    //Einzulesendes Element
    string element;

    //ElementZähler ersten 4 elemente abziehen
    int elementCounter = -3;



    int zeilen, spalten, i = 0, j = 0;

    /*eingabeDatei einlesen
     */
    while (eingabeDatei >> element)
    {

        //Array füllen nach dem header
        if (elementCounter > 0)
        {
            einleseFeld[i][j] = stoi(element);
            j++;
            //Nach x Zeilen in nächste Spalte springen
            if (j == spalten)
            {
                i++;
                j = 0;
            }
        } else
        {
            //Ausgabe
            cout << element;
            //Kodierung überprüfen
            if (elementCounter == -3)
            {
                if (element != "P2")
                {
                    cout << "Falsche Kodierung";
                    break;
                }
                //newline nach kodierung
                cout << endl;
            }
            //größe überprüfen
            if ((elementCounter == -2 || elementCounter == -1)&&(stoi(element) > N))
            {
                cout << "Bild zu groß";
                break;
            }
            //nach Element 3 Neue Zeile und Zeilenzahl merken
            if (elementCounter == -1)
            {
                cout << endl;
                zeilen = stoi(element);
            }
            //nach Element 2 Leerzeile und spaltenzahl merken
            if (elementCounter == -2)
            {
                cout << " ";
                spalten = stoi(element);
            }
            //nach Element graustufen nächste zeile
            if (elementCounter == 0)
            {
                cout << endl;
            }
        }
        elementCounter++;
    }
    //Stream schließen
    eingabeDatei.close();


    //Header in AusgabeDatei schreiben
    ausgabeDatei<<"P2"<<'\n'<<spalten<<" "<<zeilen << '\n'<<255<<'\n';
    
    //Bild schreiben
    for (i = 0; i < zeilen; i++)
    {
        for (j = 0; j < spalten; j++)
        {
            ausgabeDatei << (int) einleseFeld[i][j];
            ausgabeDatei << ' ';
        }
        ausgabeDatei << '\n';
    }

    //Stream schließen
    ausgabeDatei.close();


    return 0;
}

