/* 
 * File:   main.cpp
 * Author: Tobias Steppan
 * Description: Lösung zur Aufgabe: 1.1. Bildverarbeitung 3 Verwendung von Strukturen
 * Created on 27. Febrauar 2018, 09:51
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

//Typdefinitionen

typedef unsigned char Pixel;

//Datentyp

struct pgm_bild
{
    char magic[2]; //Bildtyp
    int nx; //Zeilenzahl
    int ny; //Spaltenzahl
    int graumax; //maximaler Grauwert
    Pixel **bild; //Bildmatrix
};

//Prototypen
void bild_lesen(pgm_bild *bild, string ifs_file_name);
void bild_schreiben(pgm_bild *bild, string ofs_file_name);
void delete_pixel_matrix(Pixel **m);
Pixel** new_pixel_matrix(size_t rows, size_t columns);
void glatten(pgm_bild *bild1, pgm_bild *bild2);
void invertieren(pgm_bild *bild1, pgm_bild *bild2);
void kantenbildung(pgm_bild *bild1, pgm_bild *bild2);
void kopiere_bildkopf(pgm_bild *bild1, pgm_bild *bild2);
void schwellenwert(pgm_bild *bild1, pgm_bild *bild2, Pixel schwellenwert);

int main(int argc, char** argv)
{
    //neuer struct pgm_bild
    pgm_bild * bild = new pgm_bild;
    //grauwert angeben
    bild->graumax = 255;
    bild_lesen(bild, "dreifach.pgm");
    return 0;
}

/**
 * Liest ein Bild ein und speichert es in dem struct bild ab
 * @param bild: datentyp pgm_bild in dem das einzulesende pgm bild abgespeichert wird
 * @param ifs_file_name dateipfad im hauptverzeichnis auf das einzulesende bild
 */
void bild_lesen(pgm_bild *bild, string ifs_file_name)
{
    //ifstream Objekt erstellen
    ifstream eingabeDatei;

    //Datei öffnen
    eingabeDatei.open(ifs_file_name);

    //Abfragen ob eingabeDatei geöffnet werden konnte
    if (!eingabeDatei)
    {
        cerr << endl << "Error: failed to open input file ! " << endl;
        exit(1);
    }

    //Einzulesendes Element
    string element;

    //Array dynamisch allokieren
    Pixel **eingabeFeld;

    //ElementZähler ersten 4 elemente abziehen
    int elementCounter = -3;

    int i = 0, j = 0, maxZeilen = 1000;

    /*eingabeDatei einlesen
     */
    while (eingabeDatei >> element)
    {

        //Array füllen nach dem header
        if (elementCounter > 0)
        {
            eingabeFeld = new_pixel_matrix(bild->nx, bild->ny);
            eingabeFeld[i][j] = stoi(element);
            j++;
            //Nach x Zeilen in nächste Spalte springen
            if (j == bild->ny)
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
            if ((elementCounter == -2 || elementCounter == -1)&&(stoi(element) > maxZeilen))
            {
                cout << "Bild zu groß";
                break;
            }
            //nach Element 3 Neue Zeile und Zeilenzahl merken
            if (elementCounter == -1)
            {
                cout << endl;
                bild->nx = stoi(element);
            }
            //nach Element 2 Leerzeile und spaltenzahl merken
            if (elementCounter == -2)
            {
                cout << " ";
                bild->ny = stoi(element);
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

    //Array an Struct übergeben
    bild->bild = eingabeFeld;
    
    //eingabeFeld speicher freigeben
    delete_pixel_matrix(eingabeFeld);
}

/**
 * Allokiere eine neue Pixelmatrix mit der Größe ros*columns
 * @param rows reihen
 * @param columns spalten
 * @return pointer auf pointer auf pixel
 */
Pixel ** new_pixel_matrix(size_t rows, size_t columns)
{
    size_t i;
    Pixel **m;

    //pointer array
    m = new Pixel * [rows];

    //Daten Array
    *m = new Pixel [rows * columns];
    for (i = 1; i < rows; i++)
        m[i] = m[i - 1] + columns;
    return m;
}

/**
 * Gibt allkokierten Speicher eines 2d Arrays frei
 * @param m freizugebendes Array
 */
void delete_pixel_matrix(Pixel **m)
{
    //lösche daten array
    delete [] * m;

    //lösche pointer array
    delete [] m;
}

