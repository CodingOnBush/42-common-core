# C++ Module 02
## Table of Contents
- [Ex00](#ex00)
- [Ex01](#ex01)
- [Ex02](#ex02)

### Introduction
	 <=> surcharge de fonctions\
**Definition** : Une fonction est dite surchargée si elle a plusieurs définitions, mais avec des paramètres différents.
```
void	foo(int a)
{
	cout << "int" << endl;
}

void	foo(float a)
{
	cout << "float" << endl;
}

void	foo(double a) 
{
	cout << "double" << endl;
}
```


Trois facon d'ecrire une operation arithmetique simple :
```bash
#Notation infix
1 + 1

#Notation prefix (fonctionnelle)
+ 1 1
+(1, 1)

#Notation postfix
1 1 +
```

### La forme canonique de Coplien
À partir de maintenant, vos classes devront impérativement se conformer à la forme
canonique de Coplien, sauf en cas d’indication contraire. Cela signifie qu’elles devront
comporter les quatre fonctions membres suivantes :
- Constructeur par défaut
- Constructeur de recopie
- Opérateur d’affectation
- Destructeur

**Voici une sorte de template avec cette class Sample :**
```cpp
#ifndef SAMPLE_HPP
# define SAMPLE_HPP

#include <iostream>

class Sample {

public:
	Sample(void);							// ✅ Constructeur par défaut 
	Sample(const int n);					// 🆗 Bonne pratique ce constructeur
	Sample(const Sample &obj);				// ✅ Constructeur de recopie
	Sample	&operator=(const Sample &obj);	// ✅ Opérateur d’affectation
	~Sample(void);							// ✅ Destructeur

	const int	getFoo(void);				// 🆗 Bonne pratique cet accesseur

private:
	int	foo_;								// 🆗 Bonne pratique le _

};

// 🆗 Bonne pratique
std::operator	&operator<<(std::ostream &o, const Sample &i);

#endif
```
**Maintenant voyons voir le code de ces fonctions :**
```cpp
#include "Sample.hpp"

Sample::Sample(void) : foo_(0) {
	std::cout << "Constructor called" << std::endl;
	return ;
}

Sample::Sample(const int n) : foo_(n) {
	std::cout << "Parametric constructor called" << std::endl;
	return ;
}

Sample::Sample(const Sample &obj) {
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
	return ;
}

Sample	&Sample::operator=(const Sample &obj) {
	std::cout << "Assignation operator called" << std::endl;
	this->foo_ = obj.getFoo();
	return (*this);
}

Sample::~Sample(void) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

const int	Sample::getFoo(void) {
	return (this->foo_);
}

std::operator	&operator<<(std::ostream &o, const Sample &i) {
	o << i.getFoo();
	return (o);
}
```
**Et voici un exemple d'utilisation de cette classe :**
```cpp
#include "Sample.hpp"

int		main(void) {
	Sample	instance1;
	Sample	instance2(42);
	Sample	instance3(instance1);

	std::cout << "instance1 : " << instance1 << std::endl;
	std::cout << "instance2 : " << instance2 << std::endl;
	std::cout << "instance3 : " << instance3 << std::endl;

	instance3 = instance2;
	std::cout << "instance3 : " << instance3 << std::endl;
	return (0);
}
```

### Ex00
les entiers	-> des briques\
les floats	-> de la pâte à modeler\
Facile de faire une sphère avec de la pâte à modeler, mais pas avec des briques.\
Facile de faire un cube parfait avec des briques, mais pas avec de la pâte à modeler (les coins notamment, seront difficile à faire).\

Les nombres à virgule flottante <=> Les flottants\

Les nombres à virgule flottante (ou flottants) sont une manière de représenter des nombres réels en informatique.\

Dans la vie réelle, 1 / 3 = 0.333333333333[...]∞\
Le resultat de 1 / 3 est un nombre à virgule floatante.\
Aucune représentation décimale finie (par exemple 0,333333) ne peut être égale à 1/3 ; il n'y a jamais assez de 3.\

Mettre un const a la fin d'une fonction permet de dire que la fonction ne modifie pas l'objet.\
En C++, la position du mot-clé const dans une déclaration de fonction a une signification importante. Lorsqu'il est placé à la fin de la déclaration de fonction, comme dans l'exemple que vous avez donné, cela signifie que la fonction ne modifie pas l'état de l'objet sur lequel elle est appelée.\

Dans le cas de la fonction getRawBits que vous avez montrée, le fait de placer const à la fin signifie que cette fonction est une fonction constante. Cela indique que la fonction ne modifie pas les membres de l'objet sur lequel elle est appelée. En d'autres termes, elle ne modifie pas l'état interne de l'objet.\

L'utilisation du mot-clé const à la fin d'une déclaration de fonction est une bonne pratique de programmation, car cela permet de spécifier clairement l'intention de ne pas modifier l'objet. Cela peut également aider le compilateur à détecter les erreurs si vous essayez de modifier l'objet à l'intérieur de la fonction.\
```cpp
int		getRawBits(void) const;
```
Si on met le const autre part :
```cpp
const int	getRawBits(void);
// or
int const	getRawBits(void);
```
Cela signifie que la valeur de retour de la fonction est constante. Cela signifie que la valeur retournée par la fonction ne peut pas être modifiée.\

### Comprendre les bits
Un bit c'est comme un interrupteur qui peut être soit allumé (1) soit éteint (0).\
Si on a un seul interrupteur, on peut avoir 0 ou 1.\
Quand j'ecris le nombre 2042, j'utilise une base 10 dans laquelle je peux piocher des chiffres dans {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}.\
Quand je fonctionne avec des interrupteurs, je suis en base 2 c'est comme si je ne pouvais piocher que dans {0, 1}.\

0 en base 10 = 0 en base 2\
1 en base 10 = 1 en base 2\
Pour pouvoir représenter 2,3,4,5 et plus, qui sont des nombres en base 10, il faut que j'utilise plusieurs interrupteurs.\

Si je veux représenter 42 en base 10, je vais devoir utiliser plusieurs interrupteurs :
```bash
101010
```
101010 c'est un nombre en base 2 tout comme 1999 est un nombre en base 10.\

Pour passe d'un nombre en base 10 à un nombre en base 2, et inversement, il y a plusieurs méthodes.\
*Je t'invite à chercher par toi même comment convertir un nombre d'une base vers une autre.*\

42 en base 10 = 101010 en base 2
```bash
101010 -> 2^5 * 1 + 2^4 * 0 + 2^3 * 1 + 2^2 * 0 + 2^1 * 1 + 2^0 * 0
101010 -> 32 + 0 + 8 + 0 + 2 + 0
101010 -> 42
# Voici comment on converti un nombre en base 2 en base 10
```
Quand j'ecris 101010, c'est comme si j'avais utilisé 6 interrupteurs pour représenter le nombre 42 (qui lui est en base 10).\
Si je veux, je peux utiliser 8 interrupteurs pour représenter un nombre. J'ai juste à rajouter des interrupteurs derrrière.\
```bash
001010101 -> 2^7 * 0 + 2^6 * 0 + 2^5 * 1 + 2^4 * 0 + 2^3 * 1 + 2^2 * 0 + 2^1 * 1 + 2^0 * 1
001010101 -> 0 + 0 + 32 + 0 + 8 + 0 + 2 + 1
001010101 -> 42
```
Si je rajoute des interrupteurs à gauche, je vais augmenter la valeur du nombre parce que les puissances de 2 vont augmenter.\
Si je rajoute des interrupteurs à droite, je vais augmenter la précision du nombre.\
```bash
01010101 -> 2^7 * 0 + 2^6 * 0 + 2^5 * 1 + 2^4 * 0 + 2^3 * 1 + 2^2 * 0 + 2^1 * 1 + 2^0 * 1
01010101 -> 0 + 0 + 32 + 0 + 8 + 0 + 2 + 1
01010101 -> 43

01101010 -> 2^7 * 0 + 2^6 * 1 + 2^5 * 1 + 2^4 * 0 + 2^3 * 1 + 2^2 * 0 + 2^1 * 1 + 2^0 * 0
01101010 -> 0 + 64 + 32 + 0 + 8 + 0 + 2 + 0
01101010 -> 106
```
En mettant des interrupteurs à gauche, j'ai augmenté la valeur du nombre.\
En mettant des interrupteurs à droite, j'ai augmenté la précision du nombre. Dans cette exemple, je suis passé de 42 à 43 mais si j'avais un nombre a virgule, j'aurais pu avoir plus de précision.\

**Mais comment représenter un nombre a virgule en binaire ?**\
Si je veux représenter 42.75 en binaire, je vais devoir utiliser des interrupteurs pour la partie entière et des interrupteurs pour la partie décimale.\
```bash
101010.11

101010 -> 42
11 -> 0.75
```

Bizarement, 11 en base 2 = 3 en base 10 et non pas 0.75.\
On a utilisé des puissance négatives de 2 pour représenter la partie décimale, celle qui vient après la virgule.
```bash
11 -> 2^(-1) * 1 + 2^(-2) * 1
11 -> 0.5 + 0.25
11 -> 0.75
```

Comment savoir si on peut utilise 1, 5, 8 ou 1000 interrupteurs pour représenter un nombre ?\
En informatique, on utilise des types de données pour définir combien d'interrupteurs on va utiliser.\
```cpp
int		n; // 4 octets
float	f; // 4 octets
double	d; // 8 octets
```
Un octet c'est 8 bits et donc 8 interrupteurs.\
Dans un int, on a 32 interrupteurs\
[░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░]\
En ecrivant 42 dans un int (`int n = 42;`), c'est comme si je devais chercher 32 interrupteurs pour représenter la creation de ce int et je vais allumer les interrupteurs 0, 1, 3, 5 :\
[░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][░][█][░][█][░][█][░]\
Ce que j'aime bien avec cette representation, c'est qu'on se rend compte que pour stocker 42, on a utilisé enormement d'interrupteurs alors qu'on aurait pu en utiliser beaucoup moins avec un autre type de données.\

Dans ce module, on va creer une classe qui va stocker un nombre a virgule flottante : Fixed.hpp\
Dans cette classe, on a beosin d'un entier pour stocker la valeur du nombre en virgule fixe.\
Ensuite, on va avoir besoin d'un entier constant statique pour stocker le nombre de bits de la partie
fractionnaire, et dont la valeur sera toujours le littéral entier 8.
```cpp
class Fixed
{
public:
	Fixed(void);
	Fixed(const Fixed &obj);
	Fixed(const int n);
	Fixed(const float f);
	~Fixed(void);
	Fixed	&operator=(const Fixed &obj);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private:
	int					value_;
	static const int	fractionalBits_ = 8;
};
```
Pour l'instant, pas besoin de faire attention à toutes les fonctions, on va juste s'interesser à la partie `value_` et `fractionalBits_`.\
`value_` est un entier qui va stocker la valeur du nombre en virgule fixe.\
`fractionalBits_` est un entier constant statique qui va stocker le nombre de bits de la partie fractionnaire.\
La partie fractionnaire est la partie du nombre qui vient après la virgule.\
Donc si on a 42.75, la partie fractionnaire est 0.75.\
On a besoin de 8 bits pour stocker la partie fractionnaire.\
```bash
101010.11
```
Dans cette exemple, on a besoin de 6 bits pour stocker la partie entière et 2 bits pour stocker la partie fractionnaire.\
Dans la classe Fixed, on a besoin de 8 bits pour stocker la partie fractionnaire :\
[░][░][░][░] [░][░][░][░]\
Pour 0.75, on va allumer les interrupteurs suivants :\
[█][█][░][░] [░][░][░][░]
```bash
1100 0000 -> 2^(-1) * 1 + 2^(-2) * 1 = 0.75
# la partie fractionnaire maximum qu'on peut atteindre avec 8 bits :
1111 1111 = 0.99609375
```

On va parler du constructeur Fixed(const float f) qui va nous permettre de convertir un float en virgule fixe.\
```cpp
Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->value_ = roundf(f * (1 << this->fractionalBits_));
}
```
Pour convertir un float en virgule fixe, on va multiplier le float par 2^8 (1 << 8) pour avoir la partie fractionnaire.\
Si je prends 42.75, je vais multiplier 42.75 par 256 (2^8) pour avoir 42.75 en virgule fixe.\
```bash
42.75 * 256 = 10944
```
10944 c'est 42.75 en virgule fixe.\
La partie entière est 42 et la partie fractionnaire est 0.75.\
En binaire, 42 c'est 101010 et pour convertir 0.75 en binaire, on va multiplier 0.75 par 2^8.\
```bash
0.75 * 256 = 192
```
En binaire, 192 c'est 11000000.\
On a donc 101010.11000000 qui est 42.75 en virgule fixe.\
On combine la partie entière et la partie fractionnaire pour avoir le nombre en virgule fixe.\
```bash
101010.11000000 -> 42.75
```
Le nombre 42.75 en virgule fixe avec 8 bits pour la partie fractionnaire est représenté par le nombre binaire 0010101011000000.\
Pour vérifier que 42.75 en virgule fixe est bien 0010101011000000, on peut convertir 0010101011000000 en base 10.\
```bash
00101010 -> 42
11000000 -> 192 en base 10 et donc 192 / 2^8 = 0.75
```

### incrémentation et décrémentation

**Pré-incrémentation (++variable)**\
L’opérateur de pré-incrémentation augmente la valeur de la variable avant que l’expression ne soit évaluée.
```cpp
float epsilon = 0.000001f; // ε très petit
float valeur = 1.0f;
++valeur; // valeur devient 1.000001
```

**Post-incrémentation (variable++)**\
L’opérateur de post-incrémentation augmente la valeur de la variable après que l’expression ne soit évaluée.
```cpp
float epsilon = 0.000001f; // ε très petit
float valeur = 1.0f;
valeur++; // valeur reste 1.0 pour l'évaluation, puis devient 1.000001
```

**Pré-décrémentation (--variable)**\
L’opérateur de pré-décrémentation diminue la valeur de la variable avant que l’expression ne soit évaluée.
```cpp
float epsilon = 0.000001f; // ε très petit
float valeur = 1.0f;
--valeur; // valeur devient 0.999999
```

**Post-décrémentation (variable--)**\
L’opérateur de post-décrémentation diminue la valeur de la variable après que l’expression ne soit évaluée.
```cpp
float epsilon = 0.000001f; // ε très petit
float valeur = 1.0f;
valeur--; // valeur reste 1.0 pour l'évaluation, puis devient 0.999999
```

Quand je lis ceci dans le sujet, je suis un peu perdu :\
**"Les 4 opérateurs d’incrémentation et de décrémentation (pré-incrémentation et post-incrémentation, pré-décrémentation et post-décrémentation) qui diminueront
la valeur du nombre à virgule fixe d’unité ε tel que 1 + ε > 1. "**\

Dans ce contexte, ε (epsilon) représente le plus petit incrément possible pour le type de nombre à virgule fixe en question. C'est la plus petite quantité par laquelle on peut augmenter ou diminuer la valeur de ce nombre, telle que 1 + ε > 1. Cela garantit que ε est suffisamment petit pour être le plus petit changement perceptible dans la valeur du nombre.

Pour trouver ε, on peut utiliser la formule suivante :\
```bash
ε = 1 / (2^fractionalBits_)
```
Dans le cas de la classe Fixed, on a besoin de 8 bits pour stocker la partie fractionnaire.\
```bash
ε = 1 / (2^8) = 1 / 256 = 0.00390625
```
On n'a pas besoin de faire de calculs pour trouver ε quand on va incrémenter ou décrémenter parce que notre fixedPoint est déjà en virgule fixe, ce qui signifie qu'en lui ajoutant ou en lui retirant 1, on va faire en sorte que lorsqu'on affichera le nombre, il sera affiché avec la bonne précision.\
```cpp
float	nb = 42.75f;
Fixed	val(nb);

std::cout << nb << std::endl; // affiche 42.75
nb++;
std::cout << nb << std::endl; // affiche 43.75

std::cout << val << std::endl; // affiche 42.75
val++;
std::cout << val << std::endl; // affiche 42.7539
```
Dans notre l'instance de Fixed (val), le fixedPoint est un int qui sera egal à 42.75 * 256 = 10944.\
Si on essaye de faire un getRawBits sur val, on va avoir 10944.\
Si on veut afficher val, on va devoir diviser 10944 par 256 pour avoir 42.75.\
Si on incrémente val, on va ajouter 1 à 10944 et on va avoir 10945.\
Si on veut afficher val après l'avoir incrémenté, on va devoir diviser 10945 par 256 pour avoir 42.7539.\