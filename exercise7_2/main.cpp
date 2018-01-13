/* 
 * File:   main.cpp
 * Author: Tobias Steppan
 * Description: Lösung zur Aufgabe: 7.2. Grauwertbild bearbeiten
 * Created on 12. Januar 2018, 23:01
 */

//Standard General Utilities Library
#include <cstdlib>

//Input/Output stream class 
#include <fstream> 

//IO Stream Objects
#include <iostream>
#include <memory>
#include <complex>

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

//zeilen spalten variable
int zeilen, spalten, i, j;

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

    //Feld für manipuliertes Bild
    unsigned char manipuliertesBild[N][N];

    //Einzulesendes Element
    string element;

    //ElementZähler ersten 4 elemente abziehen
    int elementCounter = -3;

    int i = 0, j = 0;

    //eingabeDatei einlesen, überprüfen, header ausgeben
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

    ////Aufforderung zur Eingabe
    cout << "Auswahl der Funktion:" << endl << "g Glättung" << endl << "i Invertierung" << endl;
    cout << "k Kantenbildung" << endl << "s Schärfung" << endl << "e ENDE" << endl;

    //Engabevariable
    char inputChar;
    cin>>inputChar;

    //Eingabemenü
    switch (inputChar)
    {
        case 'i': invertieren(einleseFeld, manipuliertesBild, zeilen, spalten, 255);
            break;
        case 'g': glaetten(einleseFeld, manipuliertesBild, zeilen, spalten);
            break;
        case 'k': kantenbildung(einleseFeld, manipuliertesBild, zeilen, spalten);
            break;
        case 's': schaerfen(einleseFeld, manipuliertesBild, zeilen, spalten, 255);
            break;
        case 'e': exit(0);
    }



    //Header in AusgabeDatei schreiben
    ausgabeDatei << "P2" << '\n' << spalten << " " << zeilen << '\n' << 255 << '\n';

    //manipuliertes bild schreiben
    for (i = 0; i < zeilen; i++)
    {
        for (j = 0; j < spalten; j++)
        {
            ausgabeDatei << (int) manipuliertesBild[i][j];
            ausgabeDatei << ' ';
        }
        ausgabeDatei << '\n';
    }

    //Stream schließen
    ausgabeDatei.close();


    return 0;
}

/*Beschreibung: invertiert ein zweidimensionales unsigned char array
  Übergabeparameter: bild1: original feld; bild2: manipuliertes feld; nz Zeilen; ns Spalten; graumax maximaler Wert einer Zelle
 */
void invertieren(Pixel bild1[N][N], Pixel bild2[N][N], int nz, int ns, int graumax)
{
    for (i = 0; i < zeilen; i++)
    {
        for (j = 0; j < spalten; j++)
        {
            bild2[i][j] = graumax - bild1[i][j];
        }
    }
}

/*Beschreibung: glättet ein zweidimensionales unsigned char array
  Übergabeparameter: bild1: original feld; bild2: manipuliertes feld; nz Zeilen; ns Spalten
 */
void glaetten(Pixel bild1[N][N], Pixel bild2[N][N], int nz, int ns)
{
    int mittelWert = 0;

    for (i = 0; i < zeilen; i++)
    {
        for (j = 0; j < spalten; j++)
        {
            //Wenn mittelwertbildung möglich
            if (i > 0 && j > 0 && i < zeilen && j < spalten)
            {
                mittelWert = ((int) bild1[i][j]+(int) bild1[i][j - 1]+
                        (int) bild1[i][j + 1]+(int) bild1[i - 1][j]
                        +(int) bild1[i - 1][j - 1]+(int) bild1[i - 1][j +
                        1]+(int) bild1[i + 1][j - 1]+(int) bild1[i + 1][j]
                        +(int) bild1[i + 1][j + 1]) / 9;
            } else //sonst originalpixel
            {
                mittelWert = bild1[i][j];
            }
            bild2[i][j] = mittelWert;
        }
    }
}

/*Beschreibung: manipuliert ein bild (zweidimensionales char array) dahingehend, dass kanten nachgezeichnet werden
  Übergabeparameter: bild1: original feld; bild2: manipuliertes feld; nz Zeilen; ns Spalten
 */
void kantenbildung(Pixel bild1[N][N], Pixel bild2[N][N], int nz, int ns)
{
    int gewichtung = 0;
    for (i = 0; i < zeilen; i++)
    {
        for (j = 0; j < spalten; j++)
        {
            //Wenn mittelwertbildung möglich
            if (i > 0 && j > 0 && i < zeilen && j < spalten)
            {
                gewichtung = (4 * (int) bild1[i][j]-(int) bild1[i][j - 1]-
                        (int) bild1[i][j + 1]-(int) bild1[i - 1][j]
                        -(int) bild1[i + 1][j]) / 9;
            } else //sonst schwarz
            {
                gewichtung = 0;
            }

            bild2[i][j] = abs(gewichtung);
        }
    }
}

/*Beschreibung: schärft ein bild (zweidimensionales unsigned char array) 
  Übergabeparameter: bild1: original feld; bild2: manipuliertes feld; nz Zeilen; ns Spalten; graumax: maximaler Wert einer Zelle
 */
void schaerfen(Pixel bild1[N][N], Pixel bild2[N][N], int nz, int ns, int graumax)
{
    int gewichtung = 0;
    for (i = 0; i < zeilen; i++)
    {
        for (j = 0; j < spalten; j++)
        {
            //Wenn wertbildung möglich
            if (i > 0 && j > 0 && i < zeilen && j < spalten)
            {
                gewichtung = (9 * (int) bild1[i][j]-(int) bild1[i][j - 1]-
                        (int) bild1[i][j + 1]-(int) bild1[i - 1][j]
                        -(int) bild1[i - 1][j - 1]-(int) bild1[i - 1][j +
                        1]-(int) bild1[i + 1][j - 1]-(int) bild1[i + 1][j]
                        -(int) bild1[i + 1][j + 1]);
                if (gewichtung < 0) //falls wert kleiner als 0 auf schwarz werden
                {
                    gewichtung = 0;
                } else if (gewichtung > graumax) //falls größer als graumax auf weiß
                {
                    gewichtung = graumax;
                }
            } else //sonst schwarz
            {
                gewichtung = 0;
            }
            bild2[i][j] = abs(gewichtung);
        }
    }
}



