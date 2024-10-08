
# Visual Studio Code (VSC) [Text Editor]

<details><summary>
  
Hotkeys
---
</summary>
  
|Keys|Command|Action|Details|
|-|-|-|-|
|Alt+Arrow|Left -> "workbench.action.navigateBack"||
|Ctrl+P||Find file|
|Ctrl+Shift+F||Find string in all projet|
|Ctrl+Shift+P||See all commands|
|Ctrl+k Ctrl+k||Key pressed to text|
|Ctrl+Alt+Arrow||Add cursor|
|Ctrl+d||add cursor to next matching pattern|
|Ctrl+/||Comment toggle selected lines|
|"||Surround selection with quote|
|Ctrl+Space||Snippets|
|Ctrl+Shift+\\ |editor.action.jumpToBracket| jump to closing brace|
|Ctrl+Shift+[||  Fold current region|
|Ctrl+Shift+]||Unfold current region|
|Ctrl+K Z|workbench.action.toggleZenMode|Zen Mode|to fix conflict with VIM `"vim.handleKeys": {"<C-k>": false},`
||
||workbench.action.openGlobalKeybindings|See all commands and shortcut bindings (in settings)|[vscode keybindings customization]
||workbench.action.openDefaultKeybindingsFile|See all commands and shortcut bindings (in JSON file)|
||workbench.action.openGlobalKeybindingsFile|See edited shortcut bindings (in JSON file)|
|**Modified**
|Ctrl+j Ctrl+k||toggleVim|enable/disable VimPlugin| if vscodevim installed. Not neovim.
|Ctrl+l||Clean output window if focused| when clause : `focusedView == 'workbench.panel.output'` [edite when clause]
|Alt+h (Alt+l)||Move the selection to left (right)|
|Alt+o|| toggle header/source C++|
|[More key bindings]

 </details>
  
<details><summary> keybindings.json </summary>

```json
// Place your key bindings in this file to override the defaults
[
  {
    "command": "vscode-neovim.compositeEscape1",
    "key": "j",
    "when": "neovim.mode == insert && editorTextFocus",
    "args": "j"
  },
  {
    "command": "vscode-neovim.compositeEscape2",
    "key": "k",
    "when": "neovim.mode == insert && editorTextFocus",
    "args": "k"
  },
  {
    "key": "ctrl+j ctrl+k",
    "command": "toggleVim"
  },
  {
    "key": "ctrl+l",
    "command": "workbench.output.action.clearOutput",
    "when": "focusedView == workbench.panel.output"
  },
  {
    "key": "shift+backspace",
    "command": "deleteRight",
    "when": "textInputFocus"
  },
  {
    "key": "delete",
    "command": "-deleteRight",
    "when": "textInputFocus"
  },
  {
    "key": "alt+h",
    "command": "editor.action.moveCarretLeftAction",
    "when": "editorTextFocus && editorHasSelection"
  },
  {
    "key": "alt+h",
    "command": "cursorLeft",
    "when": "editorTextFocus && !editorHasSelection"
  },
  {
    "key": "alt+l",
    "command": "editor.action.moveCarretRightAction",
    "when": "editorTextFocus && editorHasSelection"
  },
  {
    "key": "alt+l",
    "command": "cursorRight",
    "when": "editorTextFocus && !editorHasSelection"
  },
  // Toggle between terminal and editor focus
  {
    "key":     "ctrl+`",
    "command": "workbench.action.terminal.focus"
  },
  {
    "key":     "ctrl+`",
    "command": "workbench.action.focusActiveEditorGroup",
    "when":    "terminalFocus"
  },
]
```
</details>

Extentions
---
` code --list-extensions`
```
asvetliakov.vscode-neovim
cschlosser.doxdocgen
hbenl.vscode-test-explorer
IBM.output-colorizer
jeff-hykin.better-cpp-syntax
matepek.vscode-catch2-test-adapter
ms-vscode-remote.remote-containers
ms-vscode-remote.remote-ssh
ms-vscode-remote.remote-ssh-edit
ms-vscode-remote.remote-wsl
ms-vscode.cmake-tools
ms-vscode.cpptools
ms-vscode.cpptools-extension-pack
ms-vscode.cpptools-themes
ms-vscode.test-adapter-converter
peterj.proto
twxs.cmake
vscodevim.vim
```

Here is a list of helpful extantions to code, commpile and execute C++/CMake project :

- [cschlosser.doxdocgen](https://marketplace.visualstudio.com/items?itemName=cschlosser.doxdocgen)
- [jeff-hykin.better-cpp-syntax](https://marketplace.visualstudio.com/items?itemName=jeff-hykin.better-cpp-syntax)
- [ms-vscode.cmake-tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)
- [ms-vscode.cpptools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
- [ms-vscode.cpptools-extension-pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack)
- [ms-vscode.cpptools-themes](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-themes)
- [ms-vscode.hexeditor](https://marketplace.visualstudio.com/items?itemName=ms-vscode.hexeditor)
- [twxs.cmake](https://marketplace.visualstudio.com/items?itemName=twxs.cmake)

You can install all of the listed extentions with the following commands

```sh
code --install-extension cschlosser.doxdocgen
code --install-extension jeff-hykin.better-cpp-syntax
code --install-extension ms-vscode.cmake-tools
code --install-extension ms-vscode.cpptools
code --install-extension ms-vscode.cpptools-extension-pack
code --install-extension ms-vscode.cpptools-themes
code --install-extension ms-vscode.hexeditor
code --install-extension twxs.cmake
```
The previous list has been autogenerated from following command line
```sh
 code --list-extensions | xargs -I{} printf "- [%s](https://marketplace.visualstudio.com/items?itemN
ame=%s)\n" {} {}
code --list-extensions | xargs -L 1 echo code --install-extension
```

### [Regex]

```
# find float -> turn it to double
([0-9])\.?f
$1.0
# clean
([0-9](\.|e\+|e-)[0-9]+)0*(\.0)?
([0-9]\.[0-9]+)0*(\.0)?
([0-9]e\+[0-9]+)0*(\.0)?
([0-9]e-[0-9]+)0*(\.0)?
$1

# find number with pending comma -> add one 0 after comma
([0-9]\.)([^0-9])
$10$2

# find numbers-> remove trailling 0 
(\d\.(\d*[1-9]|0))0+
$1
# better
(\d\.(\d*[1-9]|0))0+([^\d])
$1$3
```

### Terminal

#### History

VSCode terminal use external shell. For linux the default shell is bash, For window, the default shell for window is powershell.
Find the history at `$env:APPDATA\Microsoft\Windows\PowerShell\PSReadLine\ConsoleHost_history.txt` or run :
```sh
Get-PSReadlineOption
```
More details at [powershell-history](https://0xdf.gitlab.io/2018/11/08/powershell-history-file.html)


#### Debugging

Using **watch** is useful especially when pinning structure [leaves elements](https://stackoverflow.com/questions/18057566/visual-studio-watch-member-of-structure-in-an-array)



[vscode keybindings customization]: https://code.visualstudio.com/docs/getstarted/keybindings#_advanced-customization
[More key bindings]: https://code.visualstudio.com/docs/getstarted/keybindings#_basic-editing
[edite when clause]: https://code.visualstudio.com/api/references/when-clause-contexts
[Regex]: https://learn.microsoft.com/en-us/visualstudio/ide/using-regular-expressions-in-visual-studio?view=vs-2022
