// 1~n的整数中1出现的次数

// 解法一，按个遍历，计算每个数字中1出现的次数。数字n有logn位，每一位都要访问，所以时间复杂度是nlogn
// 解法二，计算1出现的规律
// https://blog.csdn.net/yi_Afly/article/details/52012593
// https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/mian-shi-ti-43-1n-zheng-shu-zhong-1-chu-xian-de-2/
// 将数分为三部分，cur/high/low
// 209  1   3
// high cur low bit=bit*10
// 当cur=0时，这位上出现1的次数为high*bit
// 当cur=1时，次数为high*bit+low+1
// 当cur>1时，次数为(high+1)*bit
// 依次遍历每一位即可
#include <stdio.h>
#include <assert.h>
#include <math.h>

// 普通解法
int CountForANumber(int n)
{
    int count = 0;
    while (n)
    {
        if (n % 10 == 1)
        {
            count++;
        }
        n = n / 10;
    }
    return count;
}
int CountFor1_1(int n)
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += CountForANumber(i);
    }
    return res;
}
// 高效解法
class Solution
{
public:
    int countDigitOne(int n)
    {
        int high = n / 10;
        int low = 0;
        int cur = n % 10;
        long bit = 1;
        long result = 0;
        int temp = n;
        int times = 0;
        while (temp)
        {
            times++;
            temp = temp / 10;
        }
        while (times)
        {
            if (cur == 0)
            {
                result += high * bit;
            }
            else if (cur == 1)
            {
                result += high * bit + low + 1;
            }
            else
            {
                result += (high + 1) * bit;
            }
            low = low + cur * bit;
            cur = high % 10;
            high = high / 10;
            bit = bit * 10;
            times--;
        }
        return result;
    }
};

int main()
{

    {
        int n = 534;
        Solution s;
        assert(CountFor1_1(n) == s.countDigitOne(n));
    }
    {
        int n = 504;
        Solution s;
        assert(CountFor1_1(n) == s.countDigitOne(n));
    }
    {
        int n = 514;
        Solution s;
        assert(CountFor1_1(n) == s.countDigitOne(n));
    }
    {
        int n = 10;
        Solution s;
        assert(CountFor1_1(n) == s.countDigitOne(n));
    }
    {
        int n = 1000;
        Solution s;
        assert(CountFor1_1(n) == s.countDigitOne(n));
    }
    {
        int n = 10000;
        Solution s;
        assert(CountFor1_1(n) == s.countDigitOne(n));
    }

    {
        int n = 100000;
        Solution s;
        assert(CountFor1_1(n) == s.countDigitOne(n));
    }
    {
        int n = 1000000;
        Solution s;
        assert(CountFor1_1(n) == s.countDigitOne(n));
    }
    {
        int n = 10000000;
        Solution s;
        assert(CountFor1_1(n) == s.countDigitOne(n));
    }
    {
        int n = 100000000;
        Solution s;
        assert(CountFor1_1(n) == s.countDigitOne(n));
    }
    {
        int n = 1000000000;
        Solution s;
        assert(CountFor1_1(n) == s.countDigitOne(n));
    }
    {
        int n = 903130401;
        Solution s;
        assert(CountFor1_1(n) == s.countDigitOne(n));
    }
    // {
    //     int n = pow(2, 31) - 1;
    //     Solution s;
    //     assert(CountFor1_1(n) == s.countDigitOne(n));
    // }
}