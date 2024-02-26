/* The program to count the number of set bits 
The number is fetched from the user and is performed bitwise AND with 1. If the result of the bitwise operation is 1, then the last bit is set. The same is repeated through a while loop by right shifting the number by 1 bit to get the count of set bits.
example : 13
1101 0110 0011 0001
*/


#include <stdio.h>

int main(){
    
unsigned int number;
int setbits;
  printf("Enter the number");
  scanf("%d",&number);    
  
while(number!=0){
    
if((number & 1) == 1) setbits++;

number>>=1;

}

printf("The number of set bits is %d",setbits);

return 0;
}
