// 最小的k个数
// 第一种方法，排序之后输出前k个数，时间复杂度O(nlogn)
// 第二种方法，类似快排的机制，不断的partition直到找到的index是第k个，这时他左边的所有值就是最小的k个数
// 第三种方法，用一个k大小的容器保存最小的k个值

#include <stdio.h>
#include <set>
#include <assert.h>
#include <ctime>
using namespace std;

// 数组无序。
// 按照快排的思路，将数组切割为两部分。直到找到middle处的值，也就是中位数，时间复杂度为O(n)
// 找到中位数之后再判断中位数是否出现次数超过一半(因为如果一个数字出现次数超过一半，那么他一定是排序之后middle处的值)
int partition(int *data, int length, int start, int end)
{
    // printf("%d,%d\n",start,end);
    //随机找一个索引位置(这里没有随机)，然后将所有比numbers[index]小的值移到左边，大的移到右边，返回之后的numbers[index]的索引

    // 选定元素，找到中间的值，将他与末尾元素交换
    int index = (start + end) / 2;
    int tmp = data[index];
    data[index] = data[end];
    data[end] = tmp;
    //从0位开始遍历
    int small = start - 1; //small保存的是已经遍历过的元素中比选定元素小的元素的最后一个
    for (index = start; index < end; index++)
    {
        //遇到比选定元素更小的时，small++，使small指向已经遍历过的元素中比指定元素小的元素的最后一个的下一个
        if (data[index] < data[end])
        {
            small++;
            // 再看small和index的值是否相同，
            // 如果相同，表示目前为止还没有找到一个比选定元素还大的值，就跳过
            // 如果不同，当前遍历到的元素比之前遍历到的某个元素小，需要往前移
            // 与small指向的值交换，这时small++后，small指向的是已遍历值中比选定值大的值的第一个
            if (small != index)
            {
                tmp = data[small];
                data[small] = data[index];
                data[index] = tmp;
            }
        }
    }
    small++;
    tmp = data[small];
    data[small] = data[end];
    data[end] = tmp;
    return small;
}
// O(n)
int *findLeastK_1(int *numbers, int length, int k)
{
    if (numbers == nullptr || length <= 0 || length < k || k <= 0)
    {
        return nullptr;
    }
    int start = 0;
    int index;
    int end = length - 1;
    index = partition(numbers, length, start, end);
    while (index != k - 1) //
    {
        if (index < k - 1)
        {
            start = index + 1;
            index = partition(numbers, length, start, end);
        }
        else
        {
            end = index - 1;
            index = partition(numbers, length, start, end);
        }
    }
    int *res = new int[k];
    for (int i = 0; i < k; i++)
    {
        res[i] = numbers[i];
    }
    return res;
}
// nlogk
int *findLeastK_2(int *numbers, int length, int k)
{
    if (numbers == nullptr || length <= 0 || length < k || k <= 0)
    {
        return nullptr;
    }
    // greater<int>让set变成从大到小排序，.begin()就能直接得到最大值，而不用再遍历，复杂度为logn
    multiset<int, greater<int>> set;
    for (int i = 0; i < length; i++)
    {
        if (set.size() < k)
        {
            set.insert(numbers[i]);
        }
        else
        {
            // 从set里找到最大值
            auto iter_max = set.begin();
            // for(auto it = set.begin();it != set.end();it++){
            //     if(*it > *iter_max){
            //         iter_max = it;
            //     }
            // }
            // 如果numbers[i]比set的最大值还小，替换
            if (numbers[i] < *iter_max)
            {
                set.erase(iter_max);
                set.insert(numbers[i]);
            }
        }
    }
    int *res = new int[set.size()];

    auto it = set.begin();
    int i = 0;
    while (it != set.end())
    {
        res[i++] = *it;
        it++;
    }
    return res;
}
void test1()
{
    printf("=================test1=================\n");
    // numbers为空
    int *numbers = nullptr;
    int length = 1;
    int k = 4;
    int *res = findLeastK_1(numbers, length, k);
    assert(res == nullptr);
    res = findLeastK_2(numbers, length, k);
    assert(res == nullptr);
    //length为0
    length = 0;
    numbers = new int[1];
    res = findLeastK_1(numbers, length, k);
    assert(res == nullptr);
    res = findLeastK_2(numbers, length, k);
    assert(res == nullptr);
    delete[] numbers;
    // k小于等于0
    length = 1;
    numbers = new int[1];
    k = 0;
    res = findLeastK_1(numbers, length, k);
    assert(res == nullptr);
    res = findLeastK_2(numbers, length, k);
    assert(res == nullptr);
    delete[] numbers;

    printf("test pass.\n");
    printf("=======================================\n\n");
}
void test2()
{
    printf("=================test2=================\n");
    int numbers[] = {3, 2, 1};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    int k = 0;
    int *res;

    printf("original array:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    res = findLeastK_1(numbers, length, k);
    printf("方法一,最小的%d个值是：\n", k);
    for (int i = 0; i < k; i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");
    delete[] res;
    res = nullptr;

    res = findLeastK_2(numbers, length, k);
    printf("方法二,最小的%d个值是：\n", k);
    for (int i = 0; i < k; i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");
    delete[] res;
    res = nullptr;
    printf("=======================================\n\n");
}
void test3()
{
    printf("=================test3=================\n");
    int numbers[] = {4, 5, 1, 2, 6, 7, 3, 8};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    int k = 4;
    int *res;

    printf("original array:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    res = findLeastK_1(numbers, length, k);
    printf("方法一,最小的%d个值是：\n", k);
    for (int i = 0; i < k; i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");
    delete[] res;
    res = nullptr;

    res = findLeastK_2(numbers, length, k);
    printf("方法二,最小的%d个值是：\n", k);
    for (int i = 0; i < k; i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");
    delete[] res;
    res = nullptr;
    printf("=======================================\n\n");
}
void test4()
{
    printf("=================test4=================\n");
    int numbers[] = {4, 5, 1, 2, 6, 7, 3, 8};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    int k = 1;
    int *res;

    printf("original array:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    res = findLeastK_1(numbers, length, k);
    printf("方法一,最小的%d个值是：\n", k);
    for (int i = 0; i < k; i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");
    delete[] res;
    res = nullptr;

    res = findLeastK_2(numbers, length, k);
    printf("方法二,最小的%d个值是：\n", k);
    for (int i = 0; i < k; i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");
    delete[] res;
    res = nullptr;
    printf("=======================================\n\n");
}
void test5()
{
    printf("=================test5=================\n");
    int numbers[] = {4, 5, 1, 2, 6, 7, 3, 8};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    int k = length;
    int *res;

    printf("original array:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    res = findLeastK_1(numbers, length, k);
    printf("方法一,最小的%d个值是：\n", k);
    for (int i = 0; i < k; i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");
    delete[] res;
    res = nullptr;

    res = findLeastK_2(numbers, length, k);
    printf("方法二,最小的%d个值是：\n", k);
    for (int i = 0; i < k; i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");
    delete[] res;
    res = nullptr;
    printf("=======================================\n\n");
}
// 性能测试
void test6()
{
    printf("=============Preformance Test==========\n");
    //修改长度
    int length = 100000;
    int numbers[length];
    for (int i = 0; i < length; i++)
        numbers[i] = i;
    int k = 2;
    int *res;
    int times = 10000;
    printf("times:%d\n", times);
    printf("length:%d\n", length);
    time_t start, end;

    start = time(0);
    for (int i = 0; i < times; i++)
    {
        res = findLeastK_1(numbers, length, k);
        assert(res[0] == 1 || res[0] == 0);
        assert(res[1] == 0 || res[1] == 1);
        delete[] res;
        res = nullptr;
    }
    end = time(0);
    printf("method 1 spend time:%.1f\n", difftime(end, start));

    start = time(0);
    for (int i = 0; i < times; i++)
    {
        res = findLeastK_2(numbers, length, k);
        assert(res[0] == 1 || res[0] == 0);
        assert(res[1] == 0 || res[1] == 1);
        delete[] res;
        res = nullptr;
    }
    end = time(0);
    printf("methos 2 spend time:%.1f\n", difftime(end, start));

    printf("=======================================\n\n");
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