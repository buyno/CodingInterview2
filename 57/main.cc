// 和为s的数字：递增的数组，给定一个数s，找两个数和为s，输出任意一对
// 1）暴力
// 2）双指针，从两边往中间找
#include <stdio.h>
#include <assert.h>

int getPair_1(int *data, int length, int s)
{
    if (data == nullptr || length <= 0)
    {
        return 0;
    }
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (data[i] + data[j] == s)
            {
                printf("(%d+%d) = %d\n", data[i], data[j], s);
                return 1;
            }
        }
    }
    return 0;
}

int getPair_2(int *data, int length, int s)
{
    if (data == nullptr || length <= 0)
    {
        return 0;
    }
    int start = 0;
    int end = length - 1;
    while (start < end)
    {
        if (data[start] + data[end] == s)
        {
            printf("(%d+%d) = %d\n", data[start], data[end], s);
            return 1;
        }
        else if (data[start] + data[end] > s)
        {
            end--;
        }
        else
        {
            start++;
        }
    }
    return 0;
}
void test1()
{
    assert(getPair_1(nullptr, 1, 10) == 0);
    assert(getPair_2(nullptr, 1, 10) == 0);
    int data[] = {1, 2, 4, 5, 7, 10, 11, 15};
    assert(getPair_1(data, -10, 10) == 0);
    assert(getPair_2(data, -10, 10) == 0);
}
void test2()
{
    int data[] = {1, 2, 4, 5, 7, 10, 11, 15};
    int s = 15;
    int length = sizeof(data) / sizeof(data[0]);
    assert(getPair_1(data, length, s) == 1);
    assert(getPair_2(data, length, s) == 1);
    s = 10;
    assert(getPair_1(data, length, s) == 0);
    assert(getPair_2(data, length, s) == 0);
    s = 16;
    assert(getPair_1(data, length, s) == 1);
    assert(getPair_2(data, length, s) == 1);
}
int main()
{
    test1();
    test2();
}