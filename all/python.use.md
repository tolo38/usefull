

interpretor
---
```
python [-i src.py]				#mode interactif 
_								#resultat precedent
x**y							#x a la puissance y
"un"+" peu"						#concatenate
pass							#"Nop" statment: do nothing
float('NaN')					#valeur inexistante
```
Module
---
```
from mod import	*				#load all the name in the curent namespace
from mod import sub				#better practice
import mod						#instead of this load it in mod namespace 
dir(mod)						#provide the list of those names
if __name__ == "__main__":		#at the end of a module: allow to test it
```
##### List all available `modules`
```py
help("modules")
```
```bash
pip list
```
More advenced option is to look for installed lib in file system:
- to find the `/python/lib/` path run `help(<>)` with any modules`<>` and look for `FILE` output
###### List module content
- `help(<module>)`
- `<module>.__dir__()`
 
Variable
---
`help(var) 		#Give us details about variable type, en fonctions`

boolean
---
```
a in b (a not in b)
a is b (a is not b)
and, or							#short-circuit operators
```
Tableau(=Lists(=pile))
---

(convention sur l'indice initial)
+---+---+---+---+---+---+
| P | y | t | h | o | n |
+---+---+---+---+---+---+
0   1   2   3   4   5   6
-6  -5  -4  -3  -2  -1

tab[a:b]						#from a to b 
tab[a:]							#from a to end ( le contraire existe)
len(tab)						#give the lenght
tab1+tab2						#concatenate lists
tab = []						#make it empty (free)
del tab[i]						#delete the i value
del tab							#delete the variable
tab.append(a)					#add 'a' to the end
tab = tab + [a]					#more efficient 
list(range(a,b))				#return a list from a(opt=0) to b-1
								#NB : range() is an iterable object
a in tab						#true if 'a' is in tab
squares = [x**2 for x in range(10)]		#list comprehention

Matrix(nested list)
---
matrix = [[a, b], [c, d]]		#create a matrix
[[row[i] for row in matrix] for i in range(4)] #transpose (list comprention)
list(zip(*matrix))				#do the same
zip()							#nest (imbrique) structurs

tuples
---
t = ()

Sets
---
s = {}
s = set()

Dictionary
---
d = {}
d = {key:value,k2:v2}
d= dict(k1=v1,k2=v2)
for k, v in knights.items():	#loop with k and v
pairs.sort(key=lambda pair: pair[1]) #cool : permet de trier en indiquant la position de la clé


Fonction
---

def func():						#create the func function
								#return None by Default
func							#function address
def func(a1,a2=a):				#a1,a2 argument (a2 default value is a value)
								#warning: The default value is evaluated only once
def func(L=[]):					#Then L is allways the same list 
```								#here is the solution
def f(a, L=None):
    if L is None:
        L = []
    L.append(a)
    return L
```
def func(*args):				#args will contain the list of all passed arguments
```
def func(a : str)->int:
	"""Documentation
	on several lines
	"""
	pass

```
print(func.__doc__)				#display the function doc
print(func.__annotations__)		#function attribute type(warning : c'est juste de la doc on peu mettre nimporte quoi) 

In/Out
---
x = int(input("Please enter an integer: "))		#read a int from keyboard
print(repr(x).rjust(2), repr(x*x).rjust(3), end=' ')
print(repr(x*x*x).rjust(4))		#ajute les espace
print('{0:2d} {1:3d} {2:4d}'.format(x, x*x, x*x*x))	#affiche la même chose
print('%d %d %d' % x, x*x, x*x*x)		#ancien methode
print('{!s} {a1:.3}'.format(x, a1=math.pi))	#!s do as str() converti en string
f = open('file', 'w')			#open a file
with open('workfile') as f:		#better practice
read_data = f.read()			#read file
f.closed						#test if the file is open/close
f.write(b 'something')			#write something in f (b : opt, mean that it is a binary file
seek(),tell()					#allow to move in the file


Serializing
---
import json
json.dumps([1, 'simple', 'list'])
dump(),load()					#see also

Parsing(RegExp)
---
`nodes=[re.findall('\d+', n) for n in strArr]   #make a list of numbers from string for each`


Class
---
class MyClass:					#new class declaration
MyClass.f					#attribute reference
x = MyClass()					#instantiation
def __init__(self):				#constructor

Note
---

#take care that python is indent with space(you can add it to .vimrc)
autocmd BufNewFile,BufRead *.py setlocal expandtab


python -Qnew prog.py			#execute un scripte python

pip install --user tqdm			#installer le paquet tqdm
Pakage :
	pytest
	opencv-python



ToUnderstand
---
*a
**a
