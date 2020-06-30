// 顺时针打印矩阵
#include <stdio.h>
//打印矩阵中从(start,start)开始的一圈数字

// 1，test.cc中注释掉的是多余的判断
// 2，**start < rows/2 && start < cols/2与start*2 < rows && start*2 < cols不同
void printACircle(int *nums,int rows,int cols,int start){
    for(int i = start;i<cols-start;i++){
        printf("%d ",nums[start*cols+i]);
    }

    for(int i = start+1;i<rows-start;i++){
        printf("%d ",nums[i*cols+cols-start-1]);
    }
    if(start < rows-start - 1){
        for(int i = cols-start-2;i >= start;i--){
            printf("%d ",nums[(rows-start -1)*cols+i]);
        }
    }
    if(cols-start - start > 1){
        for(int i = rows-start - 2;i>start;i--){
            printf("%d ",nums[i*cols+start]);
        }
    }
}
void printInCircle(int *nums,int rows,int cols){
    // for(int start = 0;start < rows/2 && start < cols/2;start++){
    //     printACircle(nums,rows,cols,start);
    // }
    for(int start = 0;start*2 < rows && start*2 < cols;start++){
        printACircle(nums,rows,cols,start);
    }
}
void Test(int rows,int cols){
    printf("----------------------\nTest for %d rows,%d columns:\n",rows,cols);
    int nums[rows*cols] ;
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            nums[i*cols+j] = i*rows+j;
        }
    }
    printf("matrix:\n");
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            printf("%d ",nums[i*cols+j]);
        }
        printf("\n");
    }
    printf("circle:\n");
    printInCircle(nums,rows,cols);
    printf("\n");
}
//  0  1  2  3  4 
//  5  6  7  8  9 
// 10 11 12 13 14 
// 15 16 17 18 19 
// 20 21 22 23 24

int main(){
    Test(1,1);
    Test(2,2);
    Test(4,4);
    Test(5,5);
    Test(1,5);
    Test(2,5);
    Test(3,5);
    Test(4,5);
    Test(5,1);
    Test(5,2);
    Test(5,3);
    Test(4,1);

}