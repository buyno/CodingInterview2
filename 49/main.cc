//丑数
// 因数只包含2，3，5的数称为丑数，求从小到大第1500个丑数。
// 6，8是丑数，14不是。1是第一个丑数
//
// 1,2,3,4,5,6,8,9,10,12,15,16,18,20

// 方法二：循环，下一个数一定是前面的已知丑数分别*2,*3,*5的最小值
#include <stdio.h>
#include <assert.h>

int isUglyNumber(int number)
{
    while (number % 2 == 0)
    {
        number = number / 2;
    }

    while (number % 3 == 0)
        number = number / 3;
    while (number % 5 == 0)
        number = number / 5;
    if (number == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int getUglyNumber(int maxindex)
{
    if (maxindex <= 0)
    {
        return -1;
    }
    int count = 0;
    int number = 1;

    while (count < maxindex)
    {
        if (isUglyNumber(number))
            count++;
        number++;
    }
    return number - 1;
}
int getUglyNumber_2(int maxindex)
{
    if (maxindex <= 0)
    {
        return -1;
    }
    int tmp[maxindex];
    for (int i = 0; i < maxindex; i++)
    {
        tmp[i] = 0;
    }
    tmp[0] = 1;
    int count = 1;
    int number2, number3, number5;
    while (count < maxindex)
    {
        for (int i = 0; i < count; i++)
        {
            if (tmp[i] * 2 > tmp[count - 1])
            {
                number2 = tmp[i] * 2;
                break;
            }
        }
        for (int i = 0; i < count; i++)
        {
            if (tmp[i] * 3 > tmp[count - 1])
            {
                number3 = tmp[i] * 3;
                break;
            }
        }
        for (int i = 0; i < count; i++)
        {
            if (tmp[i] * 5 > tmp[count - 1])
            {
                number5 = tmp[i] * 5;
                break;
            }
        }
        if (number2 <= number3 && number2 <= number5)
        {
            tmp[count] = number2;
        }
        else if (number3 <= number5)
        {
            tmp[count] = number3;
        }
        else
        {
            tmp[count] = number5;
        }
        count++;
    }
    return tmp[maxindex - 1];
}
int main()
{
    // 1,2,3,4,5,6,8,9,10,12,15,16,18,20
    int res;
    res = getUglyNumber_2(0);
    assert(res == -1);
    res = getUglyNumber_2(1);
    assert(res == 1);
    res = getUglyNumber_2(2);
    assert(res == 2);
    res = getUglyNumber_2(3);
    assert(res == 3);
    res = getUglyNumber_2(4);
    assert(res == 4);
    res = getUglyNumber_2(5);
    assert(res == 5);
    res = getUglyNumber_2(6);
    assert(res == 6);
    res = getUglyNumber_2(7);
    assert(res == 8);
    res = getUglyNumber_2(8);
    assert(res == 9);
    res = getUglyNumber_2(9);
    assert(res == 10);
    res = getUglyNumber_2(10);
    assert(res == 12);
    res = getUglyNumber_2(11);
    assert(res == 15);
    res = getUglyNumber_2(12);
    assert(res == 16);
    res = getUglyNumber_2(13);
    assert(res == 18);
    res = getUglyNumber_2(14);
    assert(res == 20);
    res = getUglyNumber_2(64);
    assert(res == 450);
    res = getUglyNumber_2(1500);
    assert(res == 859963392);

    res = getUglyNumber(0);
    assert(res == -1);
    res = getUglyNumber(1);
    assert(res == 1);
    res = getUglyNumber(2);
    assert(res == 2);
    res = getUglyNumber(3);
    assert(res == 3);
    res = getUglyNumber(4);
    assert(res == 4);
    res = getUglyNumber(5);
    assert(res == 5);
    res = getUglyNumber(6);
    assert(res == 6);
    res = getUglyNumber(7);
    assert(res == 8);
    res = getUglyNumber(8);
    assert(res == 9);
    res = getUglyNumber(9);
    assert(res == 10);
    res = getUglyNumber(10);
    assert(res == 12);
    res = getUglyNumber(11);
    assert(res == 15);
    res = getUglyNumber(12);
    assert(res == 16);
    res = getUglyNumber(13);
    assert(res == 18);
    res = getUglyNumber(14);
    assert(res == 20);
    res = getUglyNumber(64);
    assert(res == 450);
    res = getUglyNumber(1500);
    assert(res == 859963392);
}