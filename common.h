#ifndef COMMON_H_
#define COMMON_H_
#include <vector>
#include <string>
#include "pbma.h"

struct Zeile {
	int _pos { 0 };
	int _gesB { 0 };  // Gesamtbreite einer Zeile
	int _leerB { 0 }; // Summe aller Leerzeichen
	int _wortB { 0 }; // Gesamtbreite aller Wörter
	long _gesK { 0 }; // Kosten einer Zeile
};

std::vector<Zeile> fillZeilen(const std::vector<std::string> &text, int B);

void ausgabe(const std::vector<std::string> &text,
		const std::vector<Zeile> &zeilen, bool k);

void startpruefung(const std::vector<std::string> &text, int B);

#endif /* COMMON_H_ */
/*
 *
 *
 *
 *
 *
 *
 *
 */
