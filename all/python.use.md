

interpretor
---

```sh
python -c "import tkinter as tk; tk.Tk().mainloop()"
```


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

- To check the existence of a variable:
```py
if 'myVar' in locals():
```
```py
if 'myVar' in globals():
```
- To check if an object has an attribute:
```py
if hasattr(obj, 'attr_name'):
  # obj.attr_name exists.
```

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
d = {"key":value,"k2":v2}
d= dict(k1=v1,k2=v2)
for k, v in knights.items():	#loop with k and v
pairs.sort(key=lambda pair: pair[1]) #cool : permet de trier en indiquant la position de la clé
call(**arg_dict) # it is possible to make a function call with a dictionary as input if its keys correspond to existing argument of the function to call
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

Logging and Error managment
---
With the following code you allways find your out put text: it is waitting for you in `/tmp`
```py
try:
    #code here
except Exception as error:
    # handle the exception
    f = open("C:/tmp/TLO.log", "a") 
    f.write("An exception occurred: "+str(error))
    f.close()
```
:warning: Juste remeber to create that folder if it does not exist yet. :warning:

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

- function is a object so it is easy to add it fields attribute :
```py
def a():
	a.wasCalled=True
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

Pychache
---

Running python generate caching files in `__pychache__` folder to optimise exectision time.

:warning: For development : it ia possible that those did not get updated dispate some source modification

* one option to avoid it :
```sh
python -B
```


Package
---

### Virtual environement (venv)

important to isolate each python projects
and limit dependencies update conflict
(update that would break older project)

```sh
python -m venv venv
venv\Scripts\activate
deactivate
```
```sh
python -m pip freeze > requirements.txt # deprecated use pipreqs
pipreqs ./path # instead of freeze
python -m pip install -r requirements.txt
```
Note : `python -m ...` ensure that we call the right version(from the activated venv) of pip,venv,...

### Poetry

* install :
```sh
python -m pip install pipx
pipx install poetry
```
check
```sh
poetry --version
```
if necessary update path
```sh
$env:PATH += "C:\Users\<>\.local\bin\"
```



* To create package once can use [poetry](https://python-poetry.org/docs/basic-usage/) :

```sh
poetry init .
```
it auto generate the initial project architecture and `.toml` file meant to configure project metadata

* set up

```sh
poetry install
```

* build the package

```sh
poetry build -f wheel
```

* (more)
```sh
poetry env
poetry env remove
poetry env list
poetry add --group dev black
poetry add --group dev ipykernel==5.5.6
```

* publish

```sh
poetry run python -m pip install twine
poetry run twine upload --repository-url https://git.com/api/v4/projects/1004/packages/pypi -u gitlab+deploy-token-# -p pass*** .\dist\*

```

* More : with [Dynamic versioning plugin for Poetry](https://github.com/mtkennerly/poetry-dynamic-versioning)
it can be directly installed in the `gitlab-ci.yml` with the line 

```yml
default:
  tags:
    - WINDOWS
  before_script:
    - py -3 -m venv .venv
    - .\.venv\Scripts\activate
    - python -m pip install --upgrade pip
    - python -m pip install poetry==1.5.1
    - poetry --version
    - poetry self add "poetry-dynamic-versioning[plugin]"
    - poetry install
```

other option :
* [Python project](https://packaging.python.org/en/latest/tutorials/packaging-projects/)
/ [Python build](https://pypa-build.readthedocs.io/en/stable/index.html)
`python -m build`
* [setup.py](https://medium.com/analytics-vidhya/how-to-create-a-python-library-7d5aea80cc3f)
`python setup.py bdist_wheel`


Deploy Zip
---

### [Application](https://gist.github.com/asimjalis/4237534)

```sh
python -m zipapp project -p "/usr/bin/env python"
```

or 
```sh
#! /bin/bash


<<**-**

Create a file __main__.py containing:

print "Hello world from Python"
Zip up the Python files (in this case just this one file) into app.zip by typing:

zip app.zip *
The next step adds a shebang to the zip file and saves it as app—at this point the file app is a zip file containing all your Python sources.

echo '#!/usr/bin/env python' | cat - app.zip > app
chmod 755 app
That’s it. The file app is now have a zipped Python application that is ready to deploy as a single file.

You can run app either using a Python interpreter as:

python app
Or you can run it directly from the command line:

./app

**-**

zip app.zip __main__.py
echo '#!/usr/bin/env python' | cat - app.zip > app
rm app.zip
chmod 755 app
```

### [Library](https://realpython.com/python-zip-import/)

* create de zip lib
```sh
zip lib.py
```

* use it

```py
import site

print(site.getusersitepackages())

import sys
print('\n'.join(x for x in sys.path if x))

# introspect, current dyrectory script version
print(sys.path) #[0]
print(sys.executable)
print(os.getcwd())

import lib

# if import lib faild (concidering lib.zip being in the current folder)
sys.path.insert(0, "./lib.zip")

import lib

lib.Hi()
```

* (add it to the path)

create a file `lib-name.pth` in folder part of `site` :
in windows (with python 3.10) `C:\Users\<>user\AppData\Roaming\Python\Python310\site-packages\lib-name.pth`.

It contains the path to the lib.zip

Threading
---
```py
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
[PySimpleGUI]
---
- [PySimpleGUI-more]

Install :
```sh
python -m pip install pysimplegui
```

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
- [multiline text colored]https://github.com/PySimpleGUI/PySimpleGUI/issues/2547)
- [bind to tkinter event](https://docs.pysimplegui.com/en/latest/documentation/module/extending/event_bindings/)
```py
window.bind('<TKINTER EVENT>', 'STRING TO APPEND')
```



tkinter
---
```py
# importing tkinter for gui
import tkinter as tk

def flash(color='#00aaaa'):
    # creating window
    window = tk.Tk()

    # setting attribute
    window.attributes('-fullscreen', True)
    window.attributes('-topmost', True)
    window.configure(bg=color)

    # Create transparent window
    window.attributes('-alpha',0.5)

    window.title("Flash")

    # timer thread function call here in 1s to close the window
    window.after(1000,window.destroy)

    window.mainloop()
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
[pysimplegui]: https://www.pysimplegui.org/en/latest/#pattern-2-b-persistent-window-multiple-reads-using-an-event-loop-updates-data-in-window
[pysimplegui-more]: https://www.tutorialspoint.com/pysimplegui/pysimplegui_checkbox_element.htm
[selenium]: https://www.selenium.dev/
[subprocess]: https://docs.python.org/3/library/subprocess.html
