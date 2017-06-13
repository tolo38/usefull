
# Maya
___

menu
---
||||
|-|-|-
|Z/shit+Z|		|undo/redo


view
----
||||
|-|-|-
|alt+click|			|rotate view (click wheel : translate) (left : Zoom)
|spacebar|			|switch between Panek layout and Four view layout (orthographic view access)
|4| 				|wirefram view
|5|	    			|shaded view
|6|	    			|textured view



selection
----
||||
|-|-|-
|click|				|select
|long right click|		|change the selection mode
|ctrl+shift+click|		|add to selection
|double click(edge mode)|		|loop selection
|ctrl+click|			|remove from the selection
|b|				|soft select

modeling scene
----
||||
|-|-|-
|q,w,e,r,t|			|select,translate,rotate,scale,normal dragging (see the result in chanelBox)
|wheel click|			|choose the direction
|j hold|			|discrete move
|y|				|last tool
|ctrl+d|			|duplicate
|alt+arrows|			|move by pixel
|insert/d|			|move pivot point


modeling object
----
||||
|-|-|-
||              |extrude region
|hold right click -> slide edge tool|	        |interactive split tool

|F8|						|switch between Objet and Component mode

outline
---
||||
|-|-|-
|Window -> Outliner|				|show the scene tree
|ctrl+G|					|group
|p|						|parent
|arrows|					|move selection inside the tree
|click wheel|					|move object inside the tree


node editor
---
||||
|-|-|-
|1,2,3,4|					|change view
|Tab|						|add new node
|click drag|					|create connection
|ctrl+ wheel click drag|			|create defqult connection
Note :
pour pouvoir editer la matiere d'un object il faut trouver sont *surfaceShader* dans *AttributeEditor*
Ou dans le *NodeEditor* select the *surfaceShader* and click on *InputConnection* : >[]
Pour commencer il faut ajouter un materiaux : right click hold -> add material (or on a node : Assign material to viewport material)
Think to check : witch is the material assignated to your shape !

Animate
---
switch the self to *Animate*
s	(Animate->Set Key)					adds key points that the animation  follows
set the number of frame					in general 24fps (frame per second) is okay
add a camera (create->camera)							To not destroy your animation each time you juste look arround the scene
create a path(curves) + select both path and camera + "link" 	create a path that the camera will follow
set camera as presp if you want to see the result (in View:Panels->prepective)		think to change back before moving in the scene (it will affect the next rendered movie)
Note : Easier to have better result by just moving the shapes instade of the camera.

Skeleton
-----
switch the self to *Animate*
*skeleton*->Join Tool				add all the join Then use the Hypergraph or the outliner to manage the hierarchie
*skeleton*->HumanIK					help to build a human skeleton
*skin*->smoothBind					(select body and skeleton with shift) this bind the skin on the skeleton
insert								move only the selected joints and not all the hierarchie
*Shading*->X-Ray Joints				allow you to see joints inside the shaded form
launch character controler

HumanIK
----
*Create a skeleton
*resize it
*make it fit to the character
*bind smooth to the skin
if needed miroring left to right : 
in *Character Controle Menu* -> Edite -> Skeleton 
*add control rig
*Animate->Widows->General->Visor ... mocape exemple
change source to loaded animation
in *Character Controle Menu* -> Bake -> to control Rig



Rendering
---
switch the self to *Rendering*
Widows->Rendering Editors->Render Settings				To Set [image rendering ->file type = .png + number of frame]
scripte editor		(low right corner)					To see the rendering involve
Render-> batch Render									To throw the rendering
log file												If their is an unexpected issue
(low right corner) PropertyWindows						let you set the Fps rating

plug-in
---
the plug-in mamager menu is in *Window* -> *Settings/preference* -> plug-in mamager
then you can browse for or .mll
add the result in the rendiring available plug-in (maya folder...)



|ctrl+hold right click|
|shift+hold right click|
