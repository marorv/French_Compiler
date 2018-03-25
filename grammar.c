#include <stdio.h>
#include <grammar.h>

void printPhrase(Phrase inpPhr){
	printf("%s %s %s %s \n", inpPhr.sujet.nom, inpPhr.verbal, inpPhr.objet.determ.det, inpPhr.objet.nom);
}

void printStruct(Phrase inpPhr){
	printf("%s\n", "Phrase");
	printf("%s \t %s \n", "Sujet", "Prédicat");
	printf("%s \t %s \t %s \n", "GN", "GV", "GN");
	printf("%s \t %s \t %s \t %s \n", "N", "V", "D", "N");
	printf("%s \t %s \t %s \t %s \n", inpPhr.sujet.nom, inpPhr.verbal, inpPhr.objet.determ.det, inpPhr.objet.nom);
}