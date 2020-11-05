#include <AceEngine/AceEngine.hpp>
#include <iostream>
using namespace std;

ACE::texture texture;

int main()
{
    texture.load("texture.png");

    cout << "Format: " << texture.get_format() << endl;
    cout << "Width: " << texture.get_size().x << endl;
    cout << "Height: " << texture.get_size().y << endl;
}