#Latex

To Compile latex to pdf
 ```
pdflatex
```
If necessary install with ```sudo apt-get install texlive``` 
 
  make it lighter
  ```
 gs -sDEVICE=pdfwrite -dCompatibilityLevel=1.4 -dNOPAUSE -dQUIET -dBATCH -sOutputFile=foo-compressed.pdf foo.pdf
```
