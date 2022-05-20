
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

### With Shortcut and uninstaller

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

### More

**Can NSIS install as silent automate?**
Have a look to `silent` [option]  

**Can NSIS automate another installer?**
What you're looking for is [AUTOIT]

[AUTOIT]: https://www.autoitscript.com/site/autoit/
[NSIS Full Tutorial]: https://nsis.sourceforge.io/Docs/
[NSIS Simple Tutorial]: https://nsis.sourceforge.io/Simple_tutorials
[option]: http://unattended.sourceforge.net/installers.php
[wikipedia]: https://en.wikipedia.org/wiki/Nullsoft_Scriptable_Install_System
