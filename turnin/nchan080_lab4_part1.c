/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum SM1_STATES {SM1_ZeroOn, SM1_OneOn, SM1_Wait, SM1_Wait2} SM1_STATE;


void Light(){

  unsigned char A0 = PINA & 0x01;
  switch(SM1_STATE){
    case(SM1_ZeroOn):
      if(A0){
        SM1_STATE = SM1_Wait;
      }
      break;
    case(SM1_Wait):
      if(!A0){
        SM1_STATE = SM1_OneOn;
      }
    case(SM1_OneOn):
      if(A0){
        SM1_STATE = SM1_Wait2;
      }
      break;
    case(SM1_Wait2):
      if(!A0){
        SM1_STATE = SM1_ZeroOn;
      }
    }
  switch(SM1_STATE){
    case SM1_ZeroOn:
      //B0 = 1;
      //B1 = 0;
      PORTB = 0x01;
      break;
    case SM1_OneOn:
      //B0 = 0;
      //B1 = 1;
      PORTB = 0x02;
      break;
    default:
      break;
  }
}
int main(void) {
  DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs

SM1_STATE = SM1_ZeroOn;
while(1) {
  Light();
}
  return 0;
}
