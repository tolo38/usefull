
# Vim

Text Editor

Best cmd
---
- `!vimtutor`
- `:w !sudo tee %` save as root
- `ctrl+q` undo `ctrl+s`
- merge lines `Shif+J`
- `:!` run a command in term
- as `%` match the whole file `:%!xxd` turn binary to hexadecimal

Basic
---
- copier : `y`  jusqua la ligne :l
- coller : `p` (as a word : vwp)
- copie multiligne : `:l1,l2 t l3`  copie vers l3 les ligne l1 à l2
- move with `m` instead of `t` that copies
- remplacer un mot : `ciw` < cw
	- ci( , ci" , ... remplace à l'interieur des délimiteur
- ajout en début de ligne : `ctrl+v, shift+i`
- refaire la meme action : `.`
- fin de ligne `$`
- débt de ligne `0`
- ajout en fin de ligne `shift+a`
- remplacer `r`
- mode remplacement `shift+r`
- Début `gg`
- fin `G`
- Increase number `Ctrl+A` \ Decrease `Ctrl+X`

settings
---
- `:set all&`   - reset default
- `:h set`

macro
---
hit `q` then one letter `name` to start recording. 
Then hit `q` again to stop it.
call macro with `@` `name`.

buffer
---
- buffer : "x  x étant le nom du buffer (un par lettre) 
- `bn` - next
- `bN` - prev
- `bd` - del

multiligne identical line bloc insert(usefull for block commenting)
    - `ctrl+v` `]select` `maj+i` `]insert` `esc`
    - `v` `]select` `:s/^/` `]insert` `/` `enter`

remaping
---
- note remaping ESC can cause unexpected behavior
- (exclamation mark turn command to toggle mode)
- `nnoremap <n><l> :set hls!<cr>`
	
- Create Snipet with vim
`nnoremap ,html :-1read <file_path><CR>A` insert the file (at file_path) content under cursor ("A" insert at the end of the line)
	
advenced
---
- `fF` - go to next/prev occuence of char
- `;,` - again
- `{}` - go to next/prev paragraphe
