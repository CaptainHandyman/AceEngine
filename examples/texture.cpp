/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-11-03 13:50:11
 * @modify date 2020-11-03 13:50:11
 * @version 0.04
 */

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