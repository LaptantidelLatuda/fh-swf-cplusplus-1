/* 
 * File:   main.cpp
 * Author: Tobias Steppan
 * Description: Lösung zur Aufgabe: 6.1. Belegung zweidimensionaler Felder
 * Created on 07. December 2017, 16:54
 */

//Standard General Utilities Library
#include <cstdlib>

//IO Stream Objects
#include <iostream>

using namespace std;

//typendefinition
typedef unsigned int uint;

//Zeilen und Spaltenzahl
const unsigned int nmat = 10;

//Prototypen
void matrix_diag(int mat[nmat][nmat], uint n, int diag, int value);
void matrix_dreieck(int mat[nmat][nmat], uint n, int k, int value);
void matrix_frame(int mat[nmat][nmat], uint n, uint frame, int value);
void matrix_null(int mat[nmat][nmat], uint n);
void matrix_print(int mat[nmat][nmat], uint n);

int main(int argc, char** argv)
{
    //testszenario
    int matrix [nmat][nmat];

    matrix_null(matrix, nmat);

    cout << endl << "Nullmatrix" << endl;
    matrix_print(matrix, nmat);

    matrix_null(matrix, nmat);

    matrix_frame(matrix, nmat, 3, 1);

    cout << endl << "Frame Matrix:" << endl;
    matrix_print(matrix, nmat);

    matrix_null(matrix, nmat);

    matrix_diag(matrix, nmat, 2, 1);

    cout << endl << "Diagonal Matrix:" << endl;
    matrix_print(matrix, nmat);

    matrix_null(matrix, nmat);

    matrix_dreieck(matrix, nmat, 6, 1);

    cout << endl << "Dreieck Matrix:" << endl;
    matrix_print(matrix, nmat);

    return 0;
}

/* Beschreibung: bearbeitet eine matrix dahingehend, dass eine dreiecksmatrix ensteht  
 * Übergabeparameter: mat: zweidimensionales int array das bearbeitet werden soll
 *                    n:   zeilen und spalten der matrix
 *                    k: anzahl der diagonalen, die in der oberen linken ecke gezeichnet werden
 *                    value: wert mit dem die diagonalen elemente gefüllt werden    
 */
void matrix_dreieck(int mat[nmat][nmat], uint n, int k, int value)
{
    //Ab größter Größe für k wird k gleich der größten größe gesetzt
    if (k > 2 * n - 1)
    {
        k = 2 * n - 1;
        cout << endl << "k größer als möglicher Bereich, wird auf den Maximalwert: " << 2 * n + 1 << " gesetzt!" << endl;
    }

    //array pointer
    int *matrixPointer = &mat[0][0];

    for (int i = 0; i < n * n; i++)
    {
        //anzahl der vertikal zu zeichnenden reihen muss kleiner als k sein
        if (i < k)
        {
            //k-i: pro nächster vertikalen reihe ein element kürzer
            for (int j = 0; j < (k - i); j++)
            {
                *(matrixPointer + n * i + j) = value;
            }
        }
    }
}

/* Beschreibung: bearbeitet eine matrix dahingehend, dass eine diagonalmatrix entsteht
 * Übergabeparameter: mat: zweidimensionales int array das bearbeitet werden soll
 *                    n:   zeilen und spalten der matrix
 *                    diag: anzahl der hauptdiagonalen
 *                    value: wert mit dem die diagonalen elemente gefüllt werden    
 */
void matrix_diag(int mat[nmat][nmat], uint n, int diag, int value)
{
    //Abfangen von falschen eingaben und ausgabe darüber
    if (diag % 2 == 0)
        cout << endl << "Diag: " << diag << " ist gerade. Es wird auf die nächst höhere ungerade Diagonalenanzahl gerundet!" << endl;
    if (diag > 2 * n - 1)
    {
        diag = 2 * n - 1;
        cout << endl << "Diag größer als der mögliche Bereich, maximalwert: " << diag << "wird angenommen " << endl;
    }

    //array pointer
    int *matrixPointer = &mat[0][0];

    //diagonalen zeichnen
    for (int i = 0; i < n * n; i++)
    {
        //hauptdiagonale alternierend verschieben
        for (int j = 0; j <= (diag / 2); j++)
        {
            if ((i % n == ((i / n) + j)) || (i % n == ((i / n) - j)))
                *(matrixPointer + i) = value;
        }

        //Ausgabe ob auf die nächst höhere diagonalenanzahl gerundet wird

    }
}

/* Beschreibung: erstellt einen rahmen aus "value" in einem zweidimensionalem array mit der rahmendicke 'frame
 * Übergabeparameter: mat: zweidimensionales int array das 
 *                    n:   zeilen und spalten hat
 *                    frame: einen franme dicken rahmen erhalten soll  
 *                    value: wert aus dem der rahemn besteht    
 */
void matrix_frame(int mat[nmat][nmat], uint n, uint frame, int value)
{
    //ab größtmöglicher größe für frame wird frame maximal gesetzt
    if (frame >= ((n / 2) + 1))
    {
        frame = (n / 2) + 1;
        cout << endl << "frame größer als möglicher Bereich, wird auf den Maximalwert: " << (n / 2) + 1 << " gesetzt!" << endl;
    }

    //array pointer
    int *matrixPointer = &mat[0][0];

    //rahmen erstellen
    for (int i = 0; i < n * n; i++)
    {
        //Filter des todes of doom 

        if (i % n <= frame - 1 || i % n >= (n - frame) || i < (n * frame) || i > ((n * n)-(n * frame + 1)))
            *(matrixPointer + i) = value;
    }
}

/* Beschreibung: befüllt ein zweidimensionales array mit nullen
 * Übergabeparameter: mat: zweidimensionales int array das 
 *                    n:   zeilen und spalten hat
 */
void matrix_null(int mat[nmat][nmat], uint n)
{
    //array pointer
    int *matrixPointer = &mat[0][0];

    //nullen zuweisen
    for (int i = 0; i < n * n; i++)
    {

        *(matrixPointer + i) = 0;
    }
}

/* Beschreibung: gibt eine zweidimensionales array aus
 * Übergabeparameter: mat: zweidimensionales int array das 
 *                    n:   zeilen und spalten hat
 */
void matrix_print(int mat[nmat][nmat], uint n)
{
    //array pointer
    int *matrixPointer = &mat[0][0];

    //zähler für addition auf pointer
    int k = 0;

    //ausgabe
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //            cout << mat[i][j] << " "; //konventionell
            cout << *(matrixPointer + k) << " ";
            k++;
        }
        cout << endl;
    }
}



