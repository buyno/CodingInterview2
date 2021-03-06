// 动态规划问题：剪绳子
// n长的绳子剪成m段，使得每段长度的乘积最大
// :给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
// 至少要切一刀
// 2 <= n <= 58
#include <stdio.h>
#include <assert.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int cuttingRope(int n)
    {
        if (n == 2)
        {
            return 1;
        }
        if (n == 3)
        {
            return 2;
        }
        int data[n + 1];
        data[1] = 1;
        data[2] = 2;
        data[3] = 3;
        for (int i = 4; i < n + 1; i++)
        {
            int max = 0;
            for (int j = 1; j < i; j++)
            {
                // cout << j << ":" << data[i - j] << endl;
                if (j * data[i - j] > max)
                {
                    max = j * data[i - j];
                }
            }
            data[i] = max;
        }
        return data[n];
    }
};

int main()
{
    Solution s;
    assert(s.cuttingRope(2) == 1);
    assert(s.cuttingRope(3) == 2);
    assert(s.cuttingRope(5) == 6);
    assert(s.cuttingRope(6) == 9);
    assert(s.cuttingRope(7) == 12);
    assert(s.cuttingRope(8) == 18);
    assert(s.cuttingRope(50) == 86093442);
}