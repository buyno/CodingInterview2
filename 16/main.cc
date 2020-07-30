// 数值的整数次方，不考虑大数

#include <assert.h>
#include <stdio.h>
#include <iostream>
using namespace std;
// double power(int base, int component)
// {
//     if (base == 0)
//         return 0;
//     if (component == 0)
//         return 1;
//     if (base != 0 && component < 0)
//     {
//         component = -component;
//         double res = 1;
//         for (int i = 1; i <= component; i++)
//         {
//             res = res * base;
//         }
//         return 1 / res;
//     }
//     double res = 1;
//     for (int i = 1; i <= component; i++)
//     {
//         res = res * base;
//     }
//     return res;
// }
double power(int x, int n)
{
    if (x == 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    int negative = 0;
    if (n < 0)
    {
        negative = 1;
        n = -n;
    }
    int index = 1;
    double tmp = x;
    while (index * 2 < n)
    {
        tmp = tmp * tmp;
        index *= 2;
    }
    for (int i = 0; i < n - index; i++)
    {
        tmp *= x;
    }
    if (negative == 1)
    {
        return 1 / tmp;
    }
    return tmp;
}

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
        {
            return 1;
        }
        //+-
        int positive = 1;
        long temp;
        if (n < 0)
        {
            positive = 0;
            temp = n;
            temp = -temp; //直接取反会越界
        }
        else
        {
            temp = n;
        }
        if (temp == 1)
        {
            return positive ? x : 1.0 / x;
        }
        double result = 1;
        result = myPow(x, temp / 2);
        result *= result;
        if (temp % 2)
        {
            result *= x;
        }
        // cout << (positive ? result : 1.0 / result) << endl;
        return positive ? result : 1.0 / result;
    }
};
int main()
{
    // assert(power(2, 3) == 8);
    // assert(power(2, 0) == 1);
    // assert(power(2, -1) == 0.5);
    // assert(power(0, 3) == 0);
    // assert(power(0, -1) == 0);
    // assert(power(0, 0) == 0);
    // assert(power(-2, 0) == 1);
    // assert(power(-2, 3) == -8);
    // assert(power(-2, -2) == 0.25);
    Solution s;

    assert(s.myPow(2, 3) == 8);
    assert(s.myPow(2, -3) == 1.0 / 8);
    // cout << 1.0 / 8 << endl;
    assert(s.myPow(2, 10) == 1024);
    assert(s.myPow(0.5, 2) == 0.25);
    assert(s.myPow(123, 0) == 1);
    assert(s.myPow(1, 200) == 1);
    assert(s.myPow(1, -2147483648) == 1);
}