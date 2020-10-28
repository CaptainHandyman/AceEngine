if [ -d /usr/include/AceEngine ] ||
    [ -d /usr/lib/x86_64-linux-gnu/libAceEngine.so ]; then
    sudo make -f MakeFile uninstall
fi
make -f MakeFile
sudo make -f MakeFile install
