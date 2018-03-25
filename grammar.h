#ifndef HEADER_H
#define HEADER_H

typedef struct D D;
typedef struct GN GN;
typedef struct Phrase Phrase;

//Determinants
struct D { 
	char det[50];
};

//Groupe Nominale
struct GN { 
	D determ;
	char nom[50];
};

struct Phrase { //defining identifier "struct Phrase" within struct name space
	char structure[50];
   	GN sujet;
   	char verbal[50];
   	GN objet;
}; //add type alias in global name space, allowing Phrase p, not struct Phrase p

void printPhrase(Phrase inpPhr);
void printStruct(Phrase inpPhr);

#endif