// 求数组中数值与下标相等的元素。数组单调递增，且值唯一

// 1) 顺序
// 2）二分查找的思路：
#include <assert.h>
#include <stdio.h>

int valueEqualIndex_1(int *data, int length)
{
    if (data == nullptr || length <= 0)
    {
        return -1;
    }
    for (int i = 0; i < length; i++)
    {
        if (data[i] == i)
        {
            return data[i];
        }
    }
    return -1;
}
int valueEqualIndex_2(int *data, int length)
{
    if (data == nullptr || length <= 0)
    {
        return -1;
    }
    int start = 0;
    int end = length - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (data[mid] == mid)
        {
            return data[mid];
        }
        else if (data[mid] > mid)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}
void test1()
{
    int data[] = {-3, -1, 1, 3, 5};
    int length = sizeof(data) / sizeof(data[0]);

    assert(valueEqualIndex_1(nullptr, length) == -1);
    assert(valueEqualIndex_2(nullptr, length) == -1);
    assert(valueEqualIndex_1(data, 0) == -1);
    assert(valueEqualIndex_2(data, 0) == -1);
}
void test2()
{
    int data[] = {-3, -1, 1, 3, 5};
    int length = sizeof(data) / sizeof(data[0]);
    assert(valueEqualIndex_1(data, length) == 3);
    assert(valueEqualIndex_2(data, length) == 3);
}
void test4()
{
    int data[] = {0, 3, 5, 20, 25};
    int length = sizeof(data) / sizeof(data[0]);
    assert(valueEqualIndex_1(data, length) == 0);
    assert(valueEqualIndex_2(data, length) == 0);
}
void test5()
{
    int data[] = {-3, -1, 1, 2, 4};
    int length = sizeof(data) / sizeof(data[0]);
    assert(valueEqualIndex_1(data, length) == 4);
    assert(valueEqualIndex_2(data, length) == 4);
}
void test6()
{
    int data[] = {-3, -1, 1, 2, 5};
    int length = sizeof(data) / sizeof(data[0]);
    assert(valueEqualIndex_1(data, length) == -1);
    assert(valueEqualIndex_2(data, length) == -1);
}
void test7()
{
    int data[] = {-3};
    int length = sizeof(data) / sizeof(data[0]);
    assert(valueEqualIndex_1(data, length) == -1);
    assert(valueEqualIndex_2(data, length) == -1);
}
void test8()
{
    int data[] = {0};
    int length = sizeof(data) / sizeof(data[0]);
    assert(valueEqualIndex_1(data, length) == 0);
    assert(valueEqualIndex_2(data, length) == 0);
}
int main()
{
    test1();
    test2();
    test4();
    test5();
    test6();
    test7();
    test8();
}