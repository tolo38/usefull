
Create a Linux VM
---

- new maching: Linux 2.6 64b
- RAM 4G
- Hard disk VDI : without the machine cannot be saved
- ... Create
- Start : provide .iso file
- Intall OS : if not the machine will be empty after reboot
- Reboot , the installation is Done

Close and restart VM
---
- It is advised that the VM is turned off like a real maching, going in the OS menu and clik `shutdown/restart/...`
- **Save the machine state** : Safe, but time and memory consuming (similar to hibernate option) it takes space as it save current RAM state, and is more time consuming, when storing and retriving RAM content
- **Send the shutdown signal** : Safe, and OK. it is similare to pressing a power button on physical hardware. It will send a ACPI signal that will allow a graceful shutdown of the Virtual Machine. It is similar to the poweroff command in Linux or Shutdown option inside Windows.
- **Power off the mahine** : UnSafe, for emergency. it is much like pulling the power cord on the physical hardware. It is a hard shutdown and may sometimes be required if the Virtual Machine is frozen and graceful shutdown is not possible. It should only be used as the last resort there may be potential data loss.

adapte Display
---
natively OS on Vbox does not provide all resolution. Run the following commande to make it available.
Or better, follow the steps in [Guest additions](#share-folder-and-clipboard) Section.
```sh
sudo apt install build-essential module-assistant
```


Shared folder and clipboard
---

Vbox allows to share folder and clipboard. However installed os is not aware that it is being run into VM.
- Go to `Devices` menu and clic `Insert Guest Additons CD Image...` it should be the last item.
-   if it is not here press ctrl+C to make it appear
- Run the installer from the CD
- Reboot, the installation is effective only after rebooting.

Done !
- Now the Installed OS is ready to behave as a guest and should provid better integration (clipboard, Resolution,...)
- If `permission denied` message popup on accessing shared folder , it is that the current user as to be add into `vboxsf` groupe
```sh
thomas@thomas-VirtualBox:~$ sudo gpasswd -a thomas vboxsf
```
 - By default (when auto-mount is checked) shared folder are mounted on `/media/sf_`
