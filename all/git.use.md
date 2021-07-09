GIT
===

[Cheat-sheet](https://education.github.com/git-cheat-sheet-education.pdf)

### Basic commands

* créer un dépots :
`git init --shared --bare notre-tp.git`

* trouver l'address du depots git :
`git remote show origin`

* annuler une modification
`git checkout <file>`

* telecharger un repo
```
git clone
https://user:password@git_host...
sever.dom:/path/to/file
```

* create a new commit
`git commit`
* add file for next commit
`git add file`
* ajout interactif
`git add -p`
* auto-add all modified files and commit
`git commit -a`
* show the list of last commit
`git log`

* récupère la mise a joure distante
`git pull`

* met a joure la branche maitre
`git push`


### Configuration

pour ne pas avoir à tout le temps mettr user
-rensseigne name@file.git au premier commit
-git --config -i


Save password
git config credentrial.helper store

touch .gitignore

vim .gitattributes

### advanced commands

* to revert initial git commit
`git update-ref -d HEAD`
* to modify previous commit
`git commit rebase -i`
* pretty print of the graph
`alias lg='git log --all --decorate --oneline --graph'`
* modify last commit
`git commit --amend` (need `add`before) if already pushed add force option `git push --force`
* view previous commit changes
`git show HEAD[~#]`

### Branches
`git checkout -b new_branche`

### log
display changes made by commit 
`git log --stat -M`
display graph
`git log --all --decorate --oneline --graph`

