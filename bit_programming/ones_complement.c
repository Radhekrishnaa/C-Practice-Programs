#include<stdio.h>

int main(){
    short int b=5;//Bit equivalent of 5 = 00000101  as it is 32 bit compiler

    printf("b = %d",~b);
    //~b is compelent of b 
    //so compelent of b is 11111010 = It is going to be a negative number as the M.S.D place has 1
    //and it will be even as L.S.D place has 0 and vice versa for opposite.
    //So the value of ~b = -128+64+32+16+8+0+2+0 = -6
    return 0 ;
}