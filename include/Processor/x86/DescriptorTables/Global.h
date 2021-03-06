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

#ifndef _LKEY_PROCESSOR_X86_DESCRIPTORTABLES_GLOBAL_H
#define _LKEY_PROCESSOR_X86_DESCRIPTORTABLES_GLOBAL_H

#include <Type.h>

namespace Kernel {

namespace Processor {

namespace DescriptorTables {

class Global
{
  protected:
    Global (void) {};

  public:
    /**
     * Global Entry Descriptor
     */
    struct Entry {
        Type::u16 limitLow;     /*<< The lower 16 bits of the limit */
        Type::u16 baseLow;      /*<< The lower 16 bits of the base. */
        Type::u8  baseMiddle;   /*<< The next 8 bits of the base. */
        Type::u8  access;       /*<< Access flags, determine what ring this segment can be used in. */
        Type::u8  granularity;
        Type::u8  baseHigh;     /*<< The last 8 bits of the base. */
    } __attribute__ ((packed));

    /**
     * Global Descriptor Table pointer.
     */
    struct Pointer {
        Type::u16 limit; /*<< The upper 16 bits of all selector limits. */
        Type::u32 base;  /*<< The address of the first descriptor. */
    } __attribute__ ((packed));

    struct TSS {
        Type::u32 prevTSS;
        Type::u32 esp0;
        Type::u32 ss0;
        Type::u32 esp1;
        Type::u32 ss1;
        Type::u32 esp2;
        Type::u32 ss2;
        Type::u32 cr3;
        Type::u32 eip;
        Type::u32 eflags;
        Type::u32 eax;
        Type::u32 ecx;
        Type::u32 edx;
        Type::u32 ebx;
        Type::u32 esp;
        Type::u32 ebp;
        Type::u32 esi;
        Type::u32 edi;
        Type::u32 es;
        Type::u32 cs;
        Type::u32 ss;
        Type::u32 ds;
        Type::u32 fs;
        Type::u32 gs;
        Type::u32 ldt;
        Type::u16 trap;
        Type::u16 iomapBase;
    } __attribute__ ((packed));

  private:
    static Entry   _entries[8];
    static Pointer _pointer;
    static TSS     _tss;

  public:
    static void init (void);

    static void set (Type::s32 index, Type::u32 base, Type::u32 limit, Type::u8 access, Type::u8 granularity);

    static void flush (void);

  private:
    static void _initTSS (Type::u32 index, Type::u16 ss0, Type::u32 esp0);
    static void _flushTSS (bool service = true);
};

}

}

}

#endif
