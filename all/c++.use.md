
-----------------------------------------------------------
- Premier programme
-----------------------------------------------------------
```
class POINT
{
	public :
		int dim;
		double x,y,z;
		void print()
		{cout<<”coordonnees : ”<<x<<” ”<<y<<” ”<<z;}
		POINT(int d); // declaration du constructeur
	private :
		double *pCor;
};
POINT::POINT(int d) //implementation externe du constructeur
{
	dim = d;
	pCor = new double[dim]; //allocation
	for(int i=0;i<dim;i++) pCor[i] = 0;
}
int main()
{
	POINT P; //instanciation d'un objet POINT
	P.dim = 3;
	P.x = 0; P.y=0; P.z=0;
	P.print();
	POINT *pQ = &P; //pointeur sur le POINT P
	pQ->x=1.;
	POINT *pQ = new POINT(3); // pointeur sur un POINT
}
```


reference
---
[Core
guidelines](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#a-namerc-orgac1-organize-related-data-into-structures-structs-or-classes)

check memoyleaks
---
[valgring](http://valgrind.org/docs/manual/mc-manual.html)

headers
---
http://www.cplusplus.com/articles/Gw6AC542/


Transtypage :
const_cast;dynamic_cast;reinterpret_cast;static_cast

return *this;			#retrourne autoreference

retourner une reference : permet de modifier
for(int i=1;i<=10;i++) element(i)=1;
avec la fonction : double & function element(const int & i);{return vec[i];}


double fonc(double x, int der=0, double par=0){...}	#valeur par defaut

inline double carre(double y){return y*y;}			#Macro en C



variable
--------
int var(value)				déclaration
++var					pré-incrémentation(l'expression = var; a la diff de var++ qui vaut = var+1;)
const					constante

flux
----
<iostream>				#include
cout << var << endl			sortie + retour à la ligne
cin >> var				entré
cin.ignore(); getline(cin,var);		"vidé buffer" + lire ligne avec espace

reference
--------
-- https://www.quora.com/Are-references-in-C++-stored-in-memory-like-pointers-or-not/answer/Lance-Diduck
<cite>
	A reference is another name for the same variable. For example, "Charlie Brown" is also called "Chuck" -- a reference is just another name for the same object.
	The "last person in the lunch line" is a pointer, and can change or point to nothing.
	Another analogy is from UNIX file system: a reference is a hard link, a pointer is a soft link.
	How they are stored is not specified, but a pointer you can pretty much rely on having storage 
</cite>
les reference sont une étique qui pointe sur la meme case mémoir, mais non pas besoin d'être déreférencée
Par defaut argument passage par copie;
int& ref(var) 				creer une reference sur var 
(int& var) 				force le passage par reférence 

fonction
------
[.h] (int var = default)		valeur par defaut
(int const& var)			passage par reference constante : aprote juste de l'information( comme la lecture d'un livre, pas de copie, pas de modif)
tableau attention passage par reference automatique

file
---
tellg/tellp				position (in/out en fct du stream)
seekg/seekp				deplacer (faire un clear() avant)
->ios::beg/end/cur			where
(string.c_str())			transform une string en tableau de char (utile pour la libC)

aleat
----
<ctime>,<cstdlib>,srand(time(0));	initilisation
rand()%x;				use

poiteur
-------
int *var(0)				initialiser un pointeur avec une address null
var = new int				alloue la taille d'un int
delete var				libere la mémoir alloue à var

class Objet{}; + Heritage
----
class ObjChild : public Obj{}		Heritage : ObjChild herite de Obj et est definie entre crochet, Note : public->par defaut l'heritage est private, ce aui rend inaccecible les declaration de la class parente.
private :				par defaut tout les attributs sont private
a noter que l'on peu acceder au attribut privé des autres objets si il sont de la classe en train d'être implémentée.
mais pas dans la classe mere 	->	en pratique on prefert déclarer les attributs en protected
struct					si au lieu d'une class on a une srtuc alors attribut public par defaut
Objet()					Constructeur vide
Objet(Objet const& autre);		Constructeur par copie
~Objet()				Destructeur
Objet::Objet() : att1(50) {}		Implémentation du constructeur avec une liste d'initialisation
void methode(int param) const;		const : methode qui ne modifie pas l'objet (ne change la valeur d'aucun attribut)
"Appel à super"				se fait dans la liste d'init pour les constructeur.
ObjMere::methode();			demasquage : apple la methode implémenté dans la class mere
Obj::methode();				de meme pour les methodes statiques
static void meth();			déclaration d'une methode statique

surcharge d'operateur
----------
bool operator==(Obj const& a, Obj const& b); opérateur binaire: Situer en dehors de la classe ou comme ami
friend bool op();			dans la class Obj : déclare une méthode "op" ami de "Obj"
return !(a==b);				Implément : operator!=()
Obj& operator+=(Obj const& a);		operateur raccourict implémenter dans la class (return *this;)
Obj copie(a);copie += b;return copie;	Implément operateur arithmetique depuis raccourcit
Obj& operator=(Obj const& aCopie)	vas de paire avec le constructeur par copie (si on réimplément l'un ,alors l'autre aussi)
iostream& operator<<(ostream& flux,Obj const& o) operateur de flux : prend est retourne une ref pour pemettre les chaines(cout << o1 << 02);
int operator()()			foncteur : redefinition l'operateur parenthé permet d'utilisé l'objet comme une fonction
prédicat				foncteur retournant un bool et prenant un seul parametre.

polymorphisme
--
virtual void meth();			déclare une méthode virtuel.
permet d'appeler la methode corespondant a la classe de notre objet
fonctionne par résolution dynamique de lien. 
dois etre utilisé sur un pointeur ou une reference.
Impossible de l'utiliser pour les constructeurs
Obligatoirement utiliser pour les destructeurs
Probleme des collections hétérogènes (construit par copie ?) :

class abstrait
--
au moins une methode virtuel pure
virtual void meth()=0;			methode virtuel pure

Standar Lib (il y en a 15 qui vienne du C)
---------
<cmath>					fct math
<cctype>				type des char
<ctime>					temps machine
<cstdlib>				nombre aleatoir
<cassert>				gestion des erreurs

STL
---
permet d'utiliser des conteneurs
<vector>				class vector est un conteneur
push_back();pop_back();			ajouter retirer un élément d'un conteneur
vector<int>::iterator it;		déclare un itérateur : les itérateur sont "une surcharge" des pointeurs
for(it = c.begin(); it!=d.end(); ++it)	foreach *it element in conteneur c
<fonctional>				foncteur de la STL
<algorithm>				modificateur de la STL
generate(c.begin(),c.end(),f);		remplie le conteneur c de begin() à end() grace au foncteur f 
count_if(c.begin(),c.end(),p);		compte si le prédicat est vrai
find();find_if();			recherche d'un element
for_each(c.begin(),c.end(),f);		applique le foncteur f au conteneur c de begin() à end()
transform();				permet de réaliser une opération de type a+b=c entre des conteneurs;
<iterator>				iterateur de la STL
Le type des iterator varie selon le conteneur auquel il est associé (5 types : bilateral, random acces, readOnly, writeOnly, ?)

page 566

[Standard library](https://en.cppreference.com/w/cpp/header)

Template - Généricité
-------------------
template<typename T>			indique que la méthode ou la class est générique via l'element T.
					dois etre implémenté dans le fichier Header
template<typename T,typename S>		on peux en avoir plusieurs 
template <> meth<Obj>			spécification : permet de définir la methode dans le cas ou on applique le template sur un Obj

compilation option
--------------
-L path to shared library
-I path to headers
-W, -Wall verbosity, warning (all)
-g add debug flags for gdb
-c     Compiler source(s) to object-code (input to linker). This option is better for incremental compilation when using multiple files.
[for more details](https://caiorss.github.io/C-Cpp-Notes/compiler-flags-options.html)

lambda function
-------------------
`[]{}`
where
    *[] lambda-introducer
    *{} instruction bloc of the funtion
It can also be seen as follow
```
[ capture clause ] (parameters) mutable sepcification -> return-type
{
   definition of method
}( call with parametes )
```
Syntax used for capturing variables :
      *[&] : capture all external variable by reference
      *[=] : capture all external variable by value
      *[a, &b] : capture a by value and b by reference
https://www.codeproject.com/Articles/71540/Explicating-the-new-C-standard-C-0x-and-its-implem#LambdaExpressions

callbacks
----------
A callback is a function that takes a *callable*(listed below) as parameter and call it at the genuine point
>One reason to use callbacks is to write generic code which is independant from the logic in the called function and can be reused with different callbacks.

    -Function pointers (including pointers to member functions)
        -`return_type (*[name])([parameters])` (`[]`:optional)
    -`std::function` objects
    -Lambda expressions
    -Bind expressions
    -Function objects (classes with overloaded function call operator operator())

>\* Note: Pointer to data members are callable as well but no function is called at all.

[more details](https://stackoverflow.com/questions/2298242/callback-functions-in-c)

