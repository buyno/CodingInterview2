// 斐波那契数列

// 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1

#include <iostream>
using namespace std;
// (1)
class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        // 节约了空间
        int first = 0;
        int second = 1;
        for (int i = 2; i < n + 1; i++)
        {
            int tmp = (first + second) % 1000000007;
            first = second;
            second = tmp;
        }
        return second;
    }
};
// (2)
// class Solution
// {
// public:
//     int fib(int n)
//     {
//         if (n == 0)
//         {
//             return 0;
//         }
//         if (n == 1)
//         {
//             return 1;
//         }
//         // 数组保存中间值
//         int data[n + 1];
//         data[0] = 0;
//         data[1] = 1;

//         for (int i = 2; i < n + 1; i++)
//         {
//             data[i] = (data[i - 1] + data[i - 2]) % 1000000007;
//         }
//         return data[n];
//     }
// };
int main()
{
    cout << __INT_MAX__ << endl;
}