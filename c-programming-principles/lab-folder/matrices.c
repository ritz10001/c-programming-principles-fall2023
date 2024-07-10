#include<stdio.h>



int main(){

    int a[2][2] = {{3,-4},{10,3}};
    int b[2][2] = {{-3,9},{2,5}};

    int sum_matrix[2][2];


    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
        for(int j=0;j<sizeof(a)/sizeof(a[0]);j++){
            sum_matrix[i][j]=a[i][j]+b[i][j];
            printf("%d %d\n", a[i][j], b[i][j]);
        }
    }
    printf("Sum matrix is {{%d, %d}, {%d, %d}}", sum_matrix[0][0], sum_matrix[0][1], sum_matrix[1][0], sum_matrix[1][1]);


    // int sub_matrix[2][2];

    // for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
    //     for(int j=0;j<sizeof(a)/sizeof(a[0]);j++){
    //         sub_matrix[i][j]=a[i][j]-b[i][j];
    //         printf("%d %d\n", a[i][j], b[i][j]);
    //     }
    // }
    // printf("Sub matrix is {{%d, %d}, {%d, %d}}", sub_matrix[0][0], sub_matrix[0][1], sub_matrix[1][0], sub_matrix[1][1]);
    



    int mul_matrix[2][2];

    


    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
        
        for(int j=0;j<sizeof(a)/sizeof(a[0]);j++){
            mul_matrix[i][j]=0;
            for(int k=0;k<2;k++){
                mul_matrix[i][j]+=a[i][k]*b[k][i];
            }
            //printf("%d %d\n", a[i][j], b[i][j]);
        }
        
    }
    printf("Mul matrix is {{%d, %d}, {%d, %d}}", mul_matrix[0][0], mul_matrix[0][1], mul_matrix[1][0], mul_matrix[1][1]);


    return 0;
}

