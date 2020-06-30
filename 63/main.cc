// 股票的最大利润

// 1）暴力 O(n*n)
// 2) 求n-1个数字中的最小值，则n位的数字对应的最大利润就是与n-1中最小值的差值。O(n)
#include <stdio.h>
#include <assert.h>

int getMaxProfit_1(int *data, int length, int &maxprofit, int &startvalue, int &endvalue)
{
    if (data == nullptr || length < 2)
    {
        return 0;
    }
    maxprofit = data[1] - data[0];
    int start = 0;
    int end = 1;
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (data[j] - data[i] > maxprofit)
            {
                maxprofit = data[j] - data[i];
                start = i;
                end = j;
            }
        }
    }
    startvalue = data[start];
    endvalue = data[end];
    // printf("max:%d,start:%d,end:%d\n", maxprofit, data[start], data[end]);
    return 1;
}
int getMaxProfit_2(int *data, int length, int &maxprofit, int &startvalue, int &endvalue)
{
    if (data == nullptr || length < 2)
    {
        return 0;
    }
    int min = data[0];
    int minindex = 0;
    int max = data[1] - data[0];
    int start = 0;
    int end = 1;
    for (int i = 1; i < length; i++)
    {
        if (data[i] - min > max)
        {
            start = minindex;
            end = i;
            max = data[i] - min;
        }

        if (data[i] < min)
        {
            min = data[i];
            minindex = i;
        }
    }
    startvalue = data[start];
    endvalue = data[end];

    // printf("max:%d,start:%d,end:%d\n", max, data[start], data[end]);
    return 1;
}
void test1()
{
    int data[] = {9, 11, 8, 5, 7, 12, 16, 14};
    int length = sizeof(data) / sizeof(data[0]);
    int max;
    int start;
    int end;
    int res;
    res = getMaxProfit_1(nullptr, length, max, start, end);
    assert(res == 0);
    res = getMaxProfit_2(nullptr, length, max, start, end);
    assert(res == 0);
}
void test2()
{
    int data[] = {9, 11, 8, 5, 7, 12, 16, 14};
    int length = sizeof(data) / sizeof(data[0]);
    int max;
    int start;
    int end;
    int res;
    res = getMaxProfit_1(data, length, max, start, end);
    assert(res == 1 && max == 11 && start == 5 && end == 16);
    res = getMaxProfit_2(data, length, max, start, end);
    assert(res == 1 && max == 11 && start == 5 && end == 16);
}
void test3()
{
    int data[] = {5, 7, 8, 9, 11, 12, 14, 16};
    int length = sizeof(data) / sizeof(data[0]);
    int max;
    int start;
    int end;
    int res;
    res = getMaxProfit_1(data, length, max, start, end);
    assert(res == 1 && max == 11 && start == 5 && end == 16);
    res = getMaxProfit_2(data, length, max, start, end);
    assert(res == 1 && max == 11 && start == 5 && end == 16);
}
void test4()
{
    int data[] = {16, 14, 12, 11, 9, 8, 7, 5};
    int length = sizeof(data) / sizeof(data[0]);
    int max;
    int start;
    int end;
    int res;
    res = getMaxProfit_1(data, length, max, start, end);
    assert(res == 1 && max == -1 && start == 12 && end == 11);
    res = getMaxProfit_2(data, length, max, start, end);
    assert(res == 1 && max == -1 && start == 12 && end == 11);
}
void test5()
{
    int data[] = {9, 11};
    int length = sizeof(data) / sizeof(data[0]);
    int max;
    int start;
    int end;
    int res;
    res = getMaxProfit_1(data, length, max, start, end);
    assert(res == 1 && max == 2 && start == 9 && end == 11);
    res = getMaxProfit_2(data, length, max, start, end);
    assert(res == 1 && max == 2 && start == 9 && end == 11);
}
void test6()
{
    int data[] = {11, 9};
    int length = sizeof(data) / sizeof(data[0]);
    int max;
    int start;
    int end;
    int res;
    res = getMaxProfit_1(data, length, max, start, end);
    assert(res == 1 && max == -2 && start == 11 && end == 9);
    res = getMaxProfit_2(data, length, max, start, end);
    assert(res == 1 && max == -2 && start == 11 && end == 9);
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
}