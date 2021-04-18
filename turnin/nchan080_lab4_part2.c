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

enum SM1_STATES {SM1_Start, SM1_Init, SM1_Add, SM1_Sub, SM1_Wait1, SM1_Wait2, SM1_Wait3, SM1_Zero, SM1_Start2} SM1_STATE;


void Calc(){

  unsigned char A0 = PINA & 0x01;
  unsigned char A1 = PINA & 0x02;
  switch(SM1_STATE){
    case(SM1_Start):
      if(A1 && A0){
        SM1_STATE = SM1_Zero;
      }
      else
        SM1_STATE = SM1_Start2;
      break;
    case(SM1_Start2):
      if(A1 && A0){
        SM1_STATE = SM1_Zero;
      }
      else
        SM1_STATE = SM1_Init;
      break;
    case(SM1_Init):
      if(A0 && A1){
        SM1_STATE = SM1_Zero;
      }
      else if(A0 && !A1){
        SM1_STATE = SM1_Add;
      }
      else if(!A0 && A1){
        SM1_STATE = SM1_Sub;
      }
      break;
    case(SM1_Add):
      if(A0){
        SM1_STATE = SM1_Wait1;
      }
      else if(A0 && A1){
        SM1_STATE = SM1_Zero;
      }
      else if(!A0){
        SM1_STATE = SM1_Init;
      }
      break;
    case(SM1_Wait1):
      if(!A0){
        SM1_STATE = SM1_Init;
      }
      else if(A1 && A0){
        SM1_STATE = SM1_Zero;
      }
      break;

    case(SM1_Sub):
      if(A1){
        SM1_STATE = SM1_Wait2;
      }
      else if(A0 && A1){
        SM1_STATE = SM1_Zero;
      }
      else if(!A1){
        SM1_STATE = SM1_Init;
      }
      break;
    case(SM1_Wait2):
      if(!A1){
        SM1_STATE = SM1_Init;
      }
      else if(A1 && A0){
        SM1_STATE = SM1_Zero;
      }
      break;
    case(SM1_Wait3):
      if(A1 && A0){
        SM1_STATE = SM1_Zero;
      }
      else if(A0 && !A1){
        SM1_STATE = SM1_Wait1;
      }
      else if(A1 && !A0){
        SM1_STATE = SM1_Wait2;
      }
      
      break;
      
      case(SM1_Zero):
        if(A1 && A0){
          SM1_STATE = SM1_Zero;
        }
        else if (!A1 && !A0){
          SM1_STATE = SM1_Wait3;
        }
      break
  }
  switch(SM1_STATE){
    case SM1_Add:
      if(PORTC>=9)
        PORTC = 9;
      else
        PORTC++;
      break;
    case SM1_Sub:
      if(PORTC<=0)
        PORTC = 0;
      else
        PORTC--;
      break;
    case SM1_Zero:
      PORTC = 0;
      break;
    case SM1_Start2:
      PORTC = 7;
      break;
    default:
      break;
  }
}
int main(void) {
  DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
  DDRC = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs

  SM1_STATE = SM1_Start;
  while(1) {
    Calc();
  }
  return 0;
}
