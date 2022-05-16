[Cheat Sheet](https://gist.github.com/mattratleph/4026987)

Keyboard Shortcuts:
--

do - Get changes from other window into the current window.

dp - Put the changes from current window into the other window.

]c - Jump to the next change.

[c - Jump to the previous change.

Ctrl W + Ctrl W - Switch to the other split window.


If you load up two files in splits (:vs or :sp), you can do :diffthis on each window and achieve a diff of files that were already loaded in buffers
:diffoff can be used to turn off the diff mode. 
You can even just say :windo diffthis in one of the split, and it will apply to all splits in that window :)

However, `Ctrl W + Ctrl W` is not required to switch windows. Ctrl W + W is enough to cycle windows. You can try Ctrl W + <any of the direction keys> to switch among windows in vimdiff or in vim with split windows.

To ignore whitespace use this command: set diffopt+=iwhite

To turn that back off use: set diffopt-=iwhite

:e % is opening the file again, isn't it better to use :diffupdate. It will conserve the undo/redo history.

:set wrap to see all line inside the screen evenif theire is not line break.

:qa to quit all
:qa! to quit all without saving
:wqa save and quit all
  
Git Mergetool
--

* get Local/Base/Remote to file
 `:diffget Lo/Ba/Re`
* get a specific line (" split the chunk")
`v` select in visual mode, then `:diffget ...`
* more at : `:help copy-diffs`
* `git mergetool` to call the merge tool and resole conflict
* set vimdiff as the merge tool `git config merge.tool vimdiff` 
