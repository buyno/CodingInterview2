// 排序数组中查找数字
// 统计一个数字在一个有序递增的数组中出现的次数
// 1）顺序遍历，计数。但是这样就浪费了原数组“有序”的特性
// 2）仿二分查找，如果中间值就是要查找的值，那么看前面是否还出现过，如果没有出现就找到了值的左边界，如果出现过那就在左边继续二分查找
//    得到左右边界之后就得到了出现次数。复杂度logn
#include <assert.h>
int getTimes_1(int *data, int length, int num)
{
    if (data == nullptr || length <= 0)
        return -1;
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (data[i] == num)
        {
            count++;
        }
    }
    return count;
}
int gettimes(int *data, int start, int end, int num)
{
    if (start >= end)
    {
        if (start == end && data[start] == num)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (data[(start + end) / 2] > num)
    {
        return gettimes(data, start, (start + end) / 2 - 1, num);
    }
    else if (data[(start + end) / 2] < num)
    {
        return gettimes(data, (start + end) / 2 + 1, end, num);
    }
    else
    {
        int left, right;
        for (int i = (start + end) / 2; i >= start; i--)
        {
            if (data[i] != num)
            {
                left = i + 1;
                break;
            }
        }
        for (int i = (start + end) / 2; i <= end; i++)
        {
            if (data[i] != num)
            {
                right = i - 1;
                break;
            }
        }
        return right - left + 1;
    }
}
int getTimes_2(int *data, int length, int num)
{
    if (data == nullptr || length <= 0)
        return -1;
    int res;
    res = gettimes(data, 0, length - 1, num);
    return res;
}
void test1()
{
    int *data = nullptr;
    int length = 2;
    assert(getTimes_1(data, length, 3) == -1);
    assert(getTimes_2(data, length, 3) == -1);
    data = new int[10];
    length = 0;
    assert(getTimes_1(data, length, 3) == -1);
    assert(getTimes_2(data, length, 3) == -1);
    delete[] data;
}
void test2()
{
    int data[] = {10};
    int length = 1;
    assert(getTimes_1(data, length, 2) == 0);
    assert(getTimes_2(data, length, 2) == 0);
    assert(getTimes_1(data, length, 10) == 1);
    assert(getTimes_2(data, length, 10) == 1);
}
void test3()
{
    int data[] = {5, 10};
    int length = 2;
    assert(getTimes_1(data, length, 2) == 0);
    assert(getTimes_2(data, length, 2) == 0);
    assert(getTimes_1(data, length, 10) == 1);
    assert(getTimes_2(data, length, 10) == 1);
}
void test4()
{
    int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
    int length = sizeof(data) / sizeof(data[0]);
    assert(getTimes_1(data, length, 3) == 4);
    assert(getTimes_2(data, length, 3) == 4);
    assert(getTimes_1(data, length, 2) == 1);
    assert(getTimes_2(data, length, 2) == 1);
    assert(getTimes_1(data, length, 20) == 0);
    assert(getTimes_2(data, length, 20) == 0);
}
void test5()
{
    int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
    int length = sizeof(data) / sizeof(data[0]);
    assert(getTimes_1(data, length, 1) == 1);
    assert(getTimes_2(data, length, 1) == 1);
    assert(getTimes_1(data, length, 5) == 1);
    assert(getTimes_2(data, length, 5) == 1);
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
}