
# Nullsoft Scriptable Install System

[NSIS Simple Tutorial]

[NSIS Full Tutorial]

### Simple Installer

```nsis
!include "MUI.nsh"

!define MUI_ABORTWARNING # This will warn the user if they exit from the installer.

!insertmacro MUI_PAGE_WELCOME # Welcome to the installer page.
!insertmacro MUI_PAGE_DIRECTORY # In which folder install page.
!insertmacro MUI_PAGE_INSTFILES # Installing page.
!insertmacro MUI_PAGE_FINISH # Finished installation page.

!insertmacro MUI_LANGUAGE "English"

Name "MyApp" # Name of the installer (usually the name of the application to install).
OutFile "MyAppInstaller.exe" # Name of the installer's file.
InstallDir "$PROGRAMFILES\MyApp" # Default installing folder ($PROGRAMFILES is Program Files folder).
ShowInstDetails show # This will always show the installation details.

Section "MyApp" # In this section add your files or your folders.
  # Add your files with "File (Name of the file)", example: "File "$DESKTOP\MyApp.exe"" ($DESKTOP is Desktop folder); or add your folders always with "File (Name of the folder)\*", always add your folders with an asterisk, example: "File /r $DESKTOP\MyApp\*" (this will add its files and (with /r its subfolders)).
SectionEnd
````
From [wikipedia]

### Basics
Installation is achieved by a succesion of pre made **pages** (ex : `!insertmacro MUI_PAGE_FINISH`)

Installation and pages behavior can be modified pre defined **variable** (ex : `$INSTDIR`)

and **function** (ex : `.onInit` -> it is automatically called)

Installation details are implemented in **section**

### [Variable] and const
use var instead of define
not set at the same time
define are somehow const
it is not called the same way $var instead on ${Defined}

var can be set
```nsis
StrCpy $var0 "empty"
```

### Installer With Shortcut and uninstaller

```nsis
# define name of installer
OutFile "InstallMyApp"
 
# define installation directory
InstallDir $LOCALAPPDATA\Programs\myapp
 
# For removing Start Menu shortcut in Windows 7
RequestExecutionLevel user
 
# start default section
Section
 
    # set the installation directory as the destination for the following actions
    SetOutPath $INSTDIR
 
    # create the uninstaller
    WriteUninstaller "$INSTDIR\uninstall.exe"
 
    # point the new shortcut at the program uninstaller
    CreateShortcut "$SMPROGRAMS\My App.lnk" "$INSTDIR\myapp.exe"
    CreateShortcut "$SMPROGRAMS\My App Uninstall.lnk" "$INSTDIR\uninstall.exe"

    File /r "C:\path\to\where\my\files\are\*"

SectionEnd
 
# uninstaller section start
Section "uninstall"
 
    # first, delete the uninstaller
    Delete "$INSTDIR\uninstall.exe"
 
    # second, remove the link from the start menu
    Delete "$SMPROGRAMS\My App.lnk"
    Delete "$SMPROGRAMS\My App Uninstall.lnk"
 
    Delete $INSTDIR

# uninstaller section end
SectionEnd
```
From [wikipedia]


### Input Parameters with getOptions
Installers can also take arguments so it can be called with options (from Execwait , or shortcut , or cmdline)
```nsis
setup.exe /MY_OPT "input content to pass to option:
```

inside NSIS script option is retrieved as follow :
```nsis
!include "FileFunc.nsh" # To use GetParameters
!insertmacro GetOptions


var var0 #define a variable called var0

Function .onInit
   ${GetOptions} $CMDLINE "/MY_OPT" $var0
FunctionEnd
```


### Call installer
```nsis
!define API_TUTORIAL_INSTALLER_FILE_NAME       'setupMe.exe'
 ExecWait '"${API_TUTORIAL_INSTALLER_FILE_NAME}" /MY_OPT ${SHORTCUT_DIRECTORY}'
 ```

### Control flow

```nsis
function .onInit
  ${GetOptions} $CMDLINE "/SHORTCUT_DIRECTORY" $SHORTCUT_DIRECTORY
  ${If} $SHORTCUT_DIRECTORY == ""	
    StrCpy $SHORTCUT_DIRECTORY "$SMPROGRAMS"
  ${EndIf}
  StrCpy $SHORTCUT_DIRECTORY "$SHORTCUT_DIRECTORY\${SOFTWARE_NAME_FULL_VERSION}"
```


### Check Folder
how to verify a folder, alert user before continuation and allows to change instead of jumping to the next page


```nsis
!include "MUI2.nsh" ;Include Modern UI


; The file to write
OutFile 'setupMe.exe'

; The default installation directory
InstallDir "C:\tmp"


!include "nsDialogs.nsh"
var TEXT_DIR_DEST 
var hwnd
var dialog


Page Custom pre

!define MUI_DIRECTORYPAGE_TEXT_DESTINATION $(TEXT_DIR_DEST)
!define MUI_PAGE_CUSTOMFUNCTION_LEAVE CheckInstallationDirectory
!insertmacro MUI_PAGE_DIRECTORY 
!insertmacro MUI_PAGE_FINISH

Function .onVerifyInstDir
    ;MessageBox MB_ICONEXCLAMATION "$TEXT_DIR_DEST"
    ;StrCpy $TEXT_DIR_DEST "The selected directory is not empty!\n It might erase current files. we recommend to chose another directory."
FunctionEnd

Function pre
nsDialogs::Create 1018
    Pop $dialog
    ${NSD_CreateLabel} 0 0 100% 20% "This line will be centered.$\nAnd so will this line."
    Pop $hwnd
    ${NSD_AddStyle} $hwnd ${SS_CENTER}
    nsDialogs::Show
FunctionEnd

Function CheckInstallationDirectory
    ; Check if the selected directory is not empty
    IfFileExists "$InstDir\*.*" directoryNotEmpty
    Goto leave
directoryNotEmpty:
    ; Directory is not empty, warn the user probably they want to choose another directory
    ;MessageBox MB_YESNO|MB_ICONEXCLAMATION "The selected directory is not empty. It might erase current files. we recommend to chose another directory." IDNO leave
    MessageBox MB_YESNO|MB_ICONEXCLAMATION "The selected directory is not empty. It might erase current files. We recommend to choose another directory.$\n$\nWould you like to change installation directory?" IDNO leave
    Abort
leave:
FunctionEnd

Section "MyApp"
SectionEnd

LangString TEXT_DIR_DEST ${LANG_ENGLISH} "Please select Installation Directory"
```


---

### More

**Can NSIS install as silent automate?**
Have a look to `silent` [option]  

**Can NSIS automate another installer?**
What you're looking for is [AUTOIT]

[AUTOIT]: https://www.autoitscript.com/site/autoit/
[NSIS Full Tutorial]: https://nsis.sourceforge.io/Docs/
[NSIS Simple Tutorial]: https://nsis.sourceforge.io/Simple_tutorials
[option]: http://unattended.sourceforge.net/installers.php
[Variable]: https://documentation.help/CTRE-NSIS/Section4.2.html
[wikipedia]: https://en.wikipedia.org/wiki/Nullsoft_Scriptable_Install_System
