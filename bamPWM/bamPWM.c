#include "74HC595.h"

int freq[8]= {0, 0, 0, 0, 0, 0, 0, 255};
int vals[2] = {0, 255};
int timing[8] = {1, 2, 4, 8, 16, 32, 64, 128};
int c = -1;
int t = 0;
int i = 0;
int a = 0;
int prev_time = 0;
int dir = 1;
int time_idx = 0;
int main(){
  DDRD = DDRD | 0b00011111;
  PORTD = PORTD & (1 << OE);
  PORTD |= PORTD | (1 << SRCLR);
  
  while(1){
    
    c = (c + 1) % 256;
    if(c == 0){
      freq[a]= (freq[a] + 1)%256;
      freq[2]+= dir;
      if(freq[2] > 127 || freq[2] < 0) dir *= -1;
    }

    
    for(i = 0; i < 8; i++){
	t = t << 1;
	t |= freq[i] > c;
    }
    
    loadValue(t);


    /*int bit_extract = 1 << time_idx;
    
    if(c == timing[time_idx]){
	    time_idx = (time_idx+1)%8;
	    for(i = 0; i < 8; i++){
		t |= freq[i] | bit_extract;
		t = t << 1;
	    }
	    loadValue(t);
    }*/


  }
  
  return 1;
}
