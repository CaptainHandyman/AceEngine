shared_install() {
    sudo apt-get update
    sudo apt-get install libsdl2-dev \
        libsdl2-image-dev \
        libsdl2-ttf-dev \
        mesa-common-dev g++

    if [ -d /usr/include/AceEngine ] ||
        [ -d /usr/lib/x86_64-linux-gnu/libAceEngine.so ]; then
        sudo make -f MakeFile uninstall
    fi
    make -f MakeFile
    sudo make -f MakeFile install

}

while getopts 'dlu' option; do
    case $option in
    d) shared_install ;;
    l) make -f MakeFile ;;
    u) make -f MakeFile uninstall ;;
    esac
done