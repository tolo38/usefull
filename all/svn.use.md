
svn co --depth empty http://server/depot
svn up --set-depth infinity folder1
svn status
svn help add
svn remove folder
svn add folder --depth empty
svn ignore folder1 file2
svn propset svn:ignore file1 folder2 targetFolder
svn proplist targetFolder
svn propget  svn:ignore targetFolder
export SVN_EDITOR=vi
svn propedit  svn:ignore targetFolder
svn commit

svn diff
svn diff -r BASE:PREV file
svn diff | GREP_COLOR="1;35" egrep '^\+.*|$' --color=always | GREP_COLOR="1;36" egrep '^\-.*|$' --color=always | less -R

pour igniorer les fichiers que l'on ne souhaite pas commit on peux se déplacer dans l'arborescence.
si il y a un probleme avec un fichier le suprimmer et faire "svn update"