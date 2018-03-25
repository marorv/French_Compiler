#include <stdio.h>
#include <string.h>
#include <grammar.h>

int main( int argc, char *argv[] )  {
   /* my first program in C */
   //printf( "Bonjour, tout le monde! \n" );
   //printf( "Veuillez entrer votre phrase, s'il vous plaît. \n" );

   char str[100];

   //fgets( str, 100, stdin );

   printf( "Vous avez muni: \n" );
   puts( str );

   //Je vois le chien
   Phrase test;

   strcpy(test.sujet.nom, "je");
   strcpy(test.verbal, "vois");
   strcpy(test.objet.determ.det, "le");
   strcpy(test.objet.nom, "chien");
   

   printStruct(test);

   return 0;
}