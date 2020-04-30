## Identify keyboard ID
Find the ID of the keyboard with its name
```
lsusb
```
- Find matching ID and isolate the handlers name
- Find product and vendors we will use in the `/etc/udev/hwdb.d/61-Cherry-keyboard.hwdb`
```
cat /proc/bus/input/devices
```

## Create new hardware map file
For now we don't have the keyboard scancodes nor the keycodes
The first line is : `evdev` is an event, `b` is bus (0003 for a keyboard), `v` is the vendor, `p` is the product.
Be careful to keep the space before the variables.
```
evdev:input:b0003v046Ap0001*
 FOO=1
```

## Check if first line well parsed
```
systemd-hwdb query evdev:input:b0003v046Ap0001*
```

## Grep if keyboard well detected
Then put that in the hwdb file
```
evdev:input:b0003v046Ap0001*
 FOO=1
```
And run
```
udevadm info /sys/class/input/event6 | grep FOO
```

## Add keyboard key remap
```
 KEYBOARD_KEY_<scancode>=<keycode> 
```
with the scancode the hexadecemal obtained with showkey
and the keycode an lowcase string corresponding to the key(see key event)
without space arround the = sign
```
evdev:input:b0003v046Ap0001*
 KEYBOARD_KEY_38=leftmeta               #Ins : use windows when get alt
 KEYBOARD_KEY_56=leftalt                #Alt : use leftalt when get <>
 KEYBOARD_KEY_e0=102nd                  #<>  : use <>      when get Ins
```
And `grep KEYBOARD_KEY` to check the keyboard vars

NOTE : the best to obtaine scancodes (and keycodes) is to install and use evtest
here [fist line] scancode=value <> and [seconde line] keycode=code <> (KEY_<>)

## Check keycodes in virtual console 
Tips: change tty
Shortcut: Ctrl-Alt F1 (and Ctrl-Alt-F7 to go back to xserver)
```
showkey --scancodes	# Hexa nb scancodes = signal kb
showkey --keycodes	# Give the keycode nb mapped on that key
```




## Verify remapping
```
udevadm info keyboard
```

## Update and trigger
```
sudo systemd-hwdb update
sudo udevadm trigger
```


## Sources
https://yulistic.gitlab.io/2017/12/linux-keymapping-with-udev-hwdb/

https://askubuntu.com/questions/877404/how-to-remap-xf86sleep-key-to-space-xmodmap-xkbcomp-udev-fail

http://blog.ssokolow.com/archives/2017/04/10/getting-your-cheap-chinese-usb-foot-pedal-doing-useful-things-on-linux/

http://atsui.wikidot.com/evtest-output

https://github.com/systemd/systemd/issues/4750

https://wiki.archlinux.org/index.php/Map_scancodes_to_keycodes

https://thinkpad-scripts.readthedocs.io/en/latest/guides/additional-keys.html

http://who-t.blogspot.com/2019/02/adding-entries-to-udev-hwdb.html

PS : if error => check syntax
