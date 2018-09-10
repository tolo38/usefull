

move 
---
<ctrl>+<cmd>+J         jump to definition
<ctrl>+<cmd>+->        pop back to previous context (or go forward)
<ctrl>+<cmd>+^         jump to header (source) file .           (xvim : :nc<CR>)

<cmd>+<~>               switch between windows

refactor
---
<ctrl>+E                add to research field

Menu navigation
---
<cmd>+[1-6]             switch between menus
<cmd>+<alt>+<`>         focus next area
<cmd>+<shift>+F         go to search menu, focus on the researched terme
<cmd>+<shift>+Y         open/close debug area
<cmd>+<alt>+0           open/close file info area

Debug
---
<cmd>+<shift>+o         next step (instruction)
<cmd>+<shift>+i         step into (instruction)



Project
---

when you create a xcode you have a folder "proj" and a file "proj.xcodeproj"
add library with :  right click project "add file to project" 
                    add lib path in "build settings" "search paths"
to add a static library : it is usually another .xcodeproj (do as mentionned above) NOTE : only one .xcodeproj file can be open at a time. 
make it run : "Product" → "Scheme" → "Edit Scheme"
specify main : "build phases" → "compile source"
to use compilation define (frome xcode pref var) : other c flag "-D" followed by FLAGSNAME

rename it : 
[from : https://stackoverflow.com/questions/17744319/duplicate-and-rename-xcode-project-associated-folders]
This answer is the culmination of various other StackOverflow posts and tutorials around the internet brought into one place for my future reference, and to help anyone else who may be facing the same issue. All credit is given for other answers at the end.
Duplicating an Xcode Project

In the Finder, duplicate the project folder to the desired location of your new project. Do not rename the .xcodeproj file name or any associated folders at this stage.

In Xcode, rename the project. Select your project from the navigator pane (left pane). In the Utilities pane (right pane) rename your project, Accept the changes Xcode proposes.

In Xcode, rename the schemes in "Manage Schemes", also rename any targets you may have.

If you're not using the default Bundle Identifier which contains the current PRODUCT_NAME at the end (so will update automatically), then change your Bundle Identifier to the new one you will be using for your duplicated project.

Renaming the source folder

So after following the above steps you should have a duplicated and renamed Xcode project that should build and compile successfully, however your source code folder will still be named as it was in the original project. This doesn't cause any compiler issues, but it's not the clearest file structure for people to navigate in SCM, etc. To rename this folder without breaking all your file links, follow these steps:

In the Finder, rename the source folder. This will break your project, because Xcode won't automatically detect the changes. All of your xcode file listings will lose their links with the actual files, so will all turn red.

In Xcode, click on the virtual folder which you renamed (This will likely be right at the top, just under your actual .xcodeproject) Rename this to match the name in the Finder, this won't fix anything and strictly isn't a required step but it's nice to have the file names matching.

In Xcode, Select the folder you just renamed in the navigation pane. Then in the Utilities pane (far right) click the icon that looks like dark grey folder, just underneath the 'Location' drop down menu. From here, navigate to your renamed folder in the finder and click 'Choose'. This will automagically re-associate all your files, and they should no longer appear red within the Xcode navigation pane.

Icon to click

In your project / targets build settings, search for the old folder name and manually rename any occurrences you find. Normally there is one for the prefix.pch and one for the info.plist, but there may be more.

If you are using any third party libraries (Testflight/Hockeyapp/etc) you will also need to search for 'Library Search Paths' and rename any occurrences of the old file name here too.

Repeat this process for any unit test source code folders your project may contain, the process is identical.

This should allow you to duplicate & rename an xcode project and all associated files without having to manually edit any xcode files, and risk messing things up.

Environment variable
---
Add "User-Defined" Setting with the '+' in "build Settings" to make compilation free from its location
also use "tree targets" in preferces
and var as DYLD_LIBRARY_PATH in "edite scheme"


Note to add OpenCV
---
-include<opencv/...>
-add librairies in "build phases" -> "Link binary with librairies"
-in  "build settings"->"search path" set
    - "library search paths" = .../opencv.../build/lib
    - "Header  search paths" = /usr/local/include

