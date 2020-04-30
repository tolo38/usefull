renommage_cours_png name num_debut
renommage_cours_tif name num_debut





GIMP
gimp -i -c -b 'commande'
avec commende qui renvoie un scripte lisp

IMAGE-MAGIC
recherche : changer la résolution dpi
la taille h*l
le nombre de couleur

http://www.commentcamarche.net/faq/6120-imagemagick-manipuler-les-images-en-ligne-de-commande
convert -units PixelsPerInch image -density 300 resultimage
convert maphoto.jpg -resize 800x600 -strip -quality 50 -interlace line imageweb.jpg

->convert image.jpeg -resize 823x1166 -interlace line imageweb8.jpg

question ??????????????????????
pourquoi moins de couleur plus lourd ?

SITE : http://softlibre.gloobe.org/imagemagick/options
convert -colors [value]
convert -colorspace {CMYK;GRAY;HSL;...}





meilleur ************
scanner en COULEUR rend un meilleur résultat a la relecture -> on cherchera a compresser :
convert image.jpeg -resize 850x2000 -interlace line -colors 128 imageweb.jpeg


QUESTION :
entré : JPEG/tif
sortit : png/gif

reponnse 1: jpeg plus leger mais moin beau en sortit du scan

convert image.png -background #ffffff -layers merge image.png

reponse 2 : le forma gif est prévu uniquement pour des annimations si ce n'est pas le cas un png sera toujours plus leger (à résolution et coloration égale)

reponse 3 : aprés convertion en PNG-8 les tif sont non seulement de meilleurs qualité mais en plus plus léger.

R2SULTAT:
entré : tif
sorti : png


test_format_entree/README 
les doc de départ tif sont deux fois plus lourd que les doc jpeg mais sont plus jolie

teste_resolution_jpeg/README
toute les images sont obtenu par la commende "convert"
la resolution es visible en ouvrant limage
par défaut l'image de départ est toujours image.jpeg qui vient de original avec un changement de résolution.

-interlace line : améliore la compression

test_format_sortie/README
convert *.jpeg *.gif
convrt *.jpeg *.png
convert *.jpeg PNG8:*.png
convert *.jpeg -colors 8 PNG8:*.png
convert *.jpeg -colors 256 PNG8:*.png
convert *.jpeg *.jpeg


