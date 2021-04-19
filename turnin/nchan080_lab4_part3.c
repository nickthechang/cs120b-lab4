#include <stdio.h>

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
      else if(A7){
        SM1_STATE = Inside;
      }
      break;
    
    case(Pressed):
      if(!A2){
        SM1_STATE = Released;
      }
      break;

    case(Released):
      if(PINA == 0x00){
        SM1_STATE = Released;
      }
      else if(!A1){
        SM1_STATE = Start;
      }
      else if(A1){
        SM1_STATE = Open;
      }
      break;

    default:
      break;
  }
  
  switch(SM1_STATE){
    case Start:
      PORTB = 0x00;
      break;
    case Inside:
      PORTB = 0x01;
      break;
    case Open:
      PORTB = 0x02;
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