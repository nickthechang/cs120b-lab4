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

enum SM1_STATES {Start, Inside, Pressed, Released, Open} SM1_STATE;


void Lock(){

  unsigned char A0 = PINA & 0x01;
  unsigned char A1 = PINA & 0x02;
  unsigned char A2 = PINA & 0x04;
  unsigned char A7 = PINA & 0x80;
  switch(SM1_STATE){
    case(Start):
      if(A2){
        SM1_STATE = Pressed;
      }
      break;
    
    case(Pressed):
      if(!A2){
        SM1_STATE = Released;
      }
      break;

    case(Released):
      if(A0 || A2){
        SM1_STATE = Start;
      }
      else if(A1){
        SM1_STATE = Open;
      }
      break;
      
    case(Open):
      if(A7){
        SM1_STATE = Start;
      }

    default:
      break;
  }
  
  switch(SM1_STATE){
    case Start:
      PORTB = 0x00;
      break;
    case Open:
      PORTB = 0x01;
      break;

    default:
      break;
  }
}
int main(void) {
  DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs

SM1_STATE = Start;
while(1) {
  Lock();
}
  return 0;
}
