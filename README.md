![AceEngine_Logo](https://raw.githubusercontent.com/RedBull4/AceEngine/master/AceEngine.png)
#
### Installation:
* ``` sudo apt-get update ```
* ``` sudo ./configure.sh ```
* ``` sudo apt-get install git ```
* ``` git clone https://github.com/RedBull4/AceEngine ```
* ``` cd AceEngine ```
* ``` make -f MakeFile ```
* ``` sudo make -f MakeFile install```
### Uninstallation:
* ``` sudo make -f MakeFile uninstall ```
### Compilation:
```
g++ file.cpp -lAceEngine -lSDL2 \
                         -lSDL2_image \
                         -lSDL2_ttf -lGL 
```
### Notes:
* Engine path: ``` /usr/include/AceEngine ```
* Library path: ``` /usr/x86_64-linux-gnu/libAceEngine.so ```
---
This program is free software. You can redistribute it and/or modify.

**Contacts:**
* Mail: alexandralibekov@yahoo.com
