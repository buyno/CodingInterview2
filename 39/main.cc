// 数组中出现次数超过一半的数字

// 测试：
// 时间复杂度测试
// 循环数：10000000
// 方法一：map
// 74.000000s
// 方法二:unordered_map
// 63.000000s
// 方法三:排序后逐个查找
// 17.000000s
// 方法四:快排
// 1.000000s
// 1.000000s
// 方法五:计数超过一般
// 1.000000s
#include <map>
#include <unordered_map>
#include <assert.h>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;
// 用map保存每个数字出现的次数
// return:过半1，未过半0
// 时间复杂度O(nlog(n))
int ifOverHalf_1(int *numbers, int length)
{
    if (numbers == nullptr || length <= 0)
    {
        // printf("没有过半\n");
        return 0;
    }
    map<int, int> data;
    for (int i = 0; i < length; i++)
    {
        if (data.find(numbers[i]) != data.end())
        {
            data[numbers[i]]++;
        }
        else
        {
            data[numbers[i]] = 1;
        }
        if (data[numbers[i]] > length / 2)
        {
            // printf("%d 过半\n",numbers[i]);
            return 1;
        }
    }
    // printf("没有过半\n");
    return 0;
}
// 用unordered_map保存每个数字出现的次数
// 时间复杂度不是O(n)
int ifOverHalf_2(int *numbers, int length)
{
    if (numbers == nullptr || length <= 0)
    {
        // printf("没有过半\n");
        return 0;
    }
    unordered_map<int, int> data;
    for (int i = 0; i < length; i++)
    {
        if (data.find(numbers[i]) != data.end())
        {
            data[numbers[i]]++;
        }
        else
        {
            data[numbers[i]] = 1;
        }
        if (data[numbers[i]] > length / 2)
        {
            // printf("%d 过半\n",numbers[i]);
            return 1;
        }
    }
    // printf("没有过半\n");
    return 0;
}
// 先排序,再逐个查找
int ifOverHalf_3(int *numbers, int length)
{
    if (numbers == nullptr)
    {
        return 0;
    }
    vector<int> vec(numbers, numbers + length);
    //O(nlogn)
    sort(vec.begin(), vec.end());

    auto it = vec.begin();
    int number = *it;
    int count = 0;
    while (it != vec.end())
    {
        if (*it == number)
        {
            count++;
            it++;
        }
        else
        {
            if (count > length / 2)
            {
                return 1;
            }
            else
            {
                count = 1;
                number = *it;
                it++;
            }
        }
    }
    if (count > length / 2)
    {
        return 1;
    }
    else
        return 0;
}
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

