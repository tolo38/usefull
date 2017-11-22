vec4
	en programation GPU opération parallélisé pour les vec4
	donc même temps d'execution pour float+float ou vec4+vec4

	vec4 : x,y,z,w (coordonné carthésienne + astuce math)
	w : est une astuce qui permet de gerer point et vecteur dans un espace vectoriel
	point -> w!=0  / vecteur -> w=0
	point-point = vecteur
	Attention à la normalisation (w=1)


Bug peux rester cacher si on utilise que des rotation 
	Attention toujours utiliser la co-matrice (meme si elle est égual à elle-meme)


Texture
	les shader n'a connaissance que du numero de la texture_unit
	du coup il faut aussi racorder la texture_unit a une texture
	en CPU la texture a deux numero (textureID, Texture_unit)

ne jamais utilisé atan(y/x) mais atan(y,x)


Vertex Shader
---
	enssemble de sommet


Fragment Shader
---

Geometry Shader(optional)
---
	Permet la création de primitive, de les remplasser, les supprimer à volonté
	V-> cool
	X-> impacte (non linéaire) sur les performances

Tesselation Shader(optional)
---
	in : points de control
	out : patch "lissé" avec le nombre de point souhaité
	V->facil à optimiser

	Tesselation Control Shader(optional)
	---

Multipass rendering + Frame Buffer Object
---
	permet d'utiliser des rendus comme texture sans passer par le cpu.
	
Compute Shader
---
	in : Shader Storage Buffer Objct(only vec4) + texture uniforme
	out : Image
	Related to memory access (who & how) 
		writeonly/readonly simpler 
		coherent : every instance sees same value, after barrier() (r/w) 
		volatile: value can change anytime (r/w) 
		restrict: this variable is the only one to access this memory 
			Combine if it makes sense. restrict as much as you can.
	->syncronisation des works groupe(enssemble de thread)
		work group : defini dans GPU communique plus facilement (nb de thread) + barrier() implissite
		Grid : defini dans le CPU (nb de work groupe)
		memoryBarrier() : force le flush (ecriture des valeurs) seulement sur "coherent" [faire avant barrier()]

	Help to debug: 
		glm:https://glm.g-truc.net/0.9.8/index.html
		Write GLSL code in C++, debug in C++, transfer to GLSL



glm
---
#include "glm/ext.hpp" -> glm::to_string(GenType)
