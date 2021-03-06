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

	strcpy(str, "le chat voit les chiens");
	
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
				j = 0;
				k++;
			}
		}


	//Extract entry nr entry from the CSV line s
	char* extrEntryFrmCSV(char *s, int entry){ 
		int i = 0;				// Current char in the CSVline
		int j = 0;				// current char in the current entry
		char *word = malloc (sizeof (char) * 20); //This isn't freed up anywhere?
		char temp;
			
		for (i = 0; i < strlen(s); i++) {
			temp = s[i];
			if (entry == 0){
				if (temp != ',' && temp != ' ') {
					word[j] = temp;
					j++;
				} if (temp == ',') {
					return word;
				}
			} else {
				if (temp == ','){
					entry--;
				}
			}
		}
		free(word); //If function returns in line 56, this is unreachable, so word never freed?
	}

	//Compare lexeme with database entries, return 0 if match found in DB, -1 elsewise
	int cmprLxmWthDB(char *lex){ 
		char filename[50] = "grammar_classes/nouns.csv"; 
		char comp_word[20]; 
		strcpy(comp_word, lex);

		FILE* stream = fopen(filename, "r");
		if (stream){
			char line[1024];

			while (fgets(line, 1024, stream))
		 	{
				char* tmp = strdup(line);
				char* sg = extrEntryFrmCSV(tmp, 0);
				char* pl = extrEntryFrmCSV(tmp, 1);
				// strcmp return values: <0 = first unmatching character has lower value in ptr1 than ptr2, 0 = contents equal
				//column 0 is singular, column 1 is plural
				if (strcmp(comp_word, sg) == 0 || strcmp(comp_word, pl) == 0) { 
					free(tmp);
					free(sg);
					free(pl);
					return 0;
				}
				free(tmp);
			}
		} else
		{
			printf("%s\n", "Could not open file.");
		}
		fclose(stream);
		return -1;
	}

	void classifyLexemes (Lexeme *phrase, int size) {
		for (i = 0; i <= size; i++){
			//Ugly hard coding, but just testing

			printf(" ");
			if (cmprLxmWthDB(phrase[i].word) == 0) { 
				strcpy(phrase[i].word_class, "noun");
			}

			printf("%s (%s)\n", phrase[i].word, phrase[i].word_class);
		}
	}

	classifyLexemes(lexemes, k);
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