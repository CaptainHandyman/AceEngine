/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-10-28 14:48:25
 * @modify date 2020-10-28 14:48:25
 * @version 0.01
 */

#ifndef ACEENGINE_HPP
#define ACEENGINE_HPP

#include "includes.hpp"
#include "utilities.hpp"
#include "structures.hpp"

#define ACE_WINDOW_POS_CENTERED 0xc - 0
#define ACE_WINDOW_POS_TOP_LEFT 0xc - 1
#define ACE_WINDOW_POS_TOP_RIGH 0xc - 2
#define ACE_WINDOW_POS_BOTTOM_LEFT 0xc - 3
#define ACE_WINDOW_POS_BOTTOM_RIGHT 0xc - 4

typedef uint16_t ACE_FLAGS;

enum
{
    ACE_WINDOW_NO_FLAGS = 1 << 0,
    ACE_WINDOW_FULLSCREEN = 1 << 1,
    ACE_WINDOW_RESIZABLE = 1 << 2
};

namespace ACE
{
} // namespace ACE

#endif // ACEENGINE_HPP