http://gl.developpez.com/tutoriel/outil/makefile/


Les makeile essaye de générer le fichier présisé par la règle appelee
si certaine dépendance manque a l'appel il essaye d'appeler les règles correspondante
sinon leve une erreur

Les Variable
SHELL=/bin/bash
FILE=pur-latex
$(FILE).pdf: $(FILE).tex

Pour les noms d'exécutables et d'arguments :
    AR : programme de maintenance d'archive (ar) ;
    CC : compilateur C (gcc) ;
    CXX : compilateur C++ (g++) ;
    RM : commande pour effacer un fichier (rm) ;
    TEX : programme pour créer un fichier TeX dvi à partir d'un source TeX (latex) ;
    ARFLAGS : paramètres à passer au programme de maintenance d'archives ;
    CFLAGS : paramètres à passer au compilateur C ;
    CXXFLAGS : paramètres à passer au compilateur C++ ;
    LDFLAGS : paramètres à passer au compilateur pour l'éditions de liens.

Pour les noms de répertoires et les destinations :
    prefix : racine du répertoire d'installation (= /usr/local) ;
    exec_prefix : racine pour les binaires (= $(prefix)) ;
    bindir : répertoire d'installation des binaires (= $(exec_prefix)/bin);
    libdir : répertoire d'installation des librairies (= $(exec_prefix)/lib) ;
    datadir : répertoire d'installation des données statiques pour le programme (= $(exec_prefix)/lib) ;
    statedir : répertoire d'installation des données modifiables par le programme (= $(prefix)/lib);
    includedir : répertoire d'installation des en-têtes (= $(prefix)/include) ;
    mandir : répertoire d'installation des fichiers de manuel (= $(prefix)/man) ;
    manxdir : répertoire d'installation des fichiers de la section x du manuel (= $(prefix)/manx) ;
    infodir : répertoire d'installation des fichiers info (= $(prefix)/info) ;
    srcdir: répertoire d'installation des fichiers sources (= $(prefix)/src).

Les variables implicites(automatique) les plus utiles sont les suivantes :
— $@ : nom de la cible ;
— $< : nom de la première dépendance ;
— $ˆ : liste des dépendances ;
— $? : liste des dépendances plus récentes que la cible ;
— $* : la chaîne qui correspond au % dans l’instantiation d’une règle implicite (en général, le nom
	d’un fichier sans son suffixe).

les variables shell sont préceder d'un dollard -> $$
for i in $$(seq 1 10); do \
	echo "$$i"; \
	done

Les Patterns :
utilisé des liste de fichier
VG_SOURCES=$(wildcard *.svg)               ->creer une liste de fichier .svg
SVG_PDFFILES=$(SVG_SOURCES:%.svg=%.pdf)    ->transforme la liste en .pdf

regle pour traiter un a un les elements de la liste
%.pdf: %.svg
		inkscape $< --export-pdf $@


Les fichier qui n'existe pas réelement (phony target):
.PHONY: all
	all: $(FILE).pdf

.PHONY: clean
	clean:
		rm -f $(FILE).ps $(FILE)-nup.ps $(FILE).log $(FILE).aux

.PHONY: view
	view: $(FILE).pdf
		evince $<

Désactivation des règles implicites:
.SUFFIXES:
 

les Conditions:
DEBUG = yes
ifeq ($(DEBUG),yes)
        CFLAGS = -g -W -Wall
else
        CFLAGS =
endif

Appel Récursif:
	make -C main all   #equivaut à : cd main && make;
-n : liste ce que make va faire, sans le faire ;
-f : indique le fichier Makefile ;
-j3 : parallélise l'exécution de make (très utile sur biprocesseur) ;
-p : liste les règles implicites ;



commprendre le makefile de cep--------------------------------------------------------------------------------------------------------------
