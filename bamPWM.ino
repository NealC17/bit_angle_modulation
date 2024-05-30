#define SER 0 //serial data input 
#define OE 1 //output enable (active low)
#define RCLK 2 //Register clk
#define SRCLK 3 //Shift register clk
#define SRCLR 4 //Shift register clear (active lpw) 

#define CLOCK_PULSE 1 //Microseconds


int freq[8]= {0, 0, 255, 0, 0, 0, 0, 255};
int vals[2] = {0, 255};

int c = -1;
int t = 0;
int i = 0;

int prev_time = 0;
int a = 0;
int b;
void clearR(){// 2*CLOCK_PULSE overhead

  //clear the shift register
  
  PORTD |= (1 << SRCLR);
  PORTD &= ~(1 << SRCLR);
}


void loadR(){ // 2*CLOCK_PULSE overhead
  //Load SR data to R
  PORTD &= ~(1 << RCLK);
  PORTD |= (1 << RCLK);
}
void loadValue(int temp){
  for(int i = 0; i < 8; i++){// 2*8*CLOCK_PULSE
    b = temp&1;
    if(b){
        PORTD |= (1 << SER);
        
    } else {
        PORTD &= ~(1 << SER);
    }    
    
    temp = temp >> 1;
    PORTD &= ~(1 << SRCLK);
    PORTD |= (1 << SRCLK);
    
  }
  
  loadR();
}

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
