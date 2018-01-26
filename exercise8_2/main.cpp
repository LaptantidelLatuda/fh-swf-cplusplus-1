/* 
 * File:   main.cpp
 * Author: Tobias Steppan
 * Description: Lösung zur Aufgabe: 8.2 Darstellung von Mengen kleiner Zahlen
 * Created on 26. Januar 2018, 19:02
 */

//Standard General Utilities Library
#include <cstdlib>
#include <climits>
#include <string>
#include <iostream>

using namespace std;

//Typendefinition
typedef char SmallSet;
typedef unsigned int uint;

//Prototypen
uint set_count(SmallSet *s);
uint set_first(SmallSet *s);
void set_clear(SmallSet *s, uint n);
void set_complement(SmallSet *s);
void set_empty(SmallSet *s);
void set_print(SmallSet *s, string name);
void set_set(SmallSet *s, uint n);

int main(int argc, char** argv)
{
    //Test Parameter
    SmallSet testSet = 128;
    string mengenName = "s1";
    int clearDigit = 5;
    int setDigit = 5;

    //Test Szenario
    set_print(&testSet, mengenName);
    uint resultCount = set_count(&testSet);
    cout << "count: " << resultCount << endl;
    uint resultFirst = set_first(&testSet);
    cout << "smallest element: " << resultFirst << endl;
    set_clear(&testSet, clearDigit);
    cout << "clear digit: " << clearDigit << endl;
    set_print(&testSet, mengenName);
    cout << "complement: " << endl;
    set_complement(&testSet);
    set_print(&testSet, mengenName);
    cout << "empty: " << endl;
    set_empty(&testSet);
    set_print(&testSet, mengenName);
    cout << "set bit: " << setDigit << endl;
    set_set(&testSet, setDigit);
    set_print(&testSet, mengenName);
    return 0;
}

/**
 * Zählt die Anzahl der gesetzten Bits
 * @param s Pointer auf char mit zu zählenden Bits
 * @return Anzahl der gesetzten Bits
 */
uint set_count(SmallSet *s)
{
    //Zähler für die gesetzten Bits
    uint result = 0;
    //Maske: ein Bit um sieben Stellen nach links schieben. 1000 0000 = 128 
    uint maske = 1U << (CHAR_BIT - 1);
    //Acht mal Bitweise Vergleich der Maske mit dem dereferenzierten Char entspricht dem Zählen der gesetzten bits
    for (int i = 0; i < CHAR_BIT; i++)
    {
        if (*s & maske)
            result++;
        //Nach jedem durchlauf muss die Bitmaske um ein Bit verschoben werden
        maske >>= 1;
    }
    return result;
}

/**
 * Gibt die Nummer des kleinsten gesetzten Bit zurück, falls kein Bit gesetzt ist 
 * gibt die Methode den Wert 8 zurück 
 * @param s Pointer auf den zu analysierenden Char 
 * @return Nummer des kleinsten gesetzten Bit
 */
uint set_first(SmallSet *s)
{
    uint result = 8;
    uint maske = 1U << (CHAR_BIT - 1);
    for (int i = CHAR_BIT - 1; i >= 0; i--)
    {
        if (*s & maske)
            result = i;
        maske >>= 1;

    }
    return result;
}

/**
 * Ein Bit löschen
 * @param s pointer auf den Char dessen 
 * @param n - tes Bit gelöscht werden soll 
 */
void set_clear(SmallSet *s, uint n)
{
    //Über maske potenz berechnen
    char maske = (1U << (n));
    //potenz passend zur bit nummer abziehen
    if (maske&*s)
        *s = *s - maske;
}

/**
 * Komplementmenge erzeugen
 * @param s pointer auf char dessen komplementmenge zu bilden ist
 */
void set_complement(SmallSet *s)
{
    //Maske: ein Bit um sieben Stellen nach links schieben. 1000 0000 = 128 
    uint maske = 1U << (CHAR_BIT - 1);
    char komplement = 0;
    for (int i = 0; i < CHAR_BIT; i++)
    {
        //Falls das betrachtete bit 1 ist abziehen, ansonsten addieren
        if ((*s & maske) == 0)
            komplement += maske;
        //Nach jedem durchlauf muss die Bitmaske um ein Bit verschoben werden
        maske >>= 1;
    }
    *s = komplement;
}

/**
 * Löscht alle Bits
 * @param s pointer auf char mit zu löschenden Bits
 */
void set_empty(SmallSet *s)
{
    *s = 0;
}

/**
 * Ausgabe als Folge von acht nullen und einsen.
 * @param s pointer auf bitweise auszugebenden char
 * @param name text der vorangestellt wird
 */
void set_print(SmallSet *s, string name)
{
    uint maske = 1U << (CHAR_BIT - 1);
    cout << "Menge " << name << " : ";
    for (int i = 0; i < CHAR_BIT; i++)
    {
        if (*s & maske)
            cout << "1";
        else
            cout << "0";
        maske >>= 1;
    }
    cout << endl;
}

/**
 * Ein bestimmtes Bit über nummer setzen 
 * @param s pointer auf char dessen bestimmtes bit gesetzt werden soll
 * @param n nummer des zu setzenden bits
 */
void set_set(SmallSet *s, uint n)
{
    //Über maske potenz berechnen
    char maske = (1U << (n));
    //potenz passend zur bit nummer abziehen
    if (!(maske&*s))
        *s = *s  + maske;
}




