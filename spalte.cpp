#include "common.h"
#include "pbma.h"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
	args_t cliparam(argc, argv);
	if (cliparam.len_pos() < 1) {
		cout << "Kein Dateiname angegeben!" << endl;
		return 1;
	}

	const vector<string> text = read_words(cliparam.pos(0));
	int B = cliparam.int_option("w", 40);

	startpruefung(text, B);

	const vector<Zeile> zeilen = fillZeilen(text, B);

	ausgabe(text, zeilen, cliparam.flag("z"));

	return 0;
}

/*
 *
 *
 *
 *
 *
 *
 *
 */
