// 数值的整数次方，不考虑大数

#include <assert.h>
#include <stdio.h>
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
    return tmp;
}
int main()
{
    assert(power(2, 3) == 8);
    assert(power(2, 0) == 1);
    assert(power(2, -1) == 0.5);
    assert(power(0, 3) == 0);
    assert(power(0, -1) == 0);
    assert(power(0, 0) == 0);
    assert(power(-2, 0) == 1);
    assert(power(-2, 3) == -8);
    assert(power(-2, -2) == 0.25);
}