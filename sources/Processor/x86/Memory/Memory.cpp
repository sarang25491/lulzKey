/****************************************************************************
* lulzKey. Let's close those effin Windows so penguins won't enter.         *
*                                                                           *
* Copyright (C) 2010  meh. [http://meh.doesntexist.org]                     *
*                                                                           *
* This file is part of lulzKey.                                             *
*                                                                           *
* lulzKey is free software: you can redistribute it and/or modify           *
* it under the terms of the GNU Affero General Public License as published  *
* by the Free Software Foundation, either version 3 of the License, or      *
* (at your option) any later version.                                       *
*                                                                           *
* lulzKey is distributed in the hope that it will be useful,                *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU Affero General Public License for more details.                       *
*                                                                           *
* You should have received a copy of the GNU Affero General Public License  *
* along with lulzKey.  If not, see <http://www.gnu.org/licenses/>.          *
****************************************************************************/

#include <Processor/x86/Memory/Memory.h>

namespace Kernel {

namespace Processor {

namespace Memory {

Type::u32 address = 0;

void*
alloc (Type::u32 size, bool aligned)
{
    if (size < 1) {
        return NULL;
    }

    return _alloc(size, NULL, aligned);
}

void*
alloc (Type::u32 size, void* physical, bool aligned)
{
    if (size < 1) {
        return NULL;
    }

    return _alloc(size, physical, aligned);
}

void
free (void* pointer)
{
    if (pointer == NULL) {

    }
}

void
copy (void* destination, void* source, Type::u32 size)
{
    for (Type::u32 i = 0; i < size; i++) {
        ((Type::u8*) destination)[i] = ((Type::u8*) source)[i];
    }
}

void
set (void* destination, Type::u8 value, Type::u32 size)
{
    for (Type::u32 i = 0; i < size; i++) {
        ((Type::u8*) destination)[i] = value;
    }
}

void*
_alloc (Type::u32 size, void* physical, bool align)
{
    if (align && (address & 0xFFFFF000)) {
        address &= 0xFFFFF000;
        address += 0x1000;
    }

    if (physical) {
        *(Type::u32*) physical = address;
    }

    void* tmp  = (void*) address;
    address   += size;

    return tmp;
}

}

}

}

