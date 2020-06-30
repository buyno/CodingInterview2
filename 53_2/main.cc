// 0~n-1中缺失的数字：n个数字只缺一个，找出这个数字

// 1）计算总的和，n*n/2，的差值，就是差的这个数。缺点，要遍历整个数组，复杂度O(n)
// 2）仿二分查找，如果中间值等于它的index，缺失的值肯定在右边，如果中间值大于它的index并且他左边的值等于index，那么他就是第一个不等index的，就是要找的数字，。。不可能小于。。。
#include <assert.h>
#include <stdio.h>

int getMissingNumber(int *data, int length)
{
    if (data == nullptr || length <= 0)
    {
        return -1;
    }
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += data[i];
    }
    return (length) * (length + 1) / 2 - sum;
}
int getMissingNumber_2(int *data, int length)
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
            start = mid + 1;
            continue;
        }
        else if (data[mid] > mid)
        {
            if (data[mid - 1] == mid - 1)
            {
                return mid;
            }
            end = mid - 1;
            continue;
        }
        else
        {
            printf("error\n");
            break;
        }
    }
    return start;
}
void test1()
{
    assert(getMissingNumber(nullptr, 2) == -1);
    assert(getMissingNumber_2(nullptr, 2) == -1);
    int num[] = {2, 3};
    assert(getMissingNumber(num, 0) == -1);
    assert(getMissingNumber_2(num, 0) == -1);
}
void test2()
{
    int data[] = {0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    int length = sizeof(data) / sizeof(data[0]);
    int res;
    res = getMissingNumber(data, length);
    assert(res == 7);
    res = getMissingNumber_2(data, length);
    assert(res == 7);
}
void test3()
{
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    int length = sizeof(data) / sizeof(data[0]);
    int res;
    res = getMissingNumber(data, length);
    assert(res == 0);
    assert(getMissingNumber_2(data, length) == 0);
}
void test4()
{
    int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int length = sizeof(data) / sizeof(data[0]);
    int res;
    res = getMissingNumber(data, length);
    assert(res == 17);
    res = getMissingNumber_2(data, length);
    assert(res == 17);
}
void test5()
{
    int data[] = {0, 1, 2};
    int length = sizeof(data) / sizeof(data[0]);
    int res;
    res = getMissingNumber(data, length);
    assert(res == 3);
    res = getMissingNumber_2(data, length);
    assert(res == 3);
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
}