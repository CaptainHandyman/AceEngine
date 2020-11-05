# AceEngine
## Installation:
#### Main:
* ``` sudo apt-get install git ```
* ``` git clone https://github.com/RedBull4/AceEngine ```
* ``` cd AceEngine ```
#### Default:
* ``` sudo ./install.sh -d ```
#### Local:
* ``` sudo ./install.sh -l ```

  Local installation only creates a ``` .so ``` file in the ``` lib ``` folder!
#
### Uninstallation:
* ``` sudo ./install.sh -u ```
### Compilation:
```
g++ file.cpp -lAceEngine -lSDl2 \
                         -lSDL2_image \
                         -lSDL2_ttf -lGL 
```
### Notes:
* Engine path: ``` /usr/include/AceEngine ```
* Library path: ``` /usr/x86_64-linux-gnu/libAceEngine.so ```
---
**Contacts:**
* Mail: alexandralibekov@yahoo.com
