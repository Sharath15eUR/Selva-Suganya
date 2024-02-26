#include <stdio.h>

void swap(int* a, int* b){    
    int temp;
    temp= *a;
    *a=*b;
    *b= temp;

}

int main(){
    
    void (*funcptr) (int*, int*);   //function pointer declaration
    funcptr = swap;
    
    int num1,num2;
    
    printf("Enter two numbers");
    scanf("%d %d", &num1, &num2);
    
   (*funcptr) (&num1,&num2);     //function call usinf function pointer
    
    printf("The swapped numbers are %d %d", num1,num2);
    return 0;
}
