/*=========================================================

  Filename: main.cpp

  Author: Tobias Steppan

  Date: 14.11.2017

  Description: "Aufgabe 4 Umgang mit Texten"

==========================================================*/


#include <iomanip>   
#include <iostream>  
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

/*
 isAlpha wechselt zwischen Großbuchstaben/Kleinbuchstaben und Buchstaben
 */
void Aufgabe4_1(bool isAlpha)
{
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

    /*
     Aufforderung zur Texteingabe 
     */
    if (isAlpha)
    {
        cout << "***** Buchstaben sowie Ziffern abzählen *****\n";
    } else
    {
        cout << "***** Klein- und Großbuchstaben sowie Ziffern abzählen *****\n";
    }
    cout << "Geben Sie eine Textzeile ein: ";


    i = 0;
    while ((c = cin.get()) != '\n') //new line 
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

    //Ausgabe
    if (isAlpha)
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

bool CharIstZwischenraum(char c)
{
    bool result = false;
    if (c == 32 || c == 9) //wenn c leerzeichen oder horizontaler tab ist
    {
        result = true;
    }
    return result;
}

void Aufgabe4_2WoerterInEinemTextAbzaelhen()
{
    cout << "Aufgabe 4.2: Wörter in einem Textabzählen" << endl;
    cout << "Bitte geben Sie eine Textzeile ein." << endl;

    //einlesen
    int maxstring = 256;
    char c; //einzulesender Char
    char text[maxstring]; //eingelesene Chars
    int i = 0;
    while ((c = cin.get()) != '\n')
    {
        text[i] = c;
        i++;
    }
    text[i] = '\0'; //nullterminieren
    cout << "Der eingegebene Text lautet '" << text << "'\n";

    /*
     * zustand = 0 -> LEER
     * zustand = 1 -> WORT
     */
    int zustand = 0;
    int wortzaehler = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if ((isalpha(text[i])) && zustand == 0)
        {
            zustand = 1;
            wortzaehler++;
        }
        if (CharIstZwischenraum(text[i]))
        {
            zustand = 0;
        }
    }
    cout << "Anzahl der Worte: " << wortzaehler << endl;
}

void Aufgabe4_3WoererUndZahlenInEinemTextAbzaehlen()
{
    cout << "Aufgabe 4.3: Wörter und Zahlen in einem Textabzählen" << endl;
    cout << "Bitte geben Sie eine Textzeile ein." << endl;

    //einlesen
    int maxstring = 256;
    char c; //einzulesender Char
    char text[maxstring]; //eingelesene Chars
    int i = 0;
    while ((c = cin.get()) != '\n')
    {
        text[i] = c;
        i++;
    }
    text[i] = '\0'; //nullterminieren
    cout << "Der eingegebene Text lautet '" << text << "'\n";

    /*
     * zustand = 0 -> LEER
     * zustand = 1 -> WORT
     * zustand = 2 -> ZAHL
     */
    int zustand = 0;
    int wortZaehler = 0;
    int zahlZaehler = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if ((isdigit(text[i])) && zustand == 0)
        {
            zustand = 2;
            zahlZaehler++;
        }
        if ((isalpha(text[i])) && zustand == 0)
        {
            zustand = 1;
            wortZaehler++;
        }
        if (CharIstZwischenraum(text[i]))
        {
            zustand = 0;
        }
        //        Überprüfen ob in einer Zahl ein Buchstabe oder in einem Wort eine Zahl vorkommt
        if (((isalpha(text[i])) && zustand == 2) || ((isdigit(text[i])) && zustand == 1))
        {
            cout << "Fehler: ein Wort enthält eine Ziffer oder eine Zahl enthält einen Buchstaben!" << endl;
            exit(1);
        }
    }
    cout << "Anzahl der Worte: " << wortZaehler << endl << "Anzahl der Zahlen: " << zahlZaehler << endl;
}

void Aufgabe4_3WoererUndZahlenInEinemTextAbzaehlenMitTextDatei()
{
    cout << "Aufgabe 4.3: Wörter und Zahlen einer Textdatei einlesen" << endl;

    /*
     * zustand = 0 -> LEER
     * zustand = 1 -> WORT
     * zustand = 2 -> ZAHL
     */
    int zustand = 0;
    int wortZaehler = 0;
    int zahlZaehler = 0;
    char c; //einzulesender Char

    ifstream datei;
    datei.open("text.txt");
    if (!datei)
    {
        cout << "Fehler: Datei kann nicht geöffnet werden!" << endl;
        exit(1);
    }

    while (!datei.eof()) 
    {
        c=datei.get();
        if ((isdigit(c)) && zustand == 0)
        {
            zustand = 2;
            zahlZaehler++;
        }
        if ((isalpha(c)) && zustand == 0)
        {
            zustand = 1;
            wortZaehler++;
        }
        if (CharIstZwischenraum(c))
        {
            zustand = 0;
        }
        if (((isalpha(c)) && zustand == 2) || ((isdigit(c)) && zustand == 1))
        {
            cout << "Fehler: ein Wort enthält eine Ziffer oder eine Zahl enthält einen Buchstaben!" << endl;
            exit(1);
        }
    }
    datei.close();
    cout << "Anzahl der Worte: " << wortZaehler << endl << "Anzahl der Zahlen: " << zahlZaehler << endl;
}

int main()
{
//    bool nichtZwischenGrossUndKleinschreibungUnterscheiden = false;
//    Aufgabe4_1(nichtZwischenGrossUndKleinschreibungUnterscheiden);
//    nichtZwischenGrossUndKleinschreibungUnterscheiden = true;
//    Aufgabe4_1(nichtZwischenGrossUndKleinschreibungUnterscheiden);
//    Aufgabe4_2WoerterInEinemTextAbzaelhen();
//    Aufgabe4_3WoererUndZahlenInEinemTextAbzaehlen();
    Aufgabe4_3WoererUndZahlenInEinemTextAbzaehlenMitTextDatei();
    return 0;
}