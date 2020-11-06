components_install() {
    sudo apt-get update
    sudo apt-get install libsdl2-dev \
        libsdl2-image-dev \
        libsdl2-ttf-dev \
        mesa-common-dev g++
}

default_install() {
    components_install

    if [ -d /usr/include/AceEngine ] ||
        [ -d /usr/lib/x86_64-linux-gnu/libAceEngine.so ]; then
        sudo make -f MakeFile uninstall
    fi
    make -f MakeFile
    sudo make -f MakeFile install

}

local_install() {
    components_install

    if [ ! -d "lib" ]; then
        mkdir lib
    fi

    make -f MakeFile
}

while getopts 'dlu' option; do
    case $option in
    d) default_install ;;
    l) local_install ;;
    u) make -f MakeFile uninstall ;;
    esac
done
