
# TMP

should be empty in the previous commit
before making a new one
otherwise use commit amend

## TODO


## Temporary note, to be added to right file

#### c++
extern -> declaration ( have to be defined somewhere, in an otherfile)
the file that define it have to declare it in a global context[without extern but outside of any function], then it can define it any where
https://stackoverflow.com/questions/10422034/when-to-use-extern-in-c
trick to raise notImplementedException
` std::cout << "Not Implemented !\n"; throw; `


(eclamation mark turn command to toggle mode)
414 nnoremap <n><l> :set hls!<cr>

curl cheat.sh
list all files (with location) that were brought in by the package.
dpkg -L
debian
In case if you are not sure about package name you could list all packages and try to find requested:
dpkg --get-selections | grep -v deinstall | grep <packagename>
https://askubuntu.com/questions/115500/how-to-find-location-of-installed-library
apt search
ldd -r
qmake, *.pro
qmake -project
CMakeList -> have to be call from build
add before commit amend
https://en.wikipedia.org/wiki/List_of_3D_graphics_libraries
sfml -> easy  (https://www.sfml-dev.org/tutorials/2.5/start-linux.php)
sudo apt-get install libsfml-dev

#### freetype2
https://techoverflow.net/2019/06/11/how-to-fix-ft2build-h-no-such-file-or-directory/

https://maverick.inria.fr/Members/Nicolas.Holzschuch/#ens
http://evasion.imag.fr/Enseignement/cours/2008/SIA/

Tuto en cour de lecture (see if it helps)
https://www.technical-recipes.com/2013/getting-started-with-opengl-in-linux/

#### libqgl
http://libqglviewer.com/examples/index.html
https://doc.qt.io/qt-5/qmake-project-files.html
https://stackoverflow.com/questions/7642955/problems-compiling-an-c-application-using-qt-and-opengl/7644057
https://ensiwiki.ensimag.fr/index.php?title=Installation_de_QGLViewer,_OpenMesh_et_Alglib
https://community.khronos.org/t/qt-and-opengl-really-basic-question/56688/4
https://github.com/GillesDebunne/libQGLViewer/issues/18
https://forum.ubuntu-fr.org/viewtopic.php?id=149078
https://stackoverflow.com/questions/47647035/cmake-prefix-path-doesnt-help-cmake-in-finding-qt5
https://answers.ros.org/question/236324/could-not-find-a-package-configuration-file-provided-by-qt5widgets/
https://askubuntu.com/questions/508503/whats-the-development-package-for-qt5-in-14-04

https://github.com/openai/roboschool/issues/42

#### OpenSceneGraphe
https://gist.github.com/vicrucann/874ec3c0a7ba4a814bd84756447bc798
http://openscenegraph.sourceforge.net/documentation/OpenSceneGraph/doc/examples.html
http://syntheractive.com/developer/downloads/OSGQSG.pdf
http://www.sm.luth.se/csee/courses/smm/011/l/t1.pdf


#### Interessant ???
https://julien-tierny.github.io/visualizationExercise3dProgramming.html
https://topology-tool-kit.github.io/bettiNumbers.html
https://leminimaliste.info/huaraches-les-chaussures-du-peuple-autochtone-des-coureurs-du-mexique/
https://www.google.com/search?q=qemu

#### cmake
https://stackoverflow.com/questions/24570916/add-external-libraries-to-cmakelist-txt-c
https://cmake.org/cmake/help/v3.0/command/set.html

### 30.04
https://www.sfml-dev.org/tutorials/2.5/start-linux.php

you can look for header file you need to include with www.debian.org
    click `packages` and look for *Search the contents of packages*
    and check `packages that contain files named like this`

#### unit test GUI
https://stackoverflow.com/questions/215458/how-can-i-unit-test-a-gui
http://web.archive.org/web/20151130093108/http://www.objectmentor.com/resources/articles/TheHumbleDialogBox.pdf
https://martinfowler.com/eaaDev/uiArchs.html
https://www.google.com/search?q=regression+test+opengl
https://stackoverflow.com/questions/1586230/automated-testing-for-opengl-application
https://community.khronos.org/t/writing-unit-tests-using-opengl/64482
https://github.com/darkenk/glmock
https://www.youtube.com/watch?v=A_hS4_r5KcA


#### about ocean project
https://github.com/deiss/fftocean

#### make
https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html
https://en.wikipedia.org/wiki/Makefile
https://stackoverflow.com/questions/8646688/make-rule-call-rule
https://gist.github.com/mawenbao/9223908

#### glut
http://www.lighthouse3d.com/tutorials/glut-tutorial/

#### c++
compilation option :
-L path to shared library
-I path to headers
-W, -Wall verbosity, warning (all)
-g add debug flags for gdb
-c     Compiler source(s) to object-code (input to linker). This option is better for incremental compilation when using multiple files.
[for more details](https://caiorss.github.io/C-Cpp-Notes/compiler-flags-options.html)

[Standard library](https://en.cppreference.com/w/cpp/header)

reference
[Core
guidelines](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#a-namerc-orgac1-organize-related-data-into-structures-structs-or-classes)

check memoyleaks
[valgring](http://valgrind.org/docs/manual/mc-manual.html)

headers
http://www.cplusplus.com/articles/Gw6AC542/

lambda function
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


#### md
>block quote
```>block quote```


#### vim 
multiligne identical line bloc insert(usefull for block commenting)
    -`ctrl+v` `]select` `maj+i` `]insert` `esc`
    -`v` `]select` `:s/^/` `]insert` `/` `enter`

remaping 

note remaping ESC can cause unexpected behavior

#### bash
match only/all directories : 
    - cmd `*/`
    -`find . -type d -exec` cmd `{} \;`

change extention :
`for f in *.OLDNAME; do mv $f `basename $f .OLDNAME`.NEWNAME; done;`

debug
add `-x` option  the shebang `#!/bin/bash -x`
install shellcheck


#### Git
[Cheat-sheet](https://education.github.com/git-cheat-sheet-education.pdf)
`git log --stat -M`

to check if a library is installed
`ldconfig -p | grep libname`
To check architecture `uname -m`

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

### 04 may

#### bash
Bash arrays : are recommended to store part of a commande line
it solves quote escaping issues :
```
var=('s1' 's2')
echo "${var[@]}"
```

pv - to monitor progress

long string can be splited by escaping line return
```
#"bla bla bla"
VAR="bla bla \
bla"
```

run in parallel `&` [metachar to run in backgroung]

`;` [metachar: ends the command]

set bash options
shopt -s expand_aliases (WARNING could have side effect)

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

delete empty directories
`find . -empty -type d -delete`

expend shell command
<ctrl> + <alt> + e
or edite `~/.inputrc` add a line with 
```"\e\C-e": alias-expand-line```

empty swap memory
```swapoff -a && swapon -a```


sound mixer issue difference between 
`amixer set Master 5%+`
and 
`amixer -D pulse set Master 5%+`
=
`pactl set-sink-volume @DEFAULT_SINK@ +5%`
also max reduced by gnome environment sound setting

https://wiki.ubuntu.com/DebuggingSoundProblems
https://help.ubuntu.com/community/SoundTroubleshootingProcedure


check desktop environment
```
echo $XDG_CURRENT_DESKTOP
ps -e | grep -E -i "xfce|kde|gnome"
```

command to clear chache 
(1:PageCache only, 2:dentries and inodes, 3:PageCache, dentries and
inodes)
```
sync; echo 1 > /proc/sys/vm/drop_caches
sync; echo 2 > /proc/sys/vm/drop_caches
sync; echo 3 > /proc/sys/vm/drop_caches
```
