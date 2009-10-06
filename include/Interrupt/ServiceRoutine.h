#ifndef _LKEY_DESCRIPTORTABLES_INTERRUPT_ISR_H
#define _LKEY_DESCRIPTORTABLES_INTERRUPT_ISR_H

#define __ISR(n) __isr## n
#define __DEFINE_ISR(n) extern "C" void __isr##n ()

__DEFINE_ISR(0);
__DEFINE_ISR(1);
__DEFINE_ISR(2);
__DEFINE_ISR(3);
__DEFINE_ISR(4);
__DEFINE_ISR(5);
__DEFINE_ISR(6);
__DEFINE_ISR(7);
__DEFINE_ISR(8);
__DEFINE_ISR(9);
__DEFINE_ISR(10);
__DEFINE_ISR(11);
__DEFINE_ISR(12);
__DEFINE_ISR(13);
__DEFINE_ISR(14);
__DEFINE_ISR(15);
__DEFINE_ISR(16);
__DEFINE_ISR(17);
__DEFINE_ISR(18);
__DEFINE_ISR(19);
__DEFINE_ISR(20);
__DEFINE_ISR(21);
__DEFINE_ISR(22);
__DEFINE_ISR(23);
__DEFINE_ISR(24);
__DEFINE_ISR(25);
__DEFINE_ISR(26);
__DEFINE_ISR(27);
__DEFINE_ISR(28);
__DEFINE_ISR(29);
__DEFINE_ISR(30);
__DEFINE_ISR(31);

#endif