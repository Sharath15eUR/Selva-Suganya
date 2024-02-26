#include <stdio.h>

int main(){
  
int number;
  
  printf("Enter the number");
scanf("%d",&number);
  
if((number & 1) == 0) printf("The given number is even");
  else printf("The given number is odd");
  
return 0;
}
