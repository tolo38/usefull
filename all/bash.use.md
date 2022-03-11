

# Bash


```
curl cheat.sh
```

- `;` [metachar: ends the command]
- run in parallel `&` [metachar to run in backgroung]


set bash options
shopt -s expand_aliases (WARNING could have side effect)

- expend shell command
`<ctrl> + <alt> + e`
to set the shortcut edite `~/.inputrc` add a line with 
```"\e\C-e": alias-expand-line```


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
grep -lR "x" *                       #find recurivly files containing "x"
grep -zo                             #regexp on the whole file as one line
grep -B 5 -A 2 --color               #Shows line before and after with color
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
[ -z "$var" ] && echo "Empty" || echo "$var"		#ternary operator (Note the spaces)
cp -al					#make a hard link instead of a copy
date -d "+1 month" +%b			#show the next month
RANDOM=$(od -An -N3 -i /dev/random)     #get a random int
tee >file >(cmd)			#multiplicate output, here send to file,cmd and stdout
zenity					#make a GUI for shell scripts
echo "o" | xargs -i echo "hell{} world !" #previous pipe output, call in middle of the command
pv                                   #to monitor progress
tar -xvf archive.tar.gz              #to extract
```


delete empty directories
`find . -empty -type d -delete`


match only/all directories : 
    - cmd `*/`
    -`find . -type d -exec` cmd `{} \;`

change extention :
`for f in *.OLDNAME; do mv $f `basename $f .OLDNAME`.NEWNAME; done;`

ask for confirmation :
```
while true; do
    read -p "Continue (y/n)?" -n 1 -r
    case "$REPLY" in
        y ) break;;
        n ) break 2;;
        * ) echo "invalid";;
    esac
done
```

`less` to display the file per centage `CTRL + G`
```
Type:
Gg-M
```

System Information
---
- check desktop environment
```
echo $XDG_CURRENT_DESKTOP
ps -e | grep -E -i "xfce|kde|gnome"
```
- To check architecture `uname -m`

Memory
---
#### Disk usage
- baobab;
- quota;
- du
#### Memory
empty swap memory
```swapoff -a && swapon -a```


command to clear chache
(1:PageCache only, 2:dentries and inodes, 3:PageCache, dentries and
inodes)
```
sync; echo 1 > /proc/sys/vm/drop_caches
sync; echo 2 > /proc/sys/vm/drop_caches
sync; echo 3 > /proc/sys/vm/drop_caches
```

Script
---

#### Debug
add `-x` option  the shebang `#!/bin/bash -x`
install `shellcheck`

#### String
long string can be splited by escaping line return
```
#"bla bla bla"
VAR="bla bla \
bla"
```

#### Boolean
Boolean does not exist, instead :
set/unset variable
`man [`
`help [`
`help [[`
```
${var+set}    #expend in set   if not unset
${var-unset}  #expend in unset if not set (empty is set)
man --pager="less -p '^ *Parameter Expansion'" bash
```
Note : set is a bash builtin command that show setted var,
calling set with a var name does not actually set it (see `help set`)

Note: be carefull with ternary operator order,
it can have side effect if you do not concidere
the lazy evalution.


#### Arrays
Bash arrays : are recommended to store part of a commande line
it solves quote escaping issues :
```
var=('s1' 's2')
echo "${var[@]}"
```


How to 'grep' a continuous stream?
Turn on grep's line buffering mode when using BSD grep (FreeBSD, Mac OS X etc.)
tail -f file | grep --line-buffered my_pattern

