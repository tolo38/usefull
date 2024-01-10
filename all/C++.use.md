
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

```
Transtypage :
const_cast;dynamic_cast;reinterpret_cast;static_cast

return *this;			#retrourne autoreference

retourner une reference : permet de modifier
for(int i=1;i<=10;i++) element(i)=1;
avec la fonction : double & function element(const int & i);{return vec[i];}


double fonc(double x, int der=0, double par=0){...}	#valeur par defaut

inline double carre(double y){return y*y;}			#Macro en C
```

Macro
---
* [Change methode behavior or by pass](https://www.geeksforgeeks.org/print-geeksforgeeks-empty-main-c/)
```
#include <iostream>
#include <string>

#define FOO // is not possible to replace with comment symbole (all comments are removed before preproc) 
#ifdef FOO
void fizz(){}
struct {
    void fizz(){}
}foo_;
decltype(foo_)* foo() { return &foo_; }
#endif // FOO

int main()
{
    const std::string HW = "Hello World!\n";
    std::cout << HW;
    fizz();
    foo()->fizz();
    foo_.fizz();
    foo();
}
```



variable
--------
- `int var(value)`				déclaration
- `++var`					pré-incrémentation(l'expression = var; a la diff de var++ qui vaut = var+1;)
- `const`					constante
- `constexpr`					 *stronger concept than constant*, promise to be initialized at compile-time

- **Global** Integral Constant Expression (ICE)
```cpp
inline extern const int GLOBAL_CONST_VAR = 0xFF;
```


flux
----
- `<iostream>`					#include
- `cout << var << endl`				sortie + retour à la ligne
- `cin >> var`					entré
- `cin.ignore(); getline(cin,var);`		"vidé buffer" + lire ligne avec espace

input
---
Use `getch()` (need `#include <conio.h>`).  
Use `getchar()` (expected for Enter, need `#include <iostream>`).  
Use `cin.get()` (expected for Enter, need `#include <iostream>`).  
Use `system("pause")` (need `#include <iostream>`, Windows only).  

Argument
---
```c++
int main(int argc, char * argv[]) {

  if (argv[1] == "yes"); // Wrong, compares two pointers
  if (strcmp(argv[1], "yes") == 0); // This compares what the pointers point to
  if (std::string(argv[1]) == "yes"); // Works fine
  if (argv[1] == std::string("yes")); // Works fine

  // Easy-mode    
  std::vector<std::string> args(argv, argv+argc);
  for (size_t i = 1; i < args.size(); ++i) {
      if (args[i] == "yes") {
          // do something
      }
  }

}
```

string
---
- `std::string s = "my text char*" + std::string(" can be concatenated using string constructor");` Concatenate
- `sprintf(Buffer,"Hello World");`		print formated string to a buffer 
- `Buffer + strlen(Buffer)`			to append at the end of current buffer (or at any index)
- `std::to_string(_int)`			to turn a `int` into a string
- `"%1d", _int`					int with 1 prepending `0`
- `"%.1e", _int`				scientific notation with 1 decimal precision
- `"%2s", _string`				string with 2 prepending spaces
```cpp
const char *text =
  "This text is pretty long, but will be "
  "concatenated into just a single string. "
  "The disadvantage is that you have to quote "
  "each part, and newlines must be literal as "
  "usual.";
  
const char *text2 =
  "Here, on the other hand, I've gone crazy \
and really let the literal span several lines, \
without bothering with quoting each line's \
content. This works, but you can't indent.";
```

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
- `int& ref(var) `				creer une reference sur var 
- `(int& var)`	 				force le passage par reférence 

lvalue - rvalue
---
```c++
void foo(int&& a)
{
    //Some magical code...
}

int main()
{
    int b;
    foo(b); //Error. An rValue reference cannot be pointed to a lValue.
    foo(5); //Compiles with no error.
    foo(b+3); //Compiles with no error.

    int&& c = b; //Error. An rValue reference cannot be pointed to a lValue.
    int&& d = 5; //Compiles with no error.
}
```
an lvalue is
>an expression that has identity and cannot be moved from. 

So, there's no such thing as an lvalue object, but there is an object which is locally named (or referred to) by an lvalue expression

an rvalue is
>an expression that is either a prvalue or an xvalue. It can be moved from. It may or may not have identity.
use `&&` to force function argument to be lvalue

a prvalue (pure rvalue) is
>roughly an expression referring to an un-named temporary object: we can't convert our lvalue expression to one of these IIUC.

an xvalue (expiring value) is
>an expression that has identity and can be moved from.

to set a rvalue where a lvalue is expected use [`std::move` ][std_move]
- `std::move` is also a way to get ownership of object, like a copy in place and getting ride of the old one.

[std_move]: https://stackoverflow.com/a/27026280/19624015

fonction
------
- `[.h] (int var = default)`			valeur par defaut
- `(int const& var)`				passage par reference constante : aprote juste de l'information( comme la lecture d'un livre, pas de copie, pas de modif)
- tableau attention passage par reference automatique
- Aliases : give an additional name to a function or variable with `static inline constexpr auto new_name = old_name`

#### Structured binding in C++17

return multiple values from a function using a local structure or tuple

```cpp
#include <iostream>
#include <tuple>

auto foo()
{
  return {128, 3.142, "Hello"};
}

int main()
{
  auto [value1, value2, value3] = foo();
  cout << value1 << ", " << value2 << ", " << value3 << endl;
}
```

file
---
- `tellg/tellp`				position (in/out en fct du stream)
- `seekg/seekp`				deplacer (faire un clear() avant)
- ->`ios::beg/end/cur`			where
- `(string.c_str())`			transform une string en tableau de char (utile pour la libC)

aleat
----
- `<ctime>,<cstdlib>,srand(time(0));`	initilisation
- `rand()%x;`				use

array
---
- `int tab[24]`				initialise an array of 24 int
- `int tab[] = {1, 2, 3, 4}`		initialise an array of  4 int ( implicitly)
- <cite>It is not possible to add elements into an array. An array has a constant number of elements through its lifetime</cite>
   - Therefore you need pointers
- Index vs Pointer : 
> indexes are more robust, because they often survive array reallocation. 

ex : a dynamic array where element are added at the end
> it can take half the space with 32-bit indices instead of 64-bit address (value stored in pointer) (assuming you don't need more than ~4.3 billion elements).
	
[namespace]
---
Is the best way to organise and split the code into private chunk  
use anonyme namespace to hide variable to the outside
	
pointeur
-------
- `int *var(0)`				initialiser un pointeur avec une address null
- `var = new int`			alloue la taille d'un int
- `delete var`				libere la mémoir alloue à var

##### [Smart Pointer][smart_pointer]
>Advantages
>
>`make_unique` teaches users "never say new/delete and new[]/delete[]" without disclaimers.
>
>make_unique shares two advantages with `make_shared` (excluding the third advantage, increased efficiency). First, unique_ptr<LongTypeName> up(new LongTypeName(args)) must mention LongTypeName twice, while auto up = make_unique<LongTypeName>(args) mentions it once.
>
>make_unique prevents the unspecified-evaluation-order leak triggered by expressions like foo(unique_ptr<X>(new X), unique_ptr<Y>(new Y)). (Following the advice "never say new" is simpler than "never say new, unless you immediately give it to a named unique_ptr".)
>
>make_unique is carefully implemented for exception safety and is recommended over directly calling `unique_ptr` constructors.
>
>When not to use make_unique
>
>Don't use make_unique if you need a custom deleter or are adopting a raw pointer from elsewhere.
	
[smart_pointer]: https://stackoverflow.com/a/37514601/19624015

malloc
---

>The more interesting part is how free works (and in this direction, malloc too can be understood better).
>
>In many malloc/free implementations, free does normally not return the memory to the operating system (or at least only in rare cases). The reason is that you will get gaps in your heap and thus it can happen, that you just finish off your 2 or 4 GB of virtual memory with gaps. This should be avoided, since as soon as the virtual memory is finished, you will be in really big trouble. The other reason is, that the OS can only handle memory chunks that are of a specific size and alignment. To be specific: Normally the OS can only handle blocks that the virtual memory manager can handle (most often multiples of 512 bytes e.g. 4KB).
>
>So returning 40 Bytes to the OS will just not work. So what does free do?
>
>Free will put the memory block in its own free block list. Normally it also tries to meld together adjacent blocks in the address space. The free block list is just a circular list of memory chunks which have some administrative data in the beginning. This is also the reason why managing very small memory elements with the standard malloc/free is not efficient. Every memory chunk needs additional data and with smaller sizes more fragmentation happens.
>
>The free-list is also the first place that malloc looks at when a new chunk of memory is needed. It is scanned before it calls for new memory from the OS. When a chunk is found that is bigger than the needed memory, it is divided into two parts. One is returned to caller, the other is put back into the free list.
>
>There are many different optimizations to this standard behaviour (for example for small chunks of memory). But since malloc and free must be so universal, the standard behaviour is always the fallback when alternatives are not usable. There are also optimizations in handling the free-list — for example storing the chunks in lists sorted by sizes. But all optimizations also have their own limitations.
	
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
```c++
bool operator==(Obj const& a, Obj const& b); opérateur binaire: Situer en dehors de la classe ou comme ami
friend bool op();			dans la class Obj : déclare une méthode "op" ami de "Obj"
return !(a==b);				Implément : operator!=()
Obj& operator+=(Obj const& a);		operateur raccourict implémenter dans la class (return *this;)
Obj copie(a);copie += b;return copie;	Implément operateur arithmetique depuis raccourcit
Obj& operator=(Obj const& aCopie)	vas de paire avec le constructeur par copie (si on réimplément l'un ,alors l'autre aussi)
iostream& operator<<(ostream& flux,Obj const& o) operateur de flux : prend est retourne une ref pour pemettre les chaines(cout << o1 << 02);
int operator()()			foncteur : redefinition l'operateur parenthé permet d'utilisé l'objet comme une fonction
prédicat				foncteur retournant un bool et prenant un seul parametre.
```
	
polymorphisme
---
```c++	
virtual void meth();			déclare une méthode virtuel.
permet d'appeler la methode corespondant a la classe de notre objet
fonctionne par résolution dynamique de lien. 
dois etre utilisé sur un pointeur ou une reference.
Impossible de l'utiliser pour les constructeurs
Obligatoirement utiliser pour les destructeurs
Probleme des collections hétérogènes (construit par copie ?) :
```
	
class abstrait
---
```
au moins une methode virtuel pure
virtual void meth()=0;			methode virtuel pure
```
	
Standar Lib (il y en a 15 qui vienne du C)
---------
|Lib|Details|
|-|-|
|`<cmath>`				|fct math
|`<cctype>`				|type des char
|`<ctime>`				|temps machine
|`<cstdlib>`				|nombre aleatoir
|`<cassert>`				|gestion des erreurs

STL
---
```C++
permet d'utiliser des conteneurs
<vector>				class vector est un conteneur
push_back();pop_back();			ajouter retirer un élément d'un conteneur
vector<int>::iterator it;		déclare un itérateur : les itérateur sont "une surcharge" des pointeurs
for(it = c.begin(); it!=d.end(); ++it)	foreach *it element in conteneur c
for (const auto& [key, value] : myMap){	//C++17- foreach
<fonctional>				foncteur de la STL
<algorithm>				modificateur de la STL
generate(c.begin(),c.end(),f);		remplie le conteneur c de begin() à end() grace au foncteur f 
count_if(c.begin(),c.end(),p);		compte si le prédicat est vrai
find();find_if();			recherche d'un element
for_each(c.begin(),c.end(),f);		applique le foncteur f au conteneur c de begin() à end()
transform();				permet de réaliser une opération de type a+b=c entre des conteneurs;
<iterator>				iterateur de la STL
Le type des iterator varie selon le conteneur auquel il est associé (5 types : bilateral, random acces, readOnly, writeOnly, ?)
```
page 566

[Standard library](https://en.cppreference.com/w/cpp/header)

Exception
---
```c++
// exception::what
#include <iostream>       // std::cout
#include <exception>      // std::exception

struct ooops : std::exception {
  const char* what() const noexcept {return "Ooops!\n";}
};

int main () {
  try {
      throw ooops();
  } catch (std::exception& ex) {
      std::cout << ex.what();
  }
  return 0;
}
```
Catch all exception with `...`
```c++
try{
    // ...
} catch (...) {
    // ...
}
```

Compilation option
--------------
```sh
gcc -lsvl -L/my/path/ # exemple to add svl library ... remember that each lib has it own command option
```
- -L path to shared library
- -I path to headers
- -W, -Wall verbosity, warning (all)
- -g add debug flags for gdb
- -c     Compiler source(s) to object-code (input to linker). This option is better for incremental compilation when using multiple files.

[for more details](https://caiorss.github.io/C-Cpp-Notes/compiler-flags-options.html)
- or use [camke](cmake.use.md)

##### [Conan]
add a conanfile.py at root : 
```py
from conans import ConanFile, CMake, tools

class PackageConan(ConanFile):
    name = ""
    version = "0.0.1"
    license = "Proprietary"
    author = "tolo"
    description = "...project"

    settings = "os", "compiler", "build_type", "arch"
    # maybe switch in the future to "CMakeDeps"
    # the cmake generator is necessary to generate a variable map that is used to find NSIS exe
    generators = ["cmake_find_package", "cmake"]

    requires = [
        "gtk/4.0.2"
    ]

    def build_requirements(self):
        if self.settings.os == "Windows":
            self.build_requires("NSIS/3.08@z43/stable")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def imports(self):
        self.copy("*.dll", "", "bin")
        self.copy("*.so*", "", "lib")
```

- find lib(to add in requires) with : `conan search gtk -r=all`

- run `CMake:Configure` (ctrl+shift+p in VScode)

- then inside `build` folder there is `Find<lib>.cmake` file, search for `add_library()` so that to add the right dependecy in `CMakeLists.txt`->`target_link_libraries()` (in the subdirectory)
- needs also `find_package(gtk REQUIRED)` (in root `CMakeLists.txt`)


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
    -Functor : Function objects (classes with overloaded function call operator operator())

>\* Note: Pointer to data members are callable as well but no function is called at all.
	
There is some name for common callbacks:
	- Predicate : do not modify data and return a boolean

[more details](https://stackoverflow.com/questions/2298242/callback-functions-in-c)

Time
---

```C++
int main ()
{
    using namespace std::chrono;
    // Get current time with precision of milliseconds
    auto now = time_point_cast<milliseconds>(system_clock::now());
    // sys_milliseconds is type time_point<system_clock, milliseconds>
    using sys_milliseconds = decltype(now);
    // Convert time_point to signed integral type
    auto integral_duration = now.time_since_epoch().count();
    // Convert signed integral type to time_point
    sys_milliseconds dt{milliseconds{integral_duration}};
    // test
    if (dt != now)
        std::cout << "Failure." << std::endl;
    else
        std::cout << "Success." << std::endl;
}
```
See details at [time convertion]
	
	
Template - Généricité
-------------------
```
template<typename T>			indique que la méthode ou la class est générique via l'element T.
					dois etre implémenté dans le fichier Header
template<typename T,typename S>		on peux en avoir plusieurs 
template <> meth<Obj>			spécification : permet de définir la methode dans le cas ou on applique le template sur un Obj
```	

Other Library
---

#### Eigen
	
```C++
Eigen::MatrixXd mat(3,3);
mat<<1,2,3,
     4,5,6,
     7,8,9;
Eigen::Index len = mat.rows();

mat.col(0).tail<1>()[0] = 10;
mat.bottomLeftCorner<1,1>()(0,0) = 10;
std::cout << mat.col(0).tail<1>().value();
std::cout << mat.bottomLeftCorner<1,1>().value();	
```

#### [Gtest](https://github.com/google/googletest)

[Primer documenttion](https://github.com/google/googletest/blob/main/docs/primer.md)

- `TEST()` is useful when you want to write unit tests for static or global functions or simple classes. [Example](https://github.com/google/googletest/blob/565f1b848215b77c3732bca345fe76a0431d8b34/googletest/test/googletest-port-test.cc#L54)
- `TEST_F()` is useful when you need access to objects and subroutines in the unit test. [Example](https://github.com/google/googletest/blob/e8a82dc7ede61c4af3b9d75aa0e953b8cecfc8bb/googletest/test/gtest_unittest.cc#L102)
- `TEST_P()` is useful when you want to write tests with a parameter. Instead of writing multiple tests with different values of the parameter, you can write one test using TEST_P() which uses GetParam() and can be instantiated using INSTANTIATE_TEST_SUITE_P(). [Example](https://github.com/google/googletest/blob/eafd2a91bb0c4fd626aae63ae852812fbd4999f2/googletest/test/googletest-param-test-test.cc#L679)
    - read more about [parametrised test](https://www.sandordargo.com/blog/2019/04/24/parameterized-testing-with-gtest)

- Personnalyse out put can be obtain with stream :
```cpp
EXPECT_TRUE(false) << "diagnostic message";
```

	
[Conan]: https://kubasejdak.com/introduction-to-conan-package-manager
[namespace]: https://en.cppreference.com/w/cpp/language/namespace
[time convertion]: https://stackoverflow.com/a/31258680/19624015
