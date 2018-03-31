#ifndef HEADER_H
#define HEADER_H

typedef struct D D;
typedef struct GN GN;
typedef struct Phrase Phrase;
typedef struct Lexeme Lexeme;

void printPhrase(Phrase inpPhr);
void printStruct(Phrase inpPhr);

//Determinants
struct D { 
	char det[50];
};

//Groupe Nominale
struct GN { 
	D determ;
	char nom[50];
};

struct Phrase {
	char structure[50];
	GN sujet;
	char verbal[50];
	GN objet;
}; 

struct Lexeme { //This will be IR - determine type an them convert to structs of nouns, determinants, ...
	char word[50];
	char word_class[50];
};

#endif