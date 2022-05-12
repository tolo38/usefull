
# Visual Studio Code (VSC) [Text Editor]

Hotkeys
---

|Keys|Command|Action|Details|
|-|-|-|-|
|Alt+Arrow|Left -> "workbench.action.navigateBack"||
|Ctrl+Alt+Arrow||Add cursor|
|Ctrl+P||Find file|
|Ctrl+Shift+F||Find string in all projet|
|Ctrl+Shift+P||See all commands|
|Ctrl+k Ctrl+k||Key pressed to text|
|Ctrl+/||Comment toggle selected lines|
|"||Surround selection with quote|
|Ctrl+Shift+[||  Fold current region|
|Ctrl+Shift+]||Unfold current region|
||workbench.action.openGlobalKeybindings|See all commands and shortcut bindings (in settings)|[vscode keybindings customization]
||workbench.action.openDefaultKeybindingsFile|See all commands and shortcut bindings (in JSON file)|
||workbench.action.openGlobalKeybindingsFile|See edited shortcut bindings (in JSON file)|
|**Modified**
|Ctrl+j Ctrl+k||toggleVim|enable/disable VimPlugin| if vscodevim installed. Not neovim.
|Ctrl+l||Clean output window if focused| when clause : `focusedView == 'workbench.panel.output'` [edite when clause]
|[More key bindings]

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



[vscode keybindings customization]: https://code.visualstudio.com/docs/getstarted/keybindings#_advanced-customization
[More key bindings]: https://code.visualstudio.com/docs/getstarted/keybindings#_basic-editing
[edite when clause]: https://code.visualstudio.com/api/references/when-clause-contexts
