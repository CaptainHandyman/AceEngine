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

/* WINDOW POSITIONS */ /* ------------------------------------------ */
/* CENTERED         */ #define ACE_WINDOW_POS_CENTERED { 0xc - 0 }
/* TOP LEFT         */ #define ACE_WINDOW_POS_TOP_LEFT { 0xc - 1 }
/* TOP RIGHT        */ #define ACE_WINDOW_POS_TOP_RIGHT { 0xc - 2 }
/* BOTTOM LEFT      */ #define ACE_WINDOW_POS_BOTTOM_LEFT { 0xc - 3 }
/* BOTTOM RIGHT     */ #define ACE_WINDOW_POS_BOTTOM_RIGHT { 0xc - 4 }
/* WINDOW POSITIONS */ /* ------------------------------------------ */

typedef uint16_t ACE_FLAGS;

/* WINDOW FLAGS */ /* ------------------------------- */
enum
{
/* REMOVE ALL FLAGS */ ACE_WINDOW_NO_FLAGS = 1 << 0,
/* FULLSCREEN       */ ACE_WINDOW_FULLSCREEN = 1 << 1,
/* RESIZABLE        */ ACE_WINDOW_RESIZABLE = 1 << 2
};
/* WINDOW FLAGS */ /* ------------------------------- */

namespace ACE
{
} // namespace ACE

#endif // ACEENGINE_HPP