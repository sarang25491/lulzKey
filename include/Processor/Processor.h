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

#ifndef _LKEY_PROCESSOR_H
#define _LKEY_PROCESSOR_H

/**
 * A correct #{ARCH}/Process.h should have:
 *  struct Registers with all the registers to be saved from the context.
 *  struct InterruptRegisters with all the stuff pushed in by interrupts.
 *  void init (Multiboot& boot) to initialize what's needed with the boot data.
 */

#ifdef _ARCH_X86
#   include <Processor/x86/Processor.h>
#else
#   error "You didn't choose a supported architecture. Faggot."
#endif

#endif
