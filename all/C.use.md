
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

String
---

- To copy string buffer without adding null terminator `/0` 
```C
strncpy(sub1, baseString+8, 4);
//<=>
for(int i=0; i<4; i++)
    sub3[i] = baseString[i+8];
```

Array
---
If you want to know the **size** of an array `a`
```C
(sizeof(a)/sizeof(*a))
```
:warning:Mind that the above formula gives the allocated **size** not the usage.


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