int ifOverHalf_4(int *numbers, int length)
{
    if (numbers == nullptr || length <= 0)
    {
        return 0;
    }

    int middle = length / 2;
    int end = length - 1;
    int start = 0;
    //不断的partition，使得中间位的数字比所有左边的数字大，比右边的小
    int key = partition(numbers, length, start, end);
    while (key != middle)
    {
        if (key < middle)
        {
            start = key + 1;
            key = partition(numbers, length, start, end);
        }
        else
        {
            end = key - 1;
            key = partition(numbers, length, start, end);
        }
    }
    int num = numbers[middle];
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (numbers[i] == num)
        {
            count++;
        }
    }
    if (count > length / 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// 利用数组的特点，如果一个数占比超过一半，那么他出现的次数一定比其他所有数字出现的次数总和都多
// 只需两个int，一个表示数，一个表示这个数出现的次数
// 遍历数组，如果当前值与保存值相等，count++；如果不相等，count--，count如果减为0，那么保存至更新为当前值，count=1
// 那么如果存在一个出现次数过半的数，那一定是最后保存的数
// 优点：相比方法4，不用修改数组

int ifOverHalf_5(int *numbers, int length)
{
    if (numbers == nullptr || length <= 0)
    {
        return 0;
    }
    int number = numbers[0];
    int count = 1;
    for (int i = 0; i < length; i++)
    {
        if (numbers[i] == number)
        {
            count++;
        }
        else
        {
            count--;
            if (count <= 0)
            {
                number = numbers[i];
                count = 1;
            }
        }
    }
    count = 0;
    for (int i = 0; i < length; i++)
    {
        if (numbers[i] == number)
        {
            count++;
        }
    }
    if (count > length / 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void test1()
{
    int *numbers = nullptr;
    int res;
    res = ifOverHalf_1(numbers, 0);
    assert(res == 0);
    res = ifOverHalf_2(numbers, 0);
    assert(res == 0);
}
void test2()
{
    int numbers[] = {1};
    int res;
    res = ifOverHalf_1(numbers, sizeof(numbers) / sizeof(numbers[0]));
    assert(res == 1);
    res = ifOverHalf_2(numbers, sizeof(numbers) / sizeof(numbers[0]));
    assert(res == 1);
}
void test3()
{
    int numbers[] = {1, 2, 3, 2, 2, 2, 5, 4, 4, 5, 6, 3, 3, 2};
    int res = ifOverHalf_1(numbers, sizeof(numbers) / sizeof(numbers[0]));
    assert(res == 0);
    // printf("res:%d\n",res);
    res = ifOverHalf_2(numbers, sizeof(numbers) / sizeof(numbers[0]));
    // printf("res:%d\n",res);
    assert(res == 0);
}
void test4()
{
    int numbers[] = {1, 2, 3, 2, 2, 2, 4, 5, 2};
    int res = ifOverHalf_1(numbers, sizeof(numbers) / sizeof(numbers[0]));
    assert(res == 1);
    // printf("res:%d\n",res);
    res = ifOverHalf_2(numbers, sizeof(numbers) / sizeof(numbers[0]));
    // printf("res:%d\n",res);
    assert(res == 1);
}
void test5()
{
    // 循环次数
    int times = 10000000;
    time_t starttime;
    time_t endtime;
    double spendtime;
    printf("时间复杂度测试\n");
    printf("循环数：%d\n", times);
    printf("方法一：\n");
    starttime = time(0);

    int *numbers;
    int res;
    int length;

    length = 14;
    numbers = new int[length]{1, 2, 3, 2, 2, 2, 5, 4, 4, 5, 6, 3, 3, 2};
    for (int i = 0; i < times; i++)
    {
        res = ifOverHalf_1(numbers, length);
        assert(res == 0);
    }
    delete[] numbers;

    endtime = time(0);
    spendtime = difftime(endtime, starttime);
    printf("%fs\n", spendtime);

    printf("方法二:\n");
    starttime = time(0);

    length = 14;
    numbers = new int[length]{1, 2, 3, 2, 2, 2, 5, 4, 4, 5, 6, 3, 3, 2};
    for (int i = 0; i < times; i++)
    {
        res = ifOverHalf_2(numbers, length);
        assert(res == 0);
    }
    delete[] numbers;

    endtime = time(0);
    spendtime = difftime(endtime, starttime);
    printf("%fs\n", spendtime);

    printf("方法三:\n");
    starttime = time(0);

    length = 14;
    numbers = new int[length]{1, 2, 3, 2, 2, 2, 5, 4, 4, 5, 6, 3, 3, 2};
    for (int i = 0; i < times; i++)
    {
        res = ifOverHalf_3(numbers, length);
        assert(res == 0);
    }
    delete[] numbers;

    endtime = time(0);
    spendtime = difftime(endtime, starttime);
    printf("%fs\n", spendtime);

    printf("方法四:\n");
    starttime = time(0);

    length = 14;
    numbers = new int[length]{1, 2, 3, 2, 2, 2, 5, 4, 4, 5, 6, 3, 3, 2};
    for (int i = 0; i < times; i++)
    {
        res = ifOverHalf_4(numbers, length);
        assert(res == 0);
    }
    delete[] numbers;

    endtime = time(0);
    spendtime = difftime(endtime, starttime);
    printf("%fs\n", spendtime);

    endtime = time(0);
    spendtime = difftime(endtime, starttime);
    printf("%fs\n", spendtime);

    printf("方法五:\n");
    starttime = time(0);

    length = 14;
    numbers = new int[length]{1, 2, 3, 2, 2, 2, 5, 4, 4, 5, 6, 3, 3, 2};
    for (int i = 0; i < times; i++)
    {
        res = ifOverHalf_5(numbers, length);
        assert(res == 0);
    }
    delete[] numbers;

    endtime = time(0);
    spendtime = difftime(endtime, starttime);
    printf("%fs\n", spendtime);
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    // int numbers[] = {1,2,3,2,2,2,5,2,6};
    // int res = ifOverHalf_5(numbers,sizeof(numbers)/sizeof(numbers[0]));
    // assert(res==0);
}