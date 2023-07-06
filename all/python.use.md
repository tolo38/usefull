

interpretor
---
```py
python [-i src.py]				#mode interactif 
_						#resultat precedent
x**y						#x a la puissance y
"un"+" peu"					#concatenate
pass						#"Nop" statment: do nothing
float('NaN')					#valeur inexistante
5/2	#=2.5					#floating division
5//2	#=2					#integer division
```
Module
---
```py
from mod import	*				#load all the name in the curent namespace
from mod import sub				#better practice
import mod						#instead of this load it in mod namespace 
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
- `help()`
- `dir()`
 
Variable
---
`help(var) 		#Give us details about variable type, en fonctions`

- **Pretty print** : thanks to [pprint] 
```py
import pprint
stuff = ['spam', 'eggs', 'lumberjack', 'knights', 'ni']
stuff.insert(0, stuff[:])
pp = pprint.PrettyPrinter(indent=4)
pp.pprint(stuff)
```

boolean
---
```py
a in b (a not in b)
a is b (a is not b)
and, or							#short-circuit operators
```
Ternary operator
---
```py
'true' if True else 'false'
```

Tableau(=Lists(=pile))
---
```py
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
sum([1 for x in frequencies if x > 0])		#conditionnal list comprehension
```

Matrix(nested list)
---
```py
matrix = [[a, b], [c, d]]		#create a matrix
[[row[i] for row in matrix] for i in range(4)] #transpose (list comprention)
list(zip(*matrix))				#do the same
zip()							#nest (imbrique) structurs
```
Transpose (Generique)  :
```py
# discards no data if jagged and fills short nested lists with None
list(map(list, itertools.zip_longest(*l, fillvalue=None)))
```

tuples
---
```py
t = ()
```

Sets
---
```py
s = {}
s = set()
```

Dictionary
---
```py
d = {}
d = {key:value,k2:v2}
d= dict(k1=v1,k2=v2)
for k, v in knights.items():	#loop with k and v
pairs.sort(key=lambda pair: pair[1]) #cool : permet de trier en indiquant la position de la clé
```

Lambda
---
```py
x = lambda a, b : a * b
```

Fonction
---

def func():						#create the func function
								#return None by Default
func							#function address
def func(a1,a2=a):				#a1,a2 argument (a2 default value is a value)
								#warning: The default value is evaluated only once
def func(L=[]):					#Then L is allways the same list 
```py								#here is the solution
def f(a, L=None):
    if L is None:
        L = []
    L.append(a)
    return L
```
def func(*args):				#args will contain the list of all passed arguments
```py
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
```py
x = int(input("Please enter an integer: "))		#read a int from keyboard
print(repr(x).rjust(2), repr(x*x).rjust(3), end=' ')
print(repr(x*x*x).rjust(4))		#ajute les espace
print('{0:2d} {1:3d} {2:4d}'.format(x, x*x, x*x*x))	#affiche la même chose
print('%d %d %d' % x, x*x, x*x*x)		#ancien methode
print('{!s} {a1:.3}'.format(x, a1=math.pi))	#!s do as str() converti en string
"a string {} {} {} format{}".format( 0, "toto", *[i for i in ["that", "be", "could"]] + ["ed", "-"], "and more...")
"a string {2} {4} {3} format{5}".format( 0, "toto", *[i for i in ["that", "be", "could"]] + ["ed", "-"], "and more...")

f = open('file', 'w')			#open a file
with open('workfile') as f:		#better practice
read_data = f.read()			#read file (-> all document into one string)
		.readlines()		#read juste the next line -> into a string
f.closed						#test if the file is open/close
f.write(b 'something')			#write something in f (b : opt, mean that it is a binary file
seek(),tell()					#allow to move in the file
```
- `help('FORMATTING')` for more details

Check file extension :
```py
string_file_name.endwith(".ext")
```

Command Line Arguments
---
Command line arguments are in the array `sys.args`
```py
import sys

if __name__ == "__main__":
    print(f"Arguments count: {len(sys.argv)}")
    for i, arg in enumerate(sys.argv):
        print(f"Argument {i:>6}: {arg}")
```

Serializing
---
import json
json.dumps([1, 'simple', 'list'])
dump(),load()					#see also

Parsing(RegExp)
---
`nodes=[re.findall('\d+', n) for n in strArr]   #make a list of numbers from string for each`
* extract numbers `[int(s) for s in txt.split() if s.isdigit()]`


Class
---
```py
class MyClass:					#new class declaration
MyClass.f					#attribute reference
x = MyClass()					#instantiation
def __init__(self):				#constructor
E = type('',(object,),{})()			#lambda object anonymous class
```

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
- `*a` the "splat operator" unpack sequence (such as generator) see [PEP448] for more detail
- `**a`


---

Threading
---
```
threading.Timer(0.01, print("wait for 1ms delay")).start()
```



Plot
---
```py
import matplotlib.pyplot as plt # For ploting
import numpy as np # to work with numerical data efficiently

fs = 100 # sample rate 
f = 2 # the frequency of the signal

x = np.arange(fs) # the points on the x axis for plotting
# compute the value (amplitude) of the sin wave at the for each sample
y = np.sin(2*np.pi*f * (x/fs)) 

#this instruction can only be used with IPython Notbook. 
% matplotlib inline
# showing the exact location of the smaples
plt.stem(x,y, 'r', )
plt.plot(x,y)
```