#### Functions
[details](https://linuxize.com/post/bash-functions/)

```
function myfunc()
{
    local  __resultvar=$1
    local  myresult='some value'
    if [[ "$__resultvar" ]]; then
        eval $__resultvar="'$myresult'"
    else
        echo "$myresult"
    fi
}

myfunc result
echo $result
result2=$(myfunc)
echo $result2
```

#### Options And Arguments

[Tuto](https://sookocheff.com/post/bash/parsing-bash-script-arguments-with-shopts/)
[Multiple Argument for a single opt](https://stackoverflow.com/q/7529856)

Test the following file running `bash try f1 -c test t ty whet si the loh teraim you tuk`

```
#! \bin\bash
text=""  # Default to empty
textPlus=""
sub=""
folder1=""
folder2=""

#Last argument
folder1=${!#}
#next to last
folder2=${*: -2:1}
# All arguments
echo $@

while getopts ":h" opt; do
  case ${opt} in
    h )
      echo "Usage:"
      echo "    test -h                      Display this help message."
      echo "    test pos1Arg                 read options."
      exit 0
      ;;
   \? )
     echo "Invalid Option: -$OPTARG" 1>&2
     exit 1
     ;;
  esac
done
shift $((OPTIND -1))

# remove 'cmdName' from arg list
shift

#Lookfor -c option
while getopts ":c:" opt; do
  case ${opt} in
    c )
            #First arg after -c
            text=$OPTARG
            #Next on
            textPlus=$(eval "echo \${$OPTIND}")
            #All args after -c before other dash
            sub=("$OPTARG")
            until [[ $(eval "echo \${$OPTIND}") =~ ^-.* ]] || [ -z $(eval "echo \${$OPTIND}") ]; do
                sub+=($(eval "echo \${$OPTIND}"))
                OPTIND=$((OPTIND + 1))
            done
      ;;
   \? )
     echo "Invalid Option: -$OPTARG" 1>&2
     exit 1
     ;;
        : )
          echo "Invalid Option: -$OPTARG requires an argument" 1>&2
          exit 1
          ;;
  esac
done
shift $((OPTIND -1))

echo $@
echo "contain $text word(s)"
echo "Plus $textPlus word(s)"
echo in $folder1 folder
echo in $folder2 folder
echo remians ${sub[@]}
```


### Sed

`\(``\)` give the possibility of delimiter a parts of the pattern that you can letter refer to with `\1`
```s/input-prefix:\(.*\)/replace1-prefix:\1 replace2-prefix:\1/```
use \2 ... \9 if you have more groups in a pattern

### Package

to check if a library is installed
`ldconfig -p | grep libname`

list all files (with location) that were brought in by the package.
dpkg -L <packagename>

In case if you are not sure about package name you could list all packages and try to find requested:
dpkg --get-selections | grep -v deinstall | grep <packagename>

```
apt search
```

see executable library dependencies
```
ldd -r
```

you can look for header file you need to include with www.debian.org
    click `packages` and look for *Search the contents of packages*
    and check `packages that contain files named like this`

### Temporary files

```
mktemp && vim "$_"
mount -t tmpfs -o size=500m tmpfs /mountpoin
```
    
### Encrypt file
 
`vim` Encrypte `-x` and decipher `-X`

    
Decipher gpg file 
```
    tf=$(mktemp)
    gpg -o $tf -d ~/gpg_file && localc $tf
```    

with `localc` openning the temporary file in a libreoffice sheet
    
And Cipher back
    ` && gpg -o ~/gpg_file --cipher-algo AES256 -c $tf`
    
    
`echo RELOADAGENT | gpg-connect-agent` remove passphrase from cache
    
### Media Tools

Normalize musics with `mp3gain`

save video stream
youtude-dl
```
sudo curl -L https://yt-dl.org/downloads/latest/youtube-dl -o /usr/local/bin/youtube-dl
sudo chmod a+rx /usr/local/bin/youtube-dl
youtube-dl --version
```
Download video
```
youtube-dl https://www.twitch.tv/videos/1234567890 -v
```
or jsut the audio
```
youtube-dl https://www.twitch.tv/videos/1234567890 -x --audio-format mp3 -v
```

[tuto save french TV stream](https://www.portail-de-la-gratuite.com/vid%C3%A9o/chapitre-v/)
[M6](https://www.portail-de-la-gratuite.com/chroniques/mchichereplay/)
[capTV](http://captvty.fr/faq#linux)


### Links

* [Cheatsheet](https://devhints.io/bash)
* [Sed](https://www.grymoire.com/Unix/Sed.html)
* [Awk](https://www.grymoire.com/Unix/Awk.html)
* https://www.linuxjournal.com/content/return-values-bash-functions
* [date exemple](http://www.gnu.org/software/coreutils/manual/html_node/Examples-of-date.html#Examples-of-date)
