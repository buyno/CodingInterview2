// 二进制中1的个数
// 存储的是补码，统计的1的位数也是补码中的1的位数。
// int a = 0x80000001 实际上是指的补码
// 1）每次右移一位，看最低位是否为1
//    缺点：对负数无效
// 2) flag为1，自己移位
//
#include <stdio.h>
#include <assert.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        long index = 1;
        int result = 0;
        for (int i = 0; i < 32; i++)
        {
            if (n & index)
            {
                result++;
            }
            index = index << 1;
        }
        return result;
    }
};
// 输出一个数的二进制
void printNumber(int num)
{
    if (num < 0)
    {
        printf("-");
        num = 0 - num;
    }
    int length = 0;
    int a = num;
    while (a)
    {
        length++;
        a = a >> 1;
    }
    // printf("%d\n",length);
    int nums[length] = {0};
    int i = length - 1;
    while (num)
    {
        if ((num & 1) == 1)
        {
            // printf("1");
            nums[i--] = 1;
        }
        else
        {
            // printf("0");
            nums[i--] = 0;
        }
        num = num >> 1;
    }
    for (int i = 0; i < length; i++)
    {
        printf("%d", nums[i]);
    }
    printf("\n");
}

int main()
{
    Solution s;
    assert(s.hammingWeight(2) == 1);
}