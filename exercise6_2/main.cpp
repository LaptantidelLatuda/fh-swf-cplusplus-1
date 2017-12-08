/* 
 * File:   main.cpp
 * Author: Tobias Steppan
 * Description: Lösung zur Aufgabe: 6.2. Luhn-Algorithmus
 * Created on 08. December 2017, 16:54
 */

//Standard General Utilities Library
#include <cstdlib>

//IO Stream Objects
#include <iostream>

//String bibliothek
#include<string>

using namespace std;

#include <cstdlib>

using namespace std;

bool luhn_check(string number);

int main(int argc, char** argv)
{
    string n_1 = "446667651";
    string n_2 = "49927398716";
    string n_3 = "49927398717";
    string n_4 = "1234567812345678";
    string n_5 = "1234567812345670";

    cout << "Nummer:" << n_1 << " ergibt:" << endl;
    if (luhn_check(n_1))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    cout << "Nummer:" << n_2 << " ergibt:" << endl;
    if (luhn_check(n_2))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    cout << "Nummer:" << n_3 << " ergibt:" << endl;
    if (luhn_check(n_3))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    cout << "Nummer:" << n_4 << " ergibt:" << endl;
    if (luhn_check(n_4))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    cout << "Nummer:" << n_5 << " ergibt:" << endl;
    if (luhn_check(n_5))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}

/*Beschreibung: errechnet eine Prüfsumme nach dem luhn-algorithmus
  Übergabeparameter: number - zu überprüfende nummer
  Rückgabeparamater: bool - true wenn nummer korrekt
                          - false wenn nummer nicht korrekt
 */
bool luhn_check(string number)
{    
    int gewicht=2;
    int vorzeichen = -1;
    int gewichtet;
    int quersumme;
    int summe=0;
    
    for (int i = (number.length()-1); i >= 0; i--)
    {   
        gewicht = gewicht + vorzeichen;
        vorzeichen = -vorzeichen;
        gewichtet=((number[i]-48)*gewicht);
        quersumme=gewichtet%10+gewichtet/10;
        summe +=quersumme;
    }
    
    //wenn einerziffer 0 dann ist die kartennummer korrekt, sonst nicht
    if(summe%10==0)
        return true;
    else
        return false;
}

