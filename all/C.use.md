
```C
#ifndef DEF_NOMDUFICHIER // Si la constante n'a pas été définie le fichier n'a jamais été inclus
#define DEF_NOMDUFICHIER // On définit la constante pour que la prochaine fois le fichier ne soit plus inclus

/* Contenu de votre fichier .h (autres include, prototypes, define...) */
#include <stdlib.h>
#define NOMBRE 9
#define MAJEUR(age) if (age >= 18) \
                    printf("Vous etes majeur\n");


#endif

int main(int argc, char *argv[])
{
    int* memoireAllouee = NULL;

    memoireAllouee = malloc(sizeof(int));
    if (memoireAllouee == NULL) // On vérifie si la mémoire a été allouée
    {
        exit(0); // Erreur : on arrête tout !
    }

    // On peut utiliser ici la mémoire
    free(memoireAllouee); // On n'a plus besoin de la mémoire, on la libère

    return 0;
}


//Pointeur 
//déclaration 
//srtucture
//apppel
//allocation
//passage dans une fonction
//déreférencement
//(*var).structelem   <=> var->structelem
```
Var
---

[types-limit](https://www.tutorialspoint.com/cprogramming/c_data_types.htm)
```C
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main(int argc, char** argv) {

    printf("CHAR_BIT    :   %d\n", CHAR_BIT);
    printf("CHAR_MAX    :   %d\n", CHAR_MAX);
    printf("CHAR_MIN    :   %d\n", CHAR_MIN);
    printf("INT_MAX     :   %d\n", INT_MAX);
    printf("INT_MIN     :   %d\n", INT_MIN);
    printf("LONG_MAX    :   %ld\n", (long) LONG_MAX);
    printf("LONG_MIN    :   %ld\n", (long) LONG_MIN);
    printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
    printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
    printf("SHRT_MAX    :   %d\n", SHRT_MAX);
    printf("SHRT_MIN    :   %d\n", SHRT_MIN);
    printf("UCHAR_MAX   :   %d\n", UCHAR_MAX);
    printf("UINT_MAX    :   %u\n", (unsigned int) UINT_MAX);
    printf("ULONG_MAX   :   %lu\n", (unsigned long) ULONG_MAX);
    printf("USHRT_MAX   :   %d\n", (unsigned short) USHRT_MAX);
    
    printf("Storage size for float : %d \n", sizeof(float));
    printf("FLT_MAX     :   %g\n", (float) FLT_MAX);
    printf("FLT_MIN     :   %g\n", (float) FLT_MIN);
    printf("-FLT_MAX    :   %g\n", (float) -FLT_MAX);
    printf("-FLT_MIN    :   %g\n", (float) -FLT_MIN);
    printf("DBL_MAX     :   %g\n", (double) DBL_MAX);
    printf("DBL_MIN     :   %g\n", (double) DBL_MIN);
    printf("-DBL_MAX     :  %g\n", (double) -DBL_MAX);
    printf("Precision value: %d\n", FLT_DIG );

    return 0;
}
```
more about Difference between [int32, int, int32_t, int8 and int8_t](https://stackoverflow.com/questions/14515874/difference-between-int32-int-int32-t-int8-and-int8-t)


String
---

- To copy string buffer without adding null terminator `/0` 
```C
strncpy(sub1, baseString+8, 4);
//<=>
for(int i=0; i<4; i++)
    sub3[i] = baseString[i+8];
```

Computing
---
Integer Division gives an integer (remember to cast) : `1/(float)2` 

Array
---
If you want to know the **size** of an array `a`
```C
(sizeof(a)/sizeof(*a))
```
:warning:Mind that the above formula gives the allocated **size** not the usage.  

Initializing array do not need size `int t[] = {1,2}`  
but only for the first dimention (if multidimentional) : `int t[][2][1] = {{{4},{3}},{{5},{12}},...}`

Pointer
---
```C
void swapnum(int *num1, int *num2)
{
   int tempnum;

   tempnum = *num1;
   *num1 = *num2;
   *num2 = tempnum;
}
int main( )
{
   int v1 = 11, v2 = 77 ;
   swapnum( &v1, &v2 );
}
```


Private
---
```C
int private_f_real_name(void)
{
    ...
}

#define f private_f_real_name
int g(void)
{
    // call f()
}
#undef f

// calling f() now won't work
```

Macro
---

* add trace : How do I show the value of a #define at compile-time?
```C
#define XSTR(x) STR(x)
#define STR(x) #x
```
The value of a macro can then be displayed with:
```C
#pragma message "The value of ABC: " XSTR(ABC)
```

* Or use some Remeinder :
```C
// Statements like:
 // #pragma message(Reminder "Fix this problem!")
 // Which will cause messages like:
 // C:\Source\Project\main.cpp(47): Reminder: Fix this problem!
 // to show up during compiles. Note that you can NOT use the
 // words "error" or "warning" in your reminders, since it will
 // make the IDE think it should abort execution. You can double
 // click on these messages and jump to the line in question.

 #define Stringize( L )     #L 
 #define MakeString( M, L ) M(L)
 #define $Line MakeString( Stringize, __LINE__ )
 #define Reminder __FILE__ "(" $Line ") : Reminder: "

//Once defined, use like so:

#pragma message(Reminder "Fix this problem!") 
```

- Variadic macro `__VA_ARGS__` in the macro replacement list is replaced by the passed arguments. **Note** : Both the C99 and C++11 standards require at least one argument, but since C++20 this limitation has been lifted through the `__VA_OPT__` functional macro.

Hardware
---

#### Register access

directly set the address of a pointer, so that it behave as a register :
```C
uint32_t* Reg = (uint32_t*)0x12345678;
```
Then use is as an array
```C
read = Reg[0];
Reg[1] = write;
```
See [memory-mapped I/O]

#### Bit operation

```C
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
```
use it this way to check the nth bit from the right end:
```C
CHECK_BIT(temp, n - 1)
```
In C++, you can use std::bitset.



[memory-mapped I/O]: https://stackoverflow.com/a/2389273
