// 动态规划问题：剪绳子
// n长的绳子剪成m段，使得每段长度的乘积最大
// :给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
// 至少要切一刀
// 2 <= n <= 10000,结果需要取模(%1000000007)
// 大数问题，不能用以前那种解法，只能用贪心算法，也就是切分的时候能分3就尽量分3，余数为0/1/2.当余数为1时，退会一个3.
// 或者，如下实现，一直最大的肯定来自-3的位置，就每次都只算那个位置的
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
        if (n == 4)
        {
            return 4;
        }
        long long data[n + 1];
        data[1] = 1;
        data[2] = 2;
        data[3] = 3;
        data[4] = 4;
        for (int i = 5; i < n + 1; i++)
        {
            data[i] = data[i - 3] * 3 % 1000000007;
        }
        return data[n];
    }
};

int main()
{
    Solution s;
    assert(s.cuttingRope(2) == 1);
    assert(s.cuttingRope(3) == 2);
    assert(s.cuttingRope(4) == 4);
    assert(s.cuttingRope(5) == 6);
    assert(s.cuttingRope(6) == 9);
    assert(s.cuttingRope(7) == 12);
    assert(s.cuttingRope(8) == 18);
    assert(s.cuttingRope(50) == 86093442);
    assert(s.cuttingRope(100) == 703522804);
    assert(s.cuttingRope(500) == 300460492);
    assert(s.cuttingRope(1000) == 620946522);
}
