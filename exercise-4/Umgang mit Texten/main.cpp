/* 
 * File:   main.cpp
 * Author: Tobias
 *
 * Created on 1. November 2017, 13:53
 */


#include <iomanip>   
#include <iostream>  

using namespace std;

void Aufgabe4_1Fremdcode(bool isAlpha)
{
    //
    // fremdcode 
    // =====================================================================================
    //
    //       Filename:  1.11.string.cc
    //
    //    Description:  
    //
    //        Version:  1.0
    //        Created:  02.07.2013 20:59:50
    //       Revision:  none
    //       Compiler:  g++
    //
    //         Author:  Dr. Fritz Mehner (fgm), mehner.fritz@fh-swf.de
    //   Organization:  FH Südwestfalen, Iserlohn
    //
    // =====================================================================================
    int maxstring = 256; // Puffergröße
    char text[maxstring]; // Eingabepuffer
    char c; // Hilfsvariable
    int i, summekl, summegr; // Schleifenzähler,Buchstabezähler

    int summeZiffer = 0, summeBuchstaben = 0; //Ziffernzähler hinzugefügt

    cout << "***** Klein- und Großbuchstaben abzählen *****\n";
    cout << "Geben Sie eine Textzeile ein: ";

    i = 0;
    while ((c = cin.get()) != '\n')
    { // Einzelzeichen lesen
        text[i] = c; //  und im Feld ablegen
        i = i + 1; // Schleifenzähler erhöhen
    }
    text[i] = '\0'; // Zeichenkette abschließen

    cout << "Der eingegebene Text lautet '" << text << "'\n";

    summekl = summegr = 0;
    for (i = 0; text[i] != '\0'; i += 1)
    {
        if (isAlpha) // hinzugefügt
        {
            if (isalpha(text[i])) summeBuchstaben++;
            if (isdigit(text[i])) summeZiffer++; //hinzugefügt
        } else
        {
            if (islower(text[i])) summekl = summekl + 1;
            if (isupper(text[i])) summegr = summegr + 1;
            if (isdigit(text[i])) summeZiffer++; //hinzugefügt

        }
    }
    if (isAlpha) //hinzugefügt
    {
        cout << setw(6) << summeBuchstaben << " Buchstaben" << endl;
        cout << setw(6) << summeZiffer << " Ziffern" << endl;
    } else
    {
        cout << setw(6) << summekl << " Kleinbuchstaben\n";
        cout << setw(6) << summegr << " Großbuchstaben\n";
        cout << setw(6) << summeZiffer << " Ziffern" << endl; //hinzugefügt
    }
}

int main()
{
    bool nurBuchstabenZaehlen=false;
//    Aufgabe4_1Fremdcode(nurBuchstabenZaehlen);
    nurBuchstabenZaehlen=true;
    Aufgabe4_1Fremdcode(nurBuchstabenZaehlen);
    return 0;
}