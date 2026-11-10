#include "common.h"
#include "pbma.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Prüfung, ob ein Wort zu lange ist
void oversize(const string &w, int B) {
	if (w.size() > B) {
		throw runtime_error("Wort zu lang: " + w);
	}
}

// Liefert vector aus eigenem Datentyp Zeile
vector<Zeile> fillZeilen(const vector<string> &text, int B) {
	vector<Zeile> Zeilen;

	size_t pos { 0 };

	// Äußere Schleife = Bis Textende
	while (pos < text.size()) {
		Zeile z;
		z._pos = pos;  // Startposition der nächsten Zeile
		while (pos < text.size()) {
			oversize(text[pos], B);

			int nB = text[pos].size();  // Breite des nächsten Worts
			int gesB = z._gesB + nB;   // Neue Gesamtbreite temporär speichern

			if (z._wortB > 0) gesB++; // +1 für Leerzeichen, wenn nicht erstes Wort

			if (gesB > B) break;  // Abbruch, wenn B überschritten
			if (z._wortB > 0) z._leerB++; // +1 für Leerzeichen, wenn nicht erstes Wort

			z._wortB += nB;
			z._gesB = z._leerB + z._wortB;
			pos++;
		}
		long restB = B - z._gesB;
		z._gesK = restB * restB;
		Zeilen.push_back(z); // Zeile zum Vector hinzufügen
	}
	Zeilen.back()._gesK = 0; // Kosten der letzten Zeile auf 0 setzten
	return Zeilen;
}

void ausgabe(const vector<string> &text, const vector<Zeile> &zeilen, bool k) {
	long gesK { 0 };

	for (size_t i { 0 }; i < zeilen.size(); i++) {
		// Ausgabe mit Kosten, wenn -z gesetzt
		if (k) {
			cout << format(zeilen[i]._gesK, 4) << " ";
		}

		size_t zEnd { 0 };
		if (i + 1 >= zeilen.size()) {
			zEnd = text.size();
		} else {
			zEnd = zeilen[i + 1]._pos;
		}

		for (size_t w = zeilen[i]._pos; w < zEnd; w++) {
			cout << text[w] << " ";
		}
		cout << endl;
		gesK += zeilen[i]._gesK;
	}
	cout << "Zeilen: " << zeilen.size() << ", Kosten: " << gesK << endl;
}

void startpruefung(const vector<string> &text, int B) {
	if (text.empty()) {
		throw runtime_error("Textdatei ist leer");
	}
	if (B <= 0) {
		throw runtime_error("Spaltenbreite muss größer 0 sein");
	}

}

