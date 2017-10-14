/*=========================================================

  Filename: main.cpp

  Author: Tobias Steppan

  Date: 30.09.2017

  Description: "Aufgabe: Summation unendlicher Reihen"

==========================================================*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int durchlaeufe=0;

double HarmonischeReiheSumme1000Summanden()
{
    /*  description:    Errechnet die ersten 1000 Summanden der Harmonischen Reihe
        parameters:     n/a
        return value:   Ergebnis auf fünf Nachkommastellen gerundet (konvergiert gegen unendlich)
    */
    double result=0.0;
    for(int i = 1; i<=1000; i++)
    {
        result += 1.0/i;
    }
    return result;
}

double AlternierendeHarmonischeReiheSumme1000Summanden()
{
    /*  description:    Errechnet die ersten 1000 Summanden der Alternierenden Harmonischen Reihe
        parameters:     n/a
        return value:   Ergebnis(konvergiert gegen ln(2) = 0,6931471806
    */
    double result=0.0;
    int vorzeichen = 1;
    double summand;
    for (int i = 1; i<=1000; i++)
    {
        summand = vorzeichen*1.0/i;
        result += summand;
        vorzeichen = -vorzeichen;
    }
    return result;
}

double LeibnizscheReiheSumme1000Summanden()
{
    /*  description:    Errechnet die ersten 1000 Summanden der Leibnizschen Reihe
        parameters:     n/a
        return value:   Ergebnis (konvergiert gegen pi/4 = 0,7853961634
    */
    double result=0.0;
    int vorzeichen=1;
    double summand;
    for(int i = 1; i<=1000;i++)
    {
        summand = vorzeichen*1.0/(2*i-1);
        result += summand;
        vorzeichen = -vorzeichen;
    }
    return result;
}

double GeometrischeReiheSumme1000Summanden()
{
    /*  description:    Errechnet die ersten 1000 Summanden der Geometrischen Reihe
        parameters:     n/a
        return value:   Ergebnis (konvergiert gegen 2)
    */
    double result=1.0;
    double summand=1;
    for(int i = 1; i<1000;i++) //erster summand ist vorinitialisiert
    {
        summand = 0.5*summand;
        result += summand;

    }
    return result;
}

long double GeometrischeReihe()
{
    /*  description:    Aufgabe 1.2. Aufsummieren bis sich nichts mehr ändert. Durläufe stehen in "durchlaeufe"
        parameters:     n/a
        return value:   Ergebnis
    */
    long double result=1.0;
    long double lastResult;
    long double summand=1.0;
    while(1)
    {
        lastResult = result;
        summand = 0.5*summand;
        result += summand;
        durchlaeufe++;
        if(lastResult==result){break;}
    }
    durchlaeufe++; //0. Durchlauf mitzählen
    return result;
}

double Exponentialfunktion()
{
    /*  description:    Aufgabe 1.3. Reihensumme für x=1.2 bis sich die Summe nicht mehr ändert
        parameters:     n/a
        return value:   Ergebnis (konvergiert gegen 3.32
    */
    double result=1.0;
    double lastResult;
    double s_i = 0.0;
    int i = 1;
    double s_iminus1=1;
    while(1)
    {
        lastResult = result;
        s_i = (1.2/i)*s_iminus1;
        result = lastResult + s_i;
        s_iminus1 = s_i;
        i++;
        if(lastResult==result){break;}
    }
    return result;
}

double CosinusHyperpolicus()
{
    /*  description:    Aufgabe 1.3. Reihensumme für x=1.2 bis sich die Summe nicht mehr ändert
        parameters:     n/a
        return value:   Ergebnis(konvergiert gegen 1.81066)
    */
    double result=1.0;
    double lastResult;
    double s_i = 0.0;
    int i = 1;
    double s_iminus1=1;
    while(1)
    {
        lastResult = result;
        s_i = ((1.2*1.2)/(2*i))*s_iminus1;
        result = lastResult + s_i;
        s_iminus1 = s_i;
        i++;
        if(lastResult==result){break;}
    }
    return result;
}

int main()
{
/*  description:    c++ main method
    parameters:
    return value:
*/
    double harmonisch = HarmonischeReiheSumme1000Summanden();
    double alternierend = AlternierendeHarmonischeReiheSumme1000Summanden();
    double leibniz = LeibnizscheReiheSumme1000Summanden();
    double geometrisch = GeometrischeReiheSumme1000Summanden();

    //Aufgabe 1.1
    cout<<"Aufgabe 1.1\n";
    cout <<setprecision(6)<< "Summe der ersten 1000 Summanden der Harmonischen Reihe:\t\t\t" << harmonisch << "\n\n" <<endl;
    cout <<setprecision(6)<< "Summe der ersten 1000 Summanden der Alternierenden harmonischen Reihe:\t" << alternierend<<"\n\n"<<endl;
    cout <<setprecision(6)<< "Summe der ersten 1000 Summanden der Leibnizschen Reihe:\t\t\t"<<leibniz<<"\n\n"<<endl;
    cout <<setprecision(6)<< "Summe der ersten 1000 Summanden der geometrischen Reihe:\t\t"<<geometrisch<<"\n\n\n"<<endl;

    //Aufgabe 1.2
    long double konvergiertGegen=GeometrischeReihe();
    cout <<"Aufagbe 1.2\n"<<endl;
    cout << setprecision(17)<< "Konvergiert gegen: " << konvergiertGegen<<" nach: "<<durchlaeufe<< " Aufrufen.\n\n\n"<<endl;

    //Aufgabe 1.3
    cout <<"Aufgabe 1.3 \n"<<endl;
    cout <<"Reihensumme der Exponentialfunktion fuer x = 1.2: e^1.2 = " << Exponentialfunktion()<<"\n"<<endl;
    cout <<"Reihensumme der Cosinus-Hyperbolicus Funktion fuer x = 1.2: cosh(1.2) = " << CosinusHyperpolicus() <<"\n"<<endl;
    return 0;
}









