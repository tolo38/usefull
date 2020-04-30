/* 
 * Deverminage - programme de demonstration debutants
 * Warnings de compilation
 * Debogueurs memoire : valgrind / fsanitize
 * Debogueurs gdb / ddd
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

struct list {
    uint16_t val;
    struct list *suiv;
};

void insere_suivant(struct list *debut, uint16_t valeur);
void affiche_liste(struct list *debut, char *message);
void affiche_tab(int16_t *table, uint16_t nb);

int main(void)
{
    /* On demarre doucement */
    int entier = 10;
    entier = 20;
    *(&entier) = 40;

    /* Un autre pour faire plaisir */
    int16_t *entier2;
    entier2=malloc(10 * sizeof(int16_t));
    entier2[5] = 5;
    affiche_tab(entier2, 10);
    free(entier2);

    /* Un dedale de chaines de caracteres : y voir plus clair avec gdb/ddd */
    char *chaine1 = "ensimag";
    char *chaine2 = &chaine1[0];
    char **chaine3 = &chaine2;
    char ***chaine4 = &chaine3;
    char *chaine5 = "grenoble inp";
    chaine2 = &chaine5[0];
    printf("chaine4 = %s\n", **chaine4);

    /* Un tableau */
    int16_t tab[4] = {1, 2, 3, 4};
    //*(tab+4) = 8;
    tab[4] = 8;
    affiche_tab(tab, 4);

    /* Une liste */
    struct list liste = {99, NULL};
    char *message="Liste initiale";
    affiche_liste(&liste,"Liste initial"); //&message);

    insere_suivant(&liste, 100);
    affiche_liste(&liste, "Liste finale");

    /* Un petit dernier avec des macros : gcc -E */
    #if defined(A)
    printf("A\n");
    #elif defined(B)
    printf("B\n");
    #else
    printf("C\n");
    #endif
    exit(EXIT_SUCCESS);
}

void affiche_tab(int16_t *table, uint16_t nb)
{
    for (uint16_t i = 0; i <= nb; i++) {
        printf("%hu ", table[i]);
    }
    printf("\n");
}

void affiche_liste(struct list *debut, char *message)
{
    struct list *sentinelle = debut;
    printf("%s :\n", message);
    while (sentinelle != NULL) {
        printf("%hu ", sentinelle->val);
        sentinelle = sentinelle->suiv;
    }
    printf("\n");
}

void insere_suivant(struct list *debut, uint16_t valeur)
{
    struct list nouveau;
    nouveau.val = valeur;
    nouveau.suiv = NULL;
    debut->suiv= &nouveau;
}

