Exiftool
---

let you manipulate picture metadata including exif data
those data are part of the picture, it contains information about 
time, location, and many other details of the picture context.

### list tags

``` exiftool . ```
list all tags for all picturs in current directory
``` exiftool -s -G pic.jpg ```
    --s means instead of showing the "friendly" names like "Create Date", show the names you need to use when you write ExifTool commands. So instead of "Create Date" you see "CreateDate".
    --G means also show the metadata Group to which the metadata tag belongs.

### filter by extention
``` exiftool -ext jpg ```
the commande will be proced only on *.jpg files

### write tag value
``` exiftool -author=name ```
will set the author field value to "name"
``` exiftool -camera= ```
will delete the value for camera, as no value is assigned to it
   
it is alse possible to set value from an other field using <
``` exiftool '-author<camera' '-author=me' ```
here author will be take camera value if it exist else it will be set to "me" (conditionnal affectation)

### rename, move or copy (file, directory)
`
exiftool -r -progress -ext jpg '-FileName<gpsdatetime' '-FileName<DateTimeOriginal' '-FileName<CreateDate' '-FileName<FileModifyDate' -d %Y/%m_%B/%Y_%m_%d__%H_%M_%S%%-c.%%e .
`
here the ```filename``` variable is not a tag but the file name. however it works the same way, its value will conditionnaly set to ```gpsdatetime``` or ``` datetimeorigine``` and follows, if tag exist
--r stands for recurcively (the dote at the end means current folder)
--progress require the commande to show the number of file processed during execution.(it is possible to couple with zenity to have graphical progress bar)
--d is for date formating according to FMT (```man strftime``` for more information)

### create custom tags
to use custom tags, first write a configuration file like ```conf```
```
%Image::ExifTool::UserDefined = (
	'Image::ExifTool::XMP::xmp' => {
		NewXMPxmpTag => { Groups => { 2 => 'Author' } },
    },
);
```
and then call the config file to set your new tag (afterward the tag can be freely modified, without the config file)
``` exiftool -config conf -XMP-xmp:NewXMPxmpTag="cool" test.jpg ```


### create custom namespace


### tmp-link
https://stackoverflow.com/questions/24416653/is-it-possible-to-create-a-custom-namespace-tag-in-xmp-dublin-core-metadata

https://stackoverflow.com/questions/29779144/how-can-i-embed-metadata-into-a-custom-xmp-field-with-exiftool

### Link

https://exiftool.org/faq.html
https://exiftool.org/config.html
https://exiftool.org/filename.html
https://ninedegreesbelow.com/photography/exiftool-commands.html

