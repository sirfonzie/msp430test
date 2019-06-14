#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    P1DIR |= BIT0;              // P1.0 (Red) -> Output

    P2DIR |= BIT6;

    P4DIR &= ~BIT3;             // P1.3 (SW2) -> Input
    P4REN &= ~BIT3;              // P1.3 Pull Up/Down Enable


    P1OUT &= BIT0;
    P2OUT |= BIT6;

    while(1)
    {
        if((P4IN & BIT3) == 0)
            P1OUT |= BIT0;      // else LED ON
        else
            P1OUT &= BIT0;      // else LED OFF
    }
}

/*

#include <msp430.h> 


int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	P2DIR = 0X00;
	P2REN = 0X00;
	P8DIR |= 0X06;
	P8OUT |= 0X06;

	while(1){
	    if((P2IN & 0x01) == 0)
	        P8OUT ^= 0x02;

	    if((P2IN & 0x04) == 0)
	        P8OUT ^= 0x04;
	}

	return 0;
}
*/
