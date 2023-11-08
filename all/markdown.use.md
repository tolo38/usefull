
Markdowm
---

[Cheatsheet]

[Github-Extended]

[Gitlab-Flavoured]


[Cheatsheet]: https://github.com/adam-p/markdown-here/wiki/Markdown-Here-Cheatsheet
[Github-Extended]: https://www.markdownguide.org/extended-syntax/
[Gitlab-Flavoured]: https://docs.gitlab.com/ee/user/markdown.html

[**Asciidoctor**](./asciidoctor.use.adoc)

#### Line breaks

Just add two space  
at the end 
of the line

or use `\` \
to jump to a new line

#### to make a title
```
Markdown (H2)
---
# H1
## H2
### H3
```
# H1
## H2
### H3

#### to have a tab like follow
|||
|-|-|
||
```
|||
|-|-|
||
```
#### to insert code
```
    ``` 
    type your code here
    here the four space help to escape `
    ```
```
- Hilighted code
```C
```C
#include <stdio.h> 
main( ) { 
    printf("hello, world\n"); 
} 
    ```
```


#### hyperlink
```
[title](http://page.com)
[link]
[link]: http://targer.io
[link][id]
[id]: http://alias-link.com
```

#### Quote
>**Title** \
>block quote
```>block quote```

#### Comment
[//]: # (This may be the most platform independent comment)
```md
[//]: # (This may be the most platform independent comment)
```


#### Collapsible section
<details><summary>Click to expand</summary>
*Content*
</details>

```html
<details><summary>Click to expand</summary>
*Content*
</details>
```


#### Strikeout
<s>text</s> `<s>text</s>` \
~~text~~  `~~text~~`

#### Symboles

&emsp;(tabulation) `&emsp;`

##### Arrows
&#8592; `&#8592;`  
&#8593; `&#8593;`  
&#8594; `&#8594;`  
&#8595; `&#8595;`  
<kbd>&uarr;</kbd> `<kbd>&uarr;</kbd>`  
more [Arrows] 

[Arrows]: https://stackoverflow.com/questions/54954544/how-do-i-show-the-up-and-down-arrow-keyboard-key-in-github-markdown

#### [Emoji]

:grinning:	:smiley: :smile:	:grin:
:laughing: :satisfied:	:sweat_smile:
:rofl:	:joy:	:slightly_smiling_face:	
:upside_down_face:	:wink:	:blush: :innocent:

[Emoji]: https://github.com/ikatyang/emoji-cheat-sheet/blob/master/README.md


#### CSS stryle

Following codes works localy but not on gitlab or github

```markdown
    <style>
    .language-html:before {
        content: "\1F4C1";
    }
    .language-py:before {
        content: "\00BB";
    }
    </style>
    ```html
    test
    ```
    ```py
    test
    ```
```


