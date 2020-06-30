// 1~n的整数中1出现的次数

//解法一，按个遍历，计算每个数字中1出现的次数。数字n有logn位，每一位都要访问，所以时间复杂度是nlogn
// 解法二，计算1出现的规律
// https://blog.csdn.net/yi_Afly/article/details/52012593
#include <stdio.h>
#include <assert.h>

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
// 最高支持999
int CountFor1_2(int n)
{
    int count = 0;

    int length = 0;
    int tmp = n;
    while (tmp)
    {
        length++;
        tmp = tmp / 10;
    }
    for (int i = 0; i < length; i++)
    {
    }

    //个位1出现的次数
    count += n / 10;
    if (n % 10 >= 1)
        count++;
    //10位
    count += (n / 100) * 10;
    if (n / 10 % 10 > 1)
    {
        count += 10;
    }
    else if (n / 10 % 10 == 1)
    {
        count += (n % 10 + 1);
    }

    //100位
    count += (n / 1000 * 100);
    if (n / 100 % 10 > 1)
    {
        count += 100;
    }
    else if (n / 100 * 10 == 1)
    {
        count += n % 100 + 1;
    }
    // printf("count:%d\n", count);

    return count;
}

int main()
{
    int n = 534;
    int res = CountFor1_1(n);
    printf("n:%d,res:%d\n", n, res);
    res = CountFor1_2(n);
    printf("n:%d,res:%d\n", n, res);
    n = 504;
    printf("n:%d,res:%d\n", n, CountFor1_1(n));
    printf("n:%d,res:%d\n", n, CountFor1_2(n));
    n = 514;
    printf("n:%d,res:%d\n", n, CountFor1_1(n));
    printf("n:%d,res:%d\n", n, CountFor1_2(n));
    n = 10;
    printf("n:%d,res:%d\n", n, CountFor1_1(n));
    printf("n:%d,res:%d\n", n, CountFor1_2(n));
    n = 1000;
    printf("n:%d,res:%d\n", n, CountFor1_1(n));
    printf("n:%d,res:%d\n", n, CountFor1_2(n));
}