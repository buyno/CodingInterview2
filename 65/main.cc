// 不用+-*/做加法

// 异或和按位加相似，只是加会有进位
// 按位与得到的结果乘2，相当于得到所有进位
// 然后将异或的结果和按位与的结果合并，再循环直到没有新的进位

// 有些编译器对负数左移会报错，解决：左移之前转为无符号数
#include <stdio.h>

int main()
{
    int num1 = -20; //10100
    int num2 = 4;   //00100
    int yihuo = num1 ^ num2;
    int jinwei = (num1 & num2) << 1;
    while (jinwei)
    {
        num1 = yihuo;
        num2 = jinwei;
        yihuo = num1 ^ num2;
        jinwei = (num1 & num2) << 1;
    }
    printf("res:%d\n", yihuo);
    printf("%d\n", -1 ^ 2);
}