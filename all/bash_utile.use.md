```
quota;                               #affiche l'espace mémoir utilisé
ps -alL;                             #processus
ps -ef ;                             #tout les processus
ps  -u --forest;		     #user process in tree view 
xwininfo; wprop;                     #processus fenetre
quota | awk 'NR==4{print $1}'        #découpe quota(4-ligne/1-colone)
vim /etc/passwd                      #liste les commandes interdites
gnome-open                           #ouvre le fichier avec le bon prgm
telnet ensiens 25;                   #envoyer des mail
env; set;                            #affiche les variable d'environnement
du * .* -shc;                        #occupation du disque
vim /etc/services;                   #liste les ports
$PKG_CONFIG_PATH $LD_LIBRARY_PATH    #variable pour les libraries
chmod; setfacl; getfacl;             #gestion des droits
chown;                               #change l'utilisateur
who; w; write;                       #qui fait quoi sur le serveur
which; history;                      #trouver une commande
echo "scale=3; 8/3"|bc               #Arithmetique
as; objdump;                         #compiler décompiler les executables
screen; ctrl+a "                     #Ouvre un terminal, change de terminal
grep -lR "x" *                       #Affiche les fichiers contenant x
grep -zo                             #regexp on the whole file as one line
killall name                         #supprime tout les prgm appelé name
free -m                              #Affiche l'uilisation de la RAM
df                                   #list peripheral devices
dd                                   #copie bit à bit :if = in-file of=out-file
mount -o iocharset=utf8              #monte une clé USB au format utf8
shred                                #écrase complétement l'espace memoir
alsamixer						     #gestionaire des son
lspci							     #liste du materiel
nmap -sP 192.168.0.*				 #liste des machine du reseau local
rsync -av <IN_file> <MAJ_file>	     #mettre à jour un fichier synchroniser
tree -F | less						 #Rechercher un fichier
[ -z "$var" ] && echo "Empty" || echo "$var"		#ternary operator
cp -al					#make a hard link instead of a copy
date -d "+1 month" +%b			#show the next month
RANDOM=$(od -An -N3 -i /dev/random)     #get a random int
tee >file >(cmd)			#multiplicate output, here send to file,cmd and stdout
zenity					#make a GUI for shell scripts
echo "o" | xargs -i echo "hell{} world !" #previous pipe output, call in middle of the command
```

How to 'grep' a continuous stream?
Turn on grep's line buffering mode when using BSD grep (FreeBSD, Mac OS X etc.)
tail -f file | grep --line-buffered my_pattern



### Sed

`\(``\)` give the possibility of delimiter a parts of the pattern that you can letter refer to with `\1`
```s/input-prefix:\(.*\)/replace1-prefix:\1 replace2-prefix:\1/```
use \2 ... \9 if you have more groups in a pattern



### Links

* [Cheatsheet](https://devhints.io/bash)
* [Sed](https://www.grymoire.com/Unix/Sed.html)
* [Awk](https://www.grymoire.com/Unix/Awk.html)
* https://www.linuxjournal.com/content/return-values-bash-functions
* [date exemple](http://www.gnu.org/software/coreutils/manual/html_node/Examples-of-date.html#Examples-of-date)
