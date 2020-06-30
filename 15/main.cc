// 二进制中1的个数
// 存储的是补码，统计的1的位数也是补码中的1的位数。
// int a = 0x80000001 实际上是指的补码
// 1）每次右移一位，看最低位是否为1
//    缺点：对负数无效
// 2) flag为1，自己移位
// 
#include <stdio.h>
#include <assert.h>

void printNumber(int num){
    if(num < 0){
        printf("-");
        num = 0-num;
    }
    int length = 0;
    int a = num;
    while(a){
        length ++;
        a = a >> 1;
    }
    // printf("%d\n",length);
    int nums[length] = {0};
    int i = length-1;
    while(num){
        if((num & 1 )== 1){
            // printf("1");
            nums[i--] = 1;
        }else{
            // printf("0");
            nums[i--] = 0;
        }
        num = num >> 1;
    }
    for(int i = 0;i<length;i++){
        printf("%d",nums[i]);
    }
    printf("\n");

}
int getOnes_1(int num){
    int count = 0;
    while(num){
        if(num & 1 == 1){
            count++;
        }
        num = num >> 1;
    }
    return count;
}

int getOnes_2(int num){
    int count = 0;
    unsigned int flag = 1;
    while(flag){
        if(flag & num){
            count++;
        }
        flag = flag << 1;
    }
    return count;
}
int main(){
    int num = 10;
    // printNumber(num);
    int res = 0;
    // int a = 0xfffffff6;
    // int a = 0x8000000a;
    // printf("%d\n",a);
    assert(getOnes_2(15) == 4);
    assert(getOnes_2(-100) == 28);
    assert(getOnes_2(0x80000001) == 2);
    assert(getOnes_2(0xffffffff) == 32); 
    assert(getOnes_2(0) == 0); 
    assert(getOnes_2(0x7fffffff) == 31); 
    assert(getOnes_2(1) == 1);
    assert(getOnes_2(0x80000000) == 1);
}