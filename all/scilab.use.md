Scilab 5.5.0
edition : preference : Disposition du bureau : Integre
Consol : executable.sce , editeur : sci.notes
```
function y=f1(x)
//commentaire : corps de la fonction
endfunction
```
||||
|-|-|-|
|waitforbuttonpress : xclick||
|,|			      |séparateur d'instruction
|;|			      |ne pas affiché
|scf|	  	    |affiche une fenetre graphique ( figure en mathlab )
|ctr+A|       |toggle comment current line

Matrice
-
||||
|-|-|-|
|\[a b\]|     |concatener a la ligne
|\[a ;b\]|     |concatener a la colonne
|A(:)|        |ecrire la matrice comme vecteur colone
|A(a:b;c:d)|  |Mat A : ligne a à b, col c à d
|A(a:b;c:$)|  |$ jusqu'a la fin de la ligne

Matrice spécial
-
zeros - ones - eyes - rand
Matrice vide : -sparse(A) / full(A)
NB: si on empile la taille de la matrice s'adapte automatiquement

Operation
-
|||||||||
|-|-|-|-|-|-|-|-|-|
|therme à therme :| |+|-|.*|./|.\\|.^ 
|matrice de meme dimention|  |*|/||||
|transpose| | .'| a ne pas confondre avec ' qui est le conjugué complexe||||
|logique| |true: %T| false: %F| and: &| or: \|| not: ~|

Utile
-
||||
|-|-|-|
|ieee()|                      |Ignore une erreur (ex: div by 0)
|rang() / grand()|            |Aleatoire
|F1 / help <> / apropos <>|   |Aide
|\[i,j\]=find()|              |i ligne trouvé (j col)

String
-
||||
|-|-|-|
|' ou "|  |to create string
|' '|  |empty string
|+|  |concatenate
|String()|  | converte to string
|disp() / printf()|  | Afficher / pretty-print
|mggetl()|  |lecture
|mputl("<>", "<file.txt>")|  |ecriture

Math
-
||||
|-|-|-|
|poly([],'var'),'coef'|  |polynome \[\] soit les racines ou les coefficient
|'factors' / 'roots' / 'degree' / 'horner'(composer)|  | factoriser
|numer() / denom()|  | Fraction rationnelles R=P/Q

HyperMatrice
-
||||
|-|-|-|
|ndims()|   |nb de dimenttion
|size()|    |vecteur longeur de chaque dimention

Prgramme
-
||||
|-|-|-|
|exec()|ctrl+shift+E| execute
||ctrl+shift+L| exec and print(ligne sans ";")
||F5| save and exec
|mode(<#>)| |# : 1,2,3
|input('')| |demander une variable a l'utilisateur
|null()|    |supprime une variable
|linsolve()|  |resolution de systeme


Boite de dialogue
||||
|-|-|-|
|messagebox("")|  |question
|x_dialog()|      |une variable
|x_mdialog()|     |multiple varable
|x_choices()|     |qcm
|uigetfile()|     |parcourire
|plot()|          |graphique

couleur
|||
|-|-|
|k|noir
|b|bleu
|g|vert
|c|cyan
|r|rouge
|m|magenta
|y|jaune
|w|blanc

forme
|||
|-|-|
|>|triangle droit
|<|gauche
|p|star
|x|cross
|d|losange
|^|triangle haut
|v|bas
|o|rond
|*|
|s|square
|-|solid
|_|tiret
|:|poitillet
|.|dot
|+|


structure de controles

Alternative 
  - if,then,else,elseif.end
  - select, case
  - try, catch:errer
 Boucle
  -while, end
  -for var=\[ vecteur colone\], end
 
 
 Nb : var reste changer aprés la boucle

||||
|-|-|-|
|break| |sortir
|continue| | sauté un tour de boucle
 

