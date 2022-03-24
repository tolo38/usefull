GIT
===

[Cheat-sheet - github](https://education.github.com/git-cheat-sheet-education.pdf)

[Cheat-sheet - gitlab](https://about.gitlab.com/images/press/git-cheat-sheet.pdf)


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


* Get Remote update (récupère la mise a joure distante)
`git pull`
* Get Remote Branches
`git fetch`

* met a joure la branche maitre
`git push`

* Clean repo from untracked files
`git clean -fd`

* Diff staged changes
`git diff --cached`

* Backup changes and clean repo
`git stash`
Load changes again
`git stash pop`
Check changes in details
`git stash show -p stash@{0}`

### Configuration

pour ne pas avoir à tout le temps mettr user
-rensseigne name@file.git au premier commit
-git --config -i


Save password
git config credentrial.helper store

touch .gitignore

vim .gitattributes

### advanced commands

* see the history
`git reflog show` 
* to revert initial git commit
`git update-ref -d HEAD`
* to deal with conflict when rebase or merge
`git mergetool` usually [vimdiff](https://github.com/tolo38/usefull/blob/master/all/vimdiff.use.md)
* pretty print of the graph
`alias lg='git log --all --decorate --oneline --graph'`
* modify last commit
`git commit --amend` (need `add`before) if already pushed add force option `git push --force`
* to modify previous commit 
`git commit rebase -i` use `HEAD~#` 
  * then squash
move commit line bellow the one to merge with change `pick` to `s` 
* view previous commit changes
`git show HEAD[^#]`
* renaming a file : git does it [automatically](https://stackoverflow.com/a/434078), it then all about display
`git log -M20 -p --stat` with `-M` option help reduce the similarity threashold

### Branches
`git checkout -b new_branch`
* rebase on `develop` branch
```
git checkout develop
git pull -p
git checkout <branch>
git rebase develop
```

### log
display changes made by commit 
`git log --stat -M`
display graph
`git log --all --decorate --oneline --graph`

### Test Driven Devellopment (TDD)
* Create a branch from `develop`for the issue
* ~~Create a branch from `issue` by feature/behavior~~
* Write a test requiering the feature and `commit -m "<feature> [Req]"`
* Write the minimal code to pass the test `commit -m "<feature> [Min]"`
* Refactore that code and `commit -m "<feature>"` ~~and merge to `issue`~~
* Continue to the next feature until the issue has to be merged
* It is easy to edit any commit with `git rebase -i ###~` with `###` the commit ID.
* Use `git rebase --continue` to go for the next commit.
