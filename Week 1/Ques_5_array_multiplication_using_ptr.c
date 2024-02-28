#include <stdio.h>


int main() {

    int mat1[3][3],mat2[3][3],res[3][3],*p[3],*q[3],*r[3],j1=0;

    // 1st Matrix
    
    printf("Enter matrix 1\n");

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&mat1[i][j]);
        }
    }

    // 2nd matrix
    
     printf("Enter matrix 2\n");

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&mat2[i][j]);
        }
    }

    // Assigning pointers

    for(int i=0;i<3;i++) p[i]=&mat1[i][0];
    for(int i=0;i<3;i++) q[i]=&mat2[i][0];
    for(int i=0;i<3;i++) r[i]=&res[i][0];

    // Resultant Matrix

    for(int i=0;i<3;i++){
        for(j1=0;j1<3;j1++){
             *(*(r+i)+j1) = *(*(p+i)+j1) * *(*(q+i)+j1);
        }
        j1 = 0;
    }
    printf("The resultant matrix is\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",res[i][j]);
        }
        printf("\n");
    }
}
