#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <grammar.h>

int main( int argc, char *argv[] )  {

	char str[100];

	/*
	printf( "Bonjour, tout le monde! \n" );
	printf( "Veuillez entrer votre phrase, s'il vous plaît. \n" );

	fgets( str, 100, stdin );
	printf( "Vous avez muni: \n" );
	printf( "%s \n", str );
	*/

	Phrase test;

	strcpy(str, "je vois le chien");
	
	int i;		//For the length of the phrase itself
	int j = 0;	//For the number of the current letter in the current word
	int k = 0;	//For the number of the current word in the phrase
	char temp;	//Current char examined

	Lexeme *lexemes = malloc(20 * sizeof(Lexeme)); //Allocating dynamic array of 20 Lexeme-s

	for (i = 0; i < strlen(str); i++){
			temp = str[i];
			if (temp != ' ') {
				lexemes[k].word[j] = temp;
				j++;
			} else {
				//printf("%s\n", lexemes[k].word);
				j = 0;
				k++;
			}
		}

	for (i = 0; i <= k; i++) {
		printf("%s\n", lexemes[i].word);
	}
	free(lexemes);

	/*
	strcpy(test.sujet.nom, "je");
	strcpy(test.verbal, "vois");
	strcpy(test.objet.determ.det, "le");
	strcpy(test.objet.nom, "chien");

	printStruct(test);
	*/

	return 0;
}