// 把数字翻译成字符串,有多少种不同的翻译方法

//1）递归
//2）循环。。。。

#include <stdio.h>
#include <assert.h>
#include <string>
using namespace std;

void translate(char *data, int length, int &count)
{
    if (length == 0)
    {
        count++;
        return;
    }

    else if (length == 1)
    {
        count++;
        return;
    }
    else
    {
        translate(data + 1, length - 1, count);
        int num = (data[0] - '0') * 10 + data[1] - '0';
        if (num <= 25 && num >= 10)
        {
            translate(data + 2, length - 2, count);
        }
    }
}
int translateCount(long number)
{
    if (number < 0)
        number = -number;
    int length = 0;
    //得到数字的长度
    long tmp = number;
    while (tmp)
    {
        length++;
        tmp = tmp / 10;
    }
    //数字转换为一个字符串
    char *data = new char[length + 1];
    sprintf(data, "%ld", number);

    int count = 0;
    translate(data, length, count);
    return count;
}
//循环
// f(n) = f(n-1) + f(n-2),n>=2且10<=data[n]*10+data[n-1]<=25
//      = f(n-1)
// f(0) = 1
// f(1) = 2,10<=data[1]*10+data[0]<=25
//      = 1 其他
int translateCount_2(long number)
{
    if (number < 0)
        number = -number;
    string data = to_string(number);
    int length = data.length();
    if (length == 1)
    {
        return 1;
    }
    int res[length];
    res[length - 1] = 1;
    int tmp = (data[length - 2] - '0') * 10 + (data[length - 1] - '0');
    if (tmp <= 25 && tmp >= 10)
    {
        res[length - 2] = 2;
    }
    else
    {
        res[length - 2] = 1;
    }

    for (int i = length - 3; i >= 0; i--)
    {
        int twobit = (data[i] - '0') * 10 + (data[i + 1] - '0');
        if (twobit <= 25 && twobit >= 10)
        {
            res[i] = res[i + 1] + res[i + 2];
        }
        else
        {
            res[i] = res[i + 1];
        }
    }
    return res[0];
}
int main()
{
    long number = 12258;
    int res = translateCount(number);
    assert(res == 5);
    res = translateCount_2(number);
    assert(res == 5);

    number = 1;
    res = translateCount(number);
    assert(res == 1);
    res = translateCount_2(number);
    assert(res == 1);

    number = -10;
    res = translateCount(number);
    assert(res == 2);
    res = translateCount_2(number);
    assert(res == 2);

    number = 125;
    res = translateCount(number);
    assert(res == 3);
    res = translateCount_2(number);
    assert(res == 3);

    number = 126;
    res = translateCount(number);
    assert(res == 2);
    res = translateCount_2(number);
    assert(res == 2);

    number = 426;
    res = translateCount(number);
    assert(res == 1);
    res = translateCount_2(number);
    assert(res == 1);

    number = 100;
    res = translateCount(number);
    assert(res == 2); //baa,ka，没有1,(00)
    res = translateCount(number);
    assert(res == 2);
}