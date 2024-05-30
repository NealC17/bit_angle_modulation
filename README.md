# bit_angle_modulation


Consider a normal PWM output with say a 70% duty cycle. It may look something like the following: 
___-------___-------

i.e. a square wave with a 70% duty cycle. 

Bit angle modulation is a form of encoding a byte onto a binary signal. To achieve the same 70% duty cycle, first we must find the corresponding integer, which is 180 since 180/256 = 70%.
The binary representation of 180 is 0b10110100. Each bit is assigned a weight corresponding to its digit, so the LSB gets 1 time interval, the next bit gets 2 time intervals, and so on until the MSB which gets 128 time intervals. 1 corresponds to logic high and 0 corresponds to logic low. Thus the bit angle modulation of 70% is the following:

_ __ ---- ________ ------...- ---...--- ________ ... ___ -------- ... --
1 2  4     8          16 ...  32             64                128


This is superior to traditional PWM since the signal only needs to be updated 8 times in 256 time intervals to change, compared to 256 times with traditional PWM. The minor inconvenience is the fact that the period must now be a power of 2, however in most applications the period length doesn't matter too much. 

Also notice that in total, the wave is high for 4 + 32 + 128 = 180 time intervals out of the 256 time interval period, just like in a traditional PWM signal.  
