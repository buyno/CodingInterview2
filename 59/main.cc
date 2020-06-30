// 队列的最大值,滑动窗口的最大值。
// k=3,{2, 3, 4, 2, 6, 2, 5, 1} -> {4, 4, 6, 6, 6, 5}

// 利用双端队列，队列的front是最大值，back是最小值。
// 新到一个值，如果比当前的最大值还大，那其他值肯定不再可能是最大值，去掉。
// 如果比当前最大值小，可能会再之后成为最大值，所以加到队列末尾
// 同时还要清理超过滑动窗口的过期数字。
#include <vector>
#include <stdio.h>
#include <assert.h>
#include <deque> //双端队列

using namespace std;

vector<int> getMaxValues(int *data, int length, int size)
{
    deque<int> maxindex;
    vector<int> result;
    if (data == nullptr || length <= 0 || length < size || size <= 0)
    {
        return result;
    }

    //先处理初始的k个值
    for (int i = 0; i < size; i++)
    {
        //先清理更小的元素
        while (!maxindex.empty() && data[i] > data[maxindex.back()])
        {
            maxindex.pop_back();
        }
        maxindex.push_back(i);
    }
    result.push_back(data[maxindex.front()]);
    // 按照规则逐个加
    for (int i = size; i < length; i++)
    {
        //如果大，移除所有之前的
        if (data[i] >= data[maxindex.front()])
        {
            while (!maxindex.empty())
            {
                maxindex.pop_back();
            }
            maxindex.push_back(i);
        }
        else
        {
            //如果小
            //先去掉所有比data[i]小的，因为他们不可能成为最大值了
            while (!maxindex.empty() && data[maxindex.back()] < data[i])
            {
                maxindex.pop_back();
            }
            // 还要移除过期的
            while (!maxindex.empty() && i - maxindex.front() >= size)
            {
                maxindex.pop_front();
            }
            //再加到队列尾
            maxindex.push_back(i);
        }
        result.push_back(data[maxindex.front()]);
    }

    return result;
}
// 空数组
// 正常值
// 递增数列
// 递减
// 一个值
// 两个值
// 窗口大小为0/1/2/数组长度/大于数组长度
void test1()
{
    int size = 3;
    auto result = getMaxValues(nullptr, 10, size);
    assert(result.empty());
}
void test2()
{
    int data[] = {2, 3, 4, 2, 6, 2, 5, 1};
    int expected[] = {4, 4, 6, 6, 6, 5};
    int length = sizeof(data) / sizeof(data[0]);
    int size = 3;
    auto result = getMaxValues(data, length, size);
    printf("result:   ");
    for (auto x : result)
    {
        printf("%d ", x);
    }
    printf("\nexpected: ");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", expected[i]);
    }
    printf("\n");
}
void test3()
{
    int data[] = {1, 2, 3, 4, 6, 15, 21};
    int expected[] = {3, 4, 6, 15, 21};
    int length = sizeof(data) / sizeof(data[0]);
    int size = 3;
    auto result = getMaxValues(data, length, size);
    printf("result:   ");
    for (auto x : result)
    {
        printf("%d ", x);
    }
    printf("\nexpected: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", expected[i]);
    }
    printf("\n");
}
void test4()
{
    int data[] = {23, 13, 11, 10, 6, 5, 1};
    int expected[] = {23, 13, 11, 10, 6};
    int length = sizeof(data) / sizeof(data[0]);
    int size = 3;
    auto result = getMaxValues(data, length, size);
    printf("result:   ");
    for (auto x : result)
    {
        printf("%d ", x);
    }
    printf("\nexpected: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", expected[i]);
    }
    printf("\n");
}
void test5()
{
    int data[] = {2};
    int length = sizeof(data) / sizeof(data[0]);
    int size = 3;
    auto result = getMaxValues(data, length, size);
    assert(result.empty());
}
void test6()
{
    int data[] = {2, 3, 4, 2, 6, 2, 5, 1};
    int length = sizeof(data) / sizeof(data[0]);
    int size = 0;
    auto result = getMaxValues(data, length, size);
    assert(result.empty());
}
void test7()
{
    int data[] = {2, 3, 4, 2, 6, 2, 5, 1};
    int expected[] = {2, 3, 4, 2, 6, 2, 5, 1};
    int length = sizeof(data) / sizeof(data[0]);
    int size = 1;
    auto result = getMaxValues(data, length, size);
    printf("result:   ");
    for (auto x : result)
    {
        printf("%d ", x);
    }
    printf("\nexpected: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", expected[i]);
    }
    printf("\n");
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