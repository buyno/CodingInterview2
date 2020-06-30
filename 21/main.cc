// 调整数组顺序使奇数位于偶数前面
// [1,2,3,4,5] -> [1,3,5,2,4]
#include <stdio.h>
#include <stdlib.h>
// 判断奇偶：x%2==0   x&0x1==0
// void myswitch_1(int *num,int length){
//     if(num == nullptr)return;
//     int *left = num;
//     int *right = num+length-1;
//     while(left < right){
//         //这里一个循环移动一位，也可以连续奇或连续偶时一次移动多位
//         if(*left%2 == 0 && *right%2){
//             int temp = *left;
//             *left = *right;
//             *right = temp;
//         }
//         if(*left%2){
//             left++;
//         }
//         if(*right%2 == 0){
//             right--;
//         }
//     }
// }
void myswitch_2(int *num,int length){
    if(num == nullptr)return;
    int *left = num;
    int *right = num+length-1;
    while(left < right){
        //左右分别先找到第一个偶/奇
        while(left-num < length && *left%2==1){
            left++;
        }
        while(right-num >=0 && *right%2==0){
            right--;
        }
        if(left < right){
            int temp = *left;
            *left = *right;
            *right = temp;
        }

    }
}

int main(int argc,char **argv){
    int num[] = {1,2,3,4,5};
    // int num[] = {1,3,5,6,8,10};
    // int num[] = {20,4,2,6,13,15};
    // int num[] = {2};
    int length = sizeof(num)/sizeof(num[0]);
    myswitch_2(num,length);
    for(int i = 0;i<length;i++){
        printf("%d\n",num[i]);
    }
    myswitch_2(nullptr,0);
}