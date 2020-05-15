
# Vim

Text Editor

Best cmd
---
- `:w !sudo tee %` save as root
- `ctrl+q` undo `ctrl+s`

Basic
---
copier : y  jusqua la ligne :l
coller : p
copie multiligne : :l1,l2 t l3  copie vers l3 les ligne l1 à l2
déplacement avec m a la place de t
remplacer un mot : ciw < cw
	ci( , ci" , ... remplace à l'interieur des délimiteur
ajout en début de ligne : ctrl+v, sift+i
refaire la meme action : .
fin de ligne $
débt de ligne 0
ajout en fin de ligne sift+a
remplacer r
mode remplacement sift+r
Début gg
fin G

settings
---
:set all&   - reset default
:h set


buffer
---
buffer : "x  x étant le nom du buffer (un par lettre) 
bn - next
bN - prev
bd - del

multiligne identical line bloc insert(usefull for block commenting)
    -`ctrl+v` `]select` `maj+i` `]insert` `esc`
    -`v` `]select` `:s/^/` `]insert` `/` `enter`

remaping
---
note remaping ESC can cause unexpected behavior
(exclamation mark turn command to toggle mode)
nnoremap <n><l> :set hls!<cr>
