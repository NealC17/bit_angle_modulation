#include "74HC595.h"

int freq[8]= {0, 0, 255, 0, 0, 0, 0, 255};
int vals[2] = {0, 255};

int c = -1;
int t = 0;
int i = 0;
int a = 0;
int prev_time = 0;

int main(){
  DDRD = DDRD | B00011111;
  PORTD = PORTD & (1 << OE);
  PORTD |= PORTD | (1 << SRCLR);
  
  while(1){
    c = (c + 1) % 256;
    if(c == 0){
      freq[a]= (freq[a] + 1)%256;
      
    }

    
    t = freq[0] > c;
    for(i = 1; i < 8; i++){
      t = t << 1;
      t |= freq[i] > c;
    }
    
    loadValue(t);
  }
  
  return 1;
}
