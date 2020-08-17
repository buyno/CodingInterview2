// 不用+-*/做加法

// 解法一：
// 异或和按位加相似，只是加会有进位
// 按位与得到的结果乘2，相当于得到所有进位
// 然后将异或的结果和按位与的结果合并，再循环直到没有新的进位
// （有些编译器对负数左移会报错，解决：左移之前转为无符号数）

// 解法二：
// 用位运算，32位逐位计算
// 因为负数按补码保存，所以也能正常运算

// #include <stdio.h>
// 解法一
// int main()
// {
//     int num1 = -20; //10100
//     int num2 = 4;   //00100
//     int yihuo = num1 ^ num2;
//     int jinwei = (num1 & num2) << 1;
//     while (jinwei)
//     {
//         num1 = yihuo;
//         num2 = jinwei;
//         yihuo = num1 ^ num2;
//         jinwei = (num1 & num2) << 1;
//     }
//     printf("res:%d\n", yihuo);
//     printf("%d\n", -1 ^ 2);
// }
#include <iostream>
#include <assert.h>
using namespace std;

// 解法二
class Solution
{
public:
    int add(int a, int b)
    {
        int bit = 0;
        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            if ((a & 1 << i) && (b & 1 << i))
            {
                if (bit)
                {
                    res = res | 1 << i;
                    bit = 1;
                }
                else
                {
                    bit = 1;
                }
            }
            else if ((a & 1 << i && !(b & 1 << i)) || (!(a & 1 << i) && (b & 1 << i)))
            {
                if (bit)
                {
                    bit = 1;
                }
                else
                {
                    res = res | 1 << i;
                    bit = 0;
                }
            }
            else if (!(a & 1 << i) && !(b & 1 << i))
            {
                if (bit)
                {
                    res = res | 1 << i;
                    bit = 0;
                }
                else
                {
                    bit = 0;
                }
            }
        }
        return res;
    }
};
int main()
{
    {
        Solution s;
        int res = s.add(1, 1);
        assert(res == 2);
    }
    {
        Solution s;
        int res = s.add(40, -30);
        assert(res == 10);
    }
    {
        Solution s;
        int res = s.add(20, -30);
        assert(res == -10);
    }
}