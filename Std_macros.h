#ifndef STD_MACROS_H_
#define STD_MACROS_H_



//Frequency
#define F_CPU 8000000UL

//Libraries
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


//Bit manipulation macros
#define SETBIT(REG,BIT)  (REG |= 1 << BIT)
#define CLRBIT(REG,BIT)  (REG &= ~(1 << BIT))
#define TOGBIT(REG,BIT)  (REG ^= 1 << BIT)
#define READBIT(REG,BIT)  ((REG >> BIT) & 1)




#endif /* STD_MACROS_H_ */