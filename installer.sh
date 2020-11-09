install_components() {
    if [ ! -d "/usr/include/SDL2" ]; then
        sudo apt-get update
        sudo apt-get install libsdl2-dev \
            libsdl2-image-dev \
            libsdl2-ttf-dev \
            mesa-common-dev g++
    fi
}

install_engine() {
    install_components

    if [ ! -d "lib" ]; then
        mkdir lib
    fi

    if [ -d /usr/include/AceEngine ] ||
        [ -d /usr/lib/x86_64-linux-gnu/libAceEngine.so ]; then
        sudo make -f MakeFile uninstall
    fi
    make -f MakeFile
    sudo make -f MakeFile install
}

while getopts 'iu' option; do
    case $option in
    i) install_engine ;;
    u) make -f MakeFile uninstall ;;
    esac
done
