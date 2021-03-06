# French_Compiler

There are claims that the 75 most common words in a language make up 40% of occurrences in said language; the 200 most common make up 50%, 524 make up 60%, etc. ("5 Steps to Speak a New Language", Hung Quang Pham).

Using general compiler principles, my goal is to verify an input French sentence as grammatically correct or not, and build a syntax tree around it. 
I wish to test the above claims as for whether or not the compiler is capable of a hit rate (produce correct syntax trees) in said percentage range given the corresponding number of words as learning set. 
This requires the compiler being able to go through the following phases:

1. Lexical Analysis
	- Verifies whether or not lexemes are valid French words, and identifies their class.
	- Outputs token stream.

2. Syntax Analysis
	- Verifies whether or not lexemes form grammatically valid French sentence; i.e. correct word order.
	- Outputs syntax tree.

3. Semantic Analysis
	- Verifies whether or not the grammatically correct sentence actually makes sense*.
	- Outputs syntax tree.

*This is an AI issue, and probably not one I will take on.

Giving tokens attributes depending on their class, it should be possible to verify them as grammatically correct.
Consider the example *la petite maison est belle*. The phrase needs an attribute indicating that it's subject is a feminine noun in third person singular, deciding that the verb in the predicate should be conjugated in the corresponding person, and that the adjective should be singular and feminine, as well as the subject complement (*attribut du sujet*), giving something along the lines of 

```
phrase.sujet.GN.noun.gender = feminine;
phrase.sujet.GN.noun.number = singular;
phrase.sujet.GA.adj.gender = phrase.sujet.GN.noun.gender;
phrase.sujet.GA.adj.number = phrase.sujet.GN.noun.number;

/* ... */

phrase.predicat.AS.adj.gender = phrase.sujet.GN.noun.gender;
phrase.predicat.AS.adj.number = phrase.sujet.GN.noun.number;

```

This could possibly be implemented using Markov Chains and Viterbi. I'm still planning this stage.

## Issues I'm aware of

- #### Language is immensely large. 
Absolutely. I don't have the capacity to store a Big Data DB, and will so probably only use a handful of words from every class and build syntax trees around these. If the principle works, it is theoretically possible to feed the program arbitrary sentences and from here, it should be able to "learn" new words and put them in their correct classes. 

If, e.g., the compiler does not know the word *ptérodactyle*, but it occurs in a syntactic setting that it knows, like *j'aime les ptérodactyles*, it should be able to determine that the unknown lexeme is in fact a noun based on the fact that it fits the grammatical rule GN (subject) + GV (Verb) + GN (Direct object) (or any other class combination. Infinitive verbs would also be valid here (*j'aime lire*), for example, so we would have to keep some kind of record on potential classes) - but this is a feature I will consider implementing when the compiler itself is functional.

- #### Language doesn't always conform to the given rules.
AI and immense data sets is the best way to teach a machine languages. However, some basis must be formed from somewhere. This is largely a personal research project that arose as a realization that both linguistics and compiler technologies use lexical, syntax, and semantic analysis to form syntax trees. The parallel was too exciting not too explore. It might turn out that this is fatuous, but if nothing else, it serves as a practice project for my later thesis, or whatever.

- #### Ambiguity is an issue both in programming language compilers as well as human languages
Does "I am watching the elephant with binoculars" mean that you are watching an elephant by the means of using binoculars, or are you watching an elephant wearing binoculars? Context usually decides this problem, but as for a compiler, the solution lies in deciding on one interpretation as preferred.

Certain words also have double meanings, like *Cet homme est fier; peut-on s'y fier?*. However, this boils down to pattern matching, and Markv chains could determine that the first instance of *fier* is far more likely to be an adjective, whereas the second ought to be a verb.