Pandas
---
- [Pandas Basic]
- make a csv `panda.DataFrame(data).to_csv("file.csv")`
- [Pandas shift data]

[Deamon]
---
to make a python script run in background
- [linux][deamon-linux] : `nohup python -u ./test.py &`
- [windows][deamon-windows] : run with `pythonw.exe` and use `*.pyw` extention
- there is other option directly from inside the [script][deamon-script] or [subprocess]

[Autoit]
---
```py
import autoit
import time

time.sleep(5)
autoit.run("notepad.exe")
autoit.win_wait_active("[CLASS:Notepad]", 3)
autoit.control_send("[CLASS:Notepad]", "Edit1", "reminder{!}")
autoit.win_close("[CLASS:Notepad]")
autoit.control_click("[Class:#32770]", "Button2")
```
PySimpleGUI
---
```py
import PySimpleGUI as sg
sg.theme('Dark Blue 3')
layout = [  [sg.Text('Move mouse over me', key='-TEXT-')],
            [sg.In(key='-IN-')],
            [sg.Button('Move mouse over me', key='-BUTTON-',border_width=0,button_color=('white','#2fa4e7'),font=('sans-serif',14)), sg.Button('Exit')] ]

window = sg.Window('Window Title', layout, finalize=True)
window['-BUTTON-'].bind('<Enter>', '+MOUSE OVER+')
window['-BUTTON-'].bind('<Leave>', '+MOUSE AWAY+')

i = 0
while True:             # Event Loop
    event, values = window.read()
    if '-BUTTON-' in event:
        i = i+1
        window['-BUTTON-'].update(i,button_color=('white','#fa4'))
    if event=='-BUTTON-+MOUSE OVER+':
        window['-BUTTON-'].update(button_color = ('white','#178acc'))
    if event == '-BUTTON-+MOUSE AWAY+':
        window['-BUTTON-'].update(button_color=('white','#2fa4e7'))
    if event in (None, 'Exit'):
        break
window.close()
```
`,mouseover_colors=('white', "#5f5")`
```py
import PySimpleGUI as sg
sg.theme('Dark Blue 3')
layout = [  [sg.Text('Move mouse over me', key='-TEXT-')],
            [sg.In(key='-IN-')],
            [sg.Button('Move mouse over me', key='-BUTTON-',border_width=0, button_color=('white','#2fa4e7'),font=('sans-serif',14),), sg.Button('Exit')] ]

window = sg.Window('Window Title', layout, finalize=True)
#window['-BUTTON-'].bind('<Enter>', '+MOUSE OVER+')
#window['-BUTTON-'].bind('<Leave>', '+MOUSE AWAY+')

print([e for e in window.element_list() if isinstance(e,sg.Button)])
for e in window.element_list():
    if isinstance(e,sg.Button):
        print(e)
        e.bind('<Enter>', '+MOUSE OVER+')
        e.bind('<Leave>', '+MOUSE AWAY+')
        
i = 0
while True:             # Event Loop
    event, values = window.read()
    print(event)
    if '-BUTTON-' in event:
        i = i+1
        window['-BUTTON-'].update(i,button_color=('white','#fa4'))
    #if event=='-BUTTON-+MOUSE OVER+':
    #    window['-BUTTON-'].update(button_color = ('white','#178acc'))
    #if event == '-BUTTON-+MOUSE AWAY+':
    #    window['-BUTTON-'].update(button_color=('white','#2fa4e7'))
    if '+MOUSE OVER+' in event:
        window[event.removesuffix('+MOUSE OVER+')].update(button_color = ('white','#178acc'))
    if '+MOUSE AWAY+' in event:
        window[event.removesuffix('+MOUSE AWAY+')].update(button_color = ('white','#2fa4e7'))
    if event in (None, 'Exit'):
        break
window.close()
```

[PyInstaller]
---

commande line example : `!pyinstaller -w --onefile --hidden-import=PySimpleGUI MyGUI.py --noconsole --add-binary ./submodule/My.dll;. --icon=app.ico --add-data app.ico;. --clean`

after a `MyGUI.spec` is created and can generate the exe with `pyinstaller --clean MyGUI.spec`

```py
# Code to find the icon
iconPath = sys._MEIPASS + '\\' if 'sys' in dir() and hasattr(sys, '_MEIPASS') else  ''
iconPath += 'app.ico'
```

[Selenium]
---
automate browser

[autoit]: https://pypi.org/project/PyAutoIt/
[deamon]: https://pypi.org/project/python-daemon/
[deamon-linux]: https://janakiev.com/blog/python-background/
[deamon-script]: https://stackoverflow.com/a/49123627
[deamon-windows]: https://stackoverflow.com/a/59125542
[pep448]: https://peps.python.org/pep-0448/
[pandas basic]: https://pandas.pydata.org/docs/user_guide/10min.html?highlight=group
[pandas shift data]: https://towardsdatascience.com/all-the-pandas-shift-you-should-know-for-data-analysis-791c1692b5e
[pprint]: https://docs.python.org/3/library/pprint.html
[pyinstaller]: https://pyinstaller.org/en/stable/usage.html
[selenium]: https://www.selenium.dev/
[subprocess]: https://docs.python.org/3/library/subprocess.html
