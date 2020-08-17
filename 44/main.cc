// 数字序列中某一位的数字,从0开始记位
// 序列：012345678910111213141516171819202122232425...
#include <assert.h>
#include <stdio.h>
#include <cmath>
#include <string>
using namespace std;

class Solution
{
public:
    int findNthDigit(int n)
    {
        if (n <= 9)
        {
            return n;
        }
        int i;
        int base = 10;
        n = n - 10;
        for (i = 1; i < 10; i++)
        {
            if (n > (i + 1) * 9 * pow(10, i))
            {
                n = n - (i + 1) * 9 * pow(10, i);
                base = base * 10;
            }
            else
            {
                break;
            }
        }
        return to_string(base + n / (i + 1))[n % (i + 1)] - '0';
    }
};

int main()
{
    Solution s;
    assert(s.findNthDigit(3) == 3);
    assert(s.findNthDigit(11) == 0);
    assert(s.findNthDigit(50) == 3);
    assert(s.findNthDigit(150) == 8);
    assert(s.findNthDigit(200) == 0);
    assert(s.findNthDigit(500) == 0);
    assert(s.findNthDigit(900) == 6);
    assert(s.findNthDigit(2000) == 0);
    assert(s.findNthDigit(2700) == 6);
}