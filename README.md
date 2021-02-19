![AceEngine_Logo](https://raw.githubusercontent.com/RedBull4/AceEngine/master/AceEngine.png)
#
### Installation:
* ``` sudo apt-get update && sudo apt-get install git ```
* ``` git clone https://github.com/RedBull4/AceEngine ```
* ``` cd AceEngine && sudo ./configure.sh ```
* ``` mkdir lib && make -f MakeFile ```
* ``` sudo make -f MakeFile install```
### Uninstallation:
* ``` sudo make -f MakeFile uninstall ```
### Compilation:
```
g++ file.cpp -lAceEngine \
             -lSDL2 \
             -lSDL2_image \
             -lSDL2_ttf -lGL 
```
Or see the example MakeFile ``` examples / MakeFile_examples ```.
### Notes:
* Engine path: ``` /usr/include/AceEngine ```
* Library path: ``` /usr/x86_64-linux-gnu/libAceEngine.so ```
#
```cpp
#include <AceEngine/AceEngine.hpp>

ACE::window window;

SDL_Event event;

int main() {
    window.create("AceEngine", ACE_WINDOW_POS_CENTERED,
                  ACE::vector2<int>(800, 800));

    while (window.is_open()) {
        while (SDL_PollEvent(&event)) {
            if (window.quit(event))
                window.close();
        }

        window.clear();
        window.display();
    }
}
```
---
This program is free software. You can redistribute it and/or modify.

**Contacts:**
* Mail: alexandralibekov@yahoo.com
