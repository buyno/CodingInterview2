// 数组中的逆序对

// 递归的思想：左半边与右半边比较，存在逆序对就+1，但是要先在内部的左半与右半比较，内部比较完之后会归并排序

//data里从start到end的数字，先找逆序对数，再归并排序到tmp中,再将tmp中的值复制会data中
#include <stdio.h>
#include <assert.h>

int getReversePair(int *data, int *tmp, int start, int end)
{
    if (start >= end)
    {
        return 0;
    }
    int count = 0;
    count += getReversePair(data, tmp, start, start + (end - start) / 2);
    count += getReversePair(data, tmp, start + (end - start) / 2 + 1, end);
    int p1 = start + (end - start) / 2;
    int p2 = end;
    while (p1 >= start)
    {
        p2 = end;
        while (p2 >= start + (end - start) / 2 + 1)
        {
            if (data[p1] > data[p2]) //相等不算逆序
            {
                count += (p2 - (start + (end - start) / 2 + 1) + 1);
                break;
            }
            p2--;
        }
        p1--;
    }
    //归并
    p1 = start + (end - start) / 2;
    p2 = end;
    int index = end;
    while (p1 >= start && p2 >= start + (end - start) / 2 + 1)
    {
        if (data[p1] >= data[p2])
        {
            tmp[index--] = data[p1--];
        }
        else
        {
            tmp[index--] = data[p2--];
        }
    }
    while (p1 >= start)
    {
        tmp[index--] = data[p1--];
    }
    while (p2 >= start + (end - start) / 2 + 1)
    {
        tmp[index--] = data[p2--];
    }
    index = start;
    while (index <= end)
    {
        data[index] = tmp[index];
        index++;
    }
    return count;
}

int getReversePair(int *data, int length)
{
    if (data == nullptr || length <= 0)
    {
        return -1;
    }
    int *tmp = new int[length];
    int count = getReversePair(data, tmp, 0, length - 1);
    delete[] tmp;
    return count;
}

void test1()
{
    int *data = nullptr;
    int length = 2;
    int res = getReversePair(data, length);
    assert(res == -1);
    data = new int[2];
    length = 0;
    res = getReversePair(data, length);
    assert(res == -1);
    delete[] data;
}

void test2()
{
    int data[] = {1, 2, 3, 4, 7, 6, 5};
    int length = sizeof(data) / sizeof(data[0]);

    int res = getReversePair(data, length);
    assert(res == 3);
}
void test3()
{
    int data[] = {4, 5, 6, 7};
    int length = sizeof(data) / sizeof(data[0]);

    int res = getReversePair(data, length);
    assert(res == 0);
}
void test4()
{
    int data[] = {1, 2, 1, 2, 1};
    int length = sizeof(data) / sizeof(data[0]);

    int res = getReversePair(data, length);
    assert(res == 3);
}
void test5()
{
    int data[] = {1, 2, 1, 2, 1};
    int length = sizeof(data) / sizeof(data[0]);

    int res = getReversePair(data, length);
    assert(res == 3);
}
void test6()
{
    int data[] = {3};
    int length = sizeof(data) / sizeof(data[0]);

    int res = getReversePair(data, length);
    assert(res == 0);
}
void test7()
{
    int data[] = {7, 3};
    int length = sizeof(data) / sizeof(data[0]);

    int res = getReversePair(data, length);
    assert(res == 1);
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