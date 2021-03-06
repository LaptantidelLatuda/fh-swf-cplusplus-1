//============================================================================
// Name        : VC1KWS17-A3.cpp
// Author      : Uwe Gogolin
//
// Description : Klausur "Programmierung mit C++ 1", Verbund, WS2017/18
//					Aufgabe 3: Schachbrett
//
//				 Hinweise: Da die Eingabe einer Position zwei mal erfolgen soll
//							wäre eine Auslagerung der Eingabe in eine eigene
//							Funktion sinnvoll!
//						   Beachten Sie auch, dass es in der Natur von Aufgaben-
//							stellungen wie dieser liegt, dass sich verschiedene
//							richtige Lösungen stark unterscheiden können.
//						   "Musterlösung" soll hier also nur als
//						   "Eine mögliche richtige Lösung" verstanden werden!
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

struct Figur	// Struktur mit Namen und Position einer
{				// Schachfigur (Name hier irrelevant)
	string figurenName;
	unsigned char  x;
	unsigned char  y;
};

// Anzahl der Figuren im Array figuren
const int FIGURENANZAHL = 4;

/*============================================================================
*
* Function:	ausgabe
* Description: Gibt das im Array Spielfeld enthaltene 8x8 Feld
* 				(Schachbrett) aus.
*
* @param unsigned char** spielfeld: Pointer auf auszugebendes 8x8-2D-Feld
*========================================================================= */
void ausgabe(unsigned char** spielfeld);

/*============================================================================
*
* Function:	nextMove
* Description: siehe Klausur
* 				(Zusatz: In der Aufgabenstellung ist verloren gegangen, dass
* 						 an der Stelle einer Figur auch ein besonderes Zeichen
* 						 im 2D-Array stehen soll. Geplant war: Array ist
* 						 gefüllt mit Leerzeichen, an Stelle einer Figur steht 'X'.
*
* @param unsigned char** spielfeld: 8x8 Array (Schachbrett)
* @param Figur* figuren: Array mit Structs der Schachfiguren
* @returns: Startadresse des neu erstellten 8x8 Arrays
*========================================================================= */
unsigned char** nextMove(unsigned char** spielfeld, Figur* figuren)
{
	// Neues 8x8 Array erstellen
	unsigned char** spielfeldNeu = new unsigned char *[8];
	for (int var = 0; var < 8; var++)
	{
		spielfeldNeu[var] = new unsigned char[8];

		// Inhalt des übergebenen Feld kopieren
		// (zur Lösung aufgrund des Fehlers in der Aufgabenstellung nicht zwangsweise nötig)
		for (int var2 = 0; var2 < 8; var2++)
		{
			spielfeldNeu[var][var2] = spielfeld[var][var2];
		}
	}

	string eingabe;
	unsigned char figurindex = 0;		// Index zu ziehender Figur im Array figuren
	bool eingabeOK = false;	// Zum check ob gewählte Position erlaubt
	unsigned char posx = 255;		// Gewählte X-Position
	unsigned char posy = 255;		// Gewählte Y-Position
									// 255 liegt außerhalb erlaubter Positionen,
									// alles außer 0-8 (bzw. 0-7) wäre möglich.

	ausgabe(spielfeldNeu);

	while (!eingabeOK)	// Schleife läuft, bis eine Figur ausgewählt wurde
	{
		cout << "Figur Auswählen: Position der Figur eingeben: ";
		cin >> eingabe;

		// Koordinaten müssen 2 Werte sein
		if (eingabe.length() == 2)
		{	// * (siehe Zeile 90)
			posx = eingabe[0] - 'A'; // Zeichen A bis H auf Werte 0 bis 7 abbilden
			posy = eingabe[1] - '1'; // Zeichen 1 bis 8 auf Werte 0 bis 7 abbilden
			posy = 7 - posy;			 // Schachbrett: erste Zeile 8, letzte Zeile 1
										 // Array:       erste Zeile 0, letzte Zeile 7
										 // Testausgabe, keine Teil der Lösung:
			cout << "eingabe " << eingabe << " PosX: " << (int)posx << " PosY: " << (int)posy << endl;
		}

		// Array mit Spielfiguren durchgehen und Figur an angegebener Position suchen
		// Ein Speichern der Position wie eingegeben (also z.B. posx = 'A' und posy = '8')
		// Wäre ebenfalls möglich.
		// Dann ist aber eine Berechnung ähnlich dieser* (siehe Zeile 80f) nötig, wenn
		// die Zielposition geprüft wird.
		// Das Prüfen, ob an der ausgewählten Position eine Figur steht ist nach
		// Aufgabenstellung nicht notwendig.
		for (int i = 0; i < FIGURENANZAHL; i++)
		{
			if (figuren[i].x == posx)
			{
				if (figuren[i].y == posy)
				{	// Figur gefunden. 'X' an der Stelle mit ' ' überschreiben.
					spielfeldNeu[posy][posx] = ' ';
					eingabeOK = true;	// Legale Position, keine weiterer Durchlauf der Eingabeschleife
					figurindex = i;		// Figurposition speichern
					break;				// Figur gefunden - kein weiterer Durchlauf nötig
				}
			}
		} // Ende der Schleife. 'figurindex' ist Index der gewählten Figur
		  //													- oder die Schleife läuft weiter.
		if (!eingabeOK) // An eingegebener Position ist keine Figur
		{
			cout << "Keine Figur bei " << eingabe << endl << endl;
		}
	}

	cout << "Figur bei " << eingabe << " ausgewählt" << endl << endl;
	eingabeOK = false;	// Zurücksetzen, wird wiederverwendet

	while (!eingabeOK)
	{
		cout << "Ziel der Figur eingeben: ";
		cin >> eingabe;
		posx = eingabe[0] - 'A'; // Zeichen A bis H auf Werte 0 bis 7 abbilden
		posy = eingabe[1] - '1'; // Zeichen 1 bis 8 auf Werte 0 bis 7 abbilden
		posy = 7 - posy;			 // Schachbrett: erste Zeile 8, letzte Zeile 1

									 // Prüfen ob Zielposition innerhalb des 8x8 Felds
		if (posx >= 0 && posx < 8 && posy >= 0 && posy < 8)
		{
			// Wenn Zielposition leer (falls Sie das Array nicht weiter verwendet haben
			//	müßte hier Code ähnlich der Zeilen 94f stehen)
			if (spielfeldNeu[posy][posx] == ' ')
			{
				cout << "Figur versetzten: posx: " << (int)posx << " posy: " << (int)posy << " Figurindex: " << (int)figurindex << endl;
				// Keine weitere Eingabe nötig, X an neue Position der Figur schreiben
				eingabeOK = true;				// Eingabeschleife beenden
				spielfeldNeu[posy][posx] = 'X';	// 'X' ins Array schreiben und
				figuren[figurindex].x = posx;	// neue Position im struct
				figuren[figurindex].y = posy;	// der Figur speichern
			}
			else
				cout << eingabe << " ist schon besetzt" << endl;
		}
		else
		{
			cout << eingabe << " ist keine Position auf dem Schachbrett" << endl;
		}
	}

	// Übergebenes Array freigeben
	for (int var = 0; var < 8; var++)
	{
		delete[] spielfeld[var];
	}
	delete[] spielfeld;

	return spielfeldNeu;	// Startadresse des neuen Schachbretts zurückgeben
}

void ausgabe(unsigned char** spielfeld)
{
	cout << "  ";
	for (int var = 0; var < 8; var++)
	{
		cout << char('A' + var) << " ";
	}
	cout << endl;

	for (int var = 0; var < 8; var++)
	{
		cout << 8 - var << " ";
		for (int var2 = 0; var2 < 8; var2++)
		{
			cout << spielfeld[var][var2] << " ";
		}
		cout << 8 - var << endl;
	}

	cout << "  ";
	for (int var = 0; var < 8; var++)
	{
		cout << char('A' + var) << " ";
	}
	cout << endl;
}

int main()
{
	Figur figuren[FIGURENANZAHL];
	figuren[0].x = 7;
	figuren[0].y = 1;
	figuren[1].x = 7;
	figuren[1].y = 6;

	figuren[2].x = 0;
	figuren[2].y = 1;

	figuren[3].x = 0;
	figuren[3].y = 6;

	unsigned char** spielfeld = new unsigned char *[8];
	for (int var = 0; var < 8; var++)
	{
		spielfeld[var] = new unsigned char[8];
		for (int var2 = 0; var2 < 8; var2++)
		{
			spielfeld[var][var2] = ' ';
		}
	}
	spielfeld[figuren[0].y][figuren[0].x] = 'X';
	spielfeld[figuren[1].y][figuren[1].x] = 'X';
	spielfeld[figuren[2].y][figuren[2].x] = 'X';
	spielfeld[figuren[3].y][figuren[3].x] = 'X';


	unsigned char** spielfeldNeu = nextMove(spielfeld, figuren);


	while (true)	spielfeldNeu = nextMove(spielfeldNeu, figuren);


	for (int var = 0; var < 8; var++)
	{
		delete[] spielfeldNeu[var];
	}
	delete[] spielfeldNeu;

	return 0;
}
