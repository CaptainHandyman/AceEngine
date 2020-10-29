echo "installing SDL2 libraries: "
sudo apt-get update
sudo apt-get install libsdl2-dev \
    libsdl2-image-dev \
    libsdl2-ttf-dev \
    mesa-common-dev

if [ -d /usr/include/AceEngine ] ||
    [ -d /usr/lib/x86_64-linux-gnu/libAceEngine.so ]; then
    sudo make -f MakeFile uninstall
fi
make -f MakeFile
sudo make -f MakeFile install
