// 扑克牌中的顺子：随机抽五张牌，判断是不是顺子，A,2-10,J,Q,K,大王小王看作任意数字

#include <stdio.h>
#include <assert.h>

int continuous(int *data, int length)
{
    if (data == nullptr || length != 5)
    {
        return 0;
    }
    //排序,O(n*n)。可以改用sort或者qsort

    for (int i = 0; i < length - 1; i++)
    {
        int minindex = i;
        for (int j = i + 1; j < length; j++)
        {
            if (data[minindex] > data[j])
            {
                minindex = j;
            }
        }
        int tmp = data[minindex];
        data[minindex] = data[i];
        data[i] = tmp;
    }
    //对子
    for (int i = 0; i < length - 1; i++)
    {
        if (data[i] != 0 && data[i] == data[i + 1])
        {
            return 0;
        }
    }
    //统计大小王个数
    //统计空位数
    int king = 0;
    int blank = 0;
    for (int i = 0; i < length; i++)
    {
        if (data[i] == 0)
        {
            king++;
        }
        else
        {
            break;
        }
    }
    int startindex = king;
    //计算空位也可以遍历时，计算相邻两个数的差值，加和差值，就是空位数
    blank = data[length - 1] - data[startindex] - (length - 1 - startindex);

    if (king >= blank)
    {
        // printf("shun xu\n");
        return 1;
    }
    else
    {
        // printf("bu shun xu\n");
        return 0;
    }
}
void test1()
{
    int data[] = {2, 3, 7, 0, 4};
    int length = sizeof(data) / sizeof(data[0]);
    assert(continuous(nullptr, length) == 0);
    assert(continuous(data, 0) == 0);
    assert(continuous(data, -1) == 0);
}
void test2()
{
    int data[] = {2, 3, 6, 5, 4};
    int length = sizeof(data) / sizeof(data[0]);
    assert(continuous(data, length) == 1);
}
void test3()
{
    int data[] = {2, 3, 7, 5, 4};
    int length = sizeof(data) / sizeof(data[0]);
    assert(continuous(data, length) == 0);
}
void test4()
{
    int data[] = {2, 0, 6, 5, 0};
    int length = sizeof(data) / sizeof(data[0]);
    assert(continuous(data, length) == 1);
}
void test5()
{
    int data[] = {2, 3, 0, 5, 0};
    int length = sizeof(data) / sizeof(data[0]);
    assert(continuous(data, length) == 1);
}
void test6()
{
    int data[] = {6, 3, 0, 5, 0};
    int length = sizeof(data) / sizeof(data[0]);
    assert(continuous(data, length) == 1);
}
void test7()
{
    int data[] = {2, 5, 0, 5, 0};
    int length = sizeof(data) / sizeof(data[0]);
    assert(continuous(data, length) == 0);
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
}