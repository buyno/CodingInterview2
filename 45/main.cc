// 把数组排列成最小的数
// 1)全排列，比较每种情况生成的值的大小，得到最小值
// 2)用自定义的compare函数排序，得到最小值

// 两种sort：sort/qsort
// qsort是标准c库提供的，sort是STL提供的，sort效率更高
// void qsort(void *base, size_t num, size_t size,
//            int (*compar)(const void *, const void *));
// template <class RandomAccessIterator, class Compare>
// void sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);
// qsort直接比较，sort需要先生成对应的vector
// qsort的compare函数是 int compare(const void *num1,const void *num2);
// sort的compare函数是 bool compare(int a,int b);

#include <string>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

long minvalue = LONG_MAX;  //方法一，保存最小值
short inputError = 0;      //用全局变量作为错误处理
const int MAXLENGTH = 100; //字符串最大长度

void getAllNumbers(int *numbers, int length, int *substr, int sublength)
{
    if (sublength <= 0)
    {
        char str[MAXLENGTH];
        for (int i = 0; i < MAXLENGTH; i++)
            str[i] = 0;
        int n = 0;
        for (int i = 0; i < length; i++)
        {
            n += sprintf(str + n, "%d", numbers[i]);
            if (n > MAXLENGTH)
            {
                printf("length > %d\n", MAXLENGTH);
                minvalue = LONG_MAX;
                return;
            }
        }

        long res = atol(str);
        if (res < minvalue)
        {
            minvalue = res;
        }
        return;
    }
    else
    {
        for (int i = 0; i < sublength; i++)
        {
            int tmp = substr[i];
            substr[i] = substr[0];
            substr[0] = tmp;
            getAllNumbers(numbers, length, substr + 1, sublength - 1);
            tmp = substr[i];
            substr[i] = substr[0];
            substr[0] = tmp;
        }
    }
}
// 全排列，比较每种情况生成的值的大小，得到最小值
long getMinValue_1(int *numbers, int length)
{
    if (numbers == nullptr || length <= 0)
    {
        inputError = 1;
        return 0;
    }
    getAllNumbers(numbers, length, numbers, length);
    long res = minvalue;
    minvalue = LONG_MAX;
    return res;
}
bool compare(int x, int y)
{
    char *number1 = new char[MAXLENGTH + 1];
    char *number2 = new char[MAXLENGTH + 1];
    char *number12 = new char[MAXLENGTH + 1];
    char *number21 = new char[MAXLENGTH + 1];
    for (int i = 0; i < MAXLENGTH + 1; i++)
    {
        number1[i] = 0;
        number2[i] = 0;
        number12[i] = 0;
        number21[i] = 0;
    }
    sprintf(number1, "%d", x);
    sprintf(number2, "%d", y);

    strcpy(number12, number1);
    strcat(number12, number2);
    strcpy(number21, number2);
    strcat(number21, number1);
    auto res = strcmp(number12, number21);
    delete[] number1;
    delete[] number2;
    delete[] number12;
    delete[] number21;

    return res < 0;
}

// 用自定义的compare函数排序，得到最小的一种排列
long getMinValue_2(int *numbers, int length)
{
    if (numbers == nullptr || length <= 0)
    {
        inputError = 1;
        return 0;
    }
    vector<int> vec;
    for (int i = 0; i < length; i++)
    {
        vec.push_back(numbers[i]);
    }
    //STL库的sort函数，自定义的compare规则
    sort(vec.begin(), vec.end(), compare);

    char str[MAXLENGTH * 2];
    for (int i = 0; i < MAXLENGTH * 2; i++)
        str[i] = 0;
    int n = 0;
    for (auto x : vec)
    {
        n += sprintf(str + n, "%d", x);
        if (n > MAXLENGTH * 2)
        {
            printf("length > %d\n", MAXLENGTH * 2);
            return -1;
        }
    }
    long res = atol(str);
    return res;
}
void test1()
{
    int *numbers = nullptr;
    int length = 0;
    long res = getMinValue_1(numbers, length);
    assert(res == 0 && inputError == 1);
    inputError = 0;
    res = getMinValue_2(numbers, length);
    assert(res == 0 && inputError == 1);
    inputError = 0;
}
void test2()
{
    int numbers[] = {3, 32, 321};
    int length = 3;
    long res;
    res = getMinValue_1(numbers, length);
    assert(res == 321323);
    res = getMinValue_2(numbers, length);
    assert(res == 321323);
}
void test3()
{
    int numbers[] = {3, 323, 32123};
    int length = 3;
    long res;
    res = getMinValue_1(numbers, length);
    assert(res == 321233233);
    res = getMinValue_2(numbers, length);
    assert(res == 321233233);
}
void test4()
{
    int numbers[] = {1, 11, 111};
    int length = 3;
    long res;
    res = getMinValue_1(numbers, length);
    assert(res == 111111);
    res = getMinValue_2(numbers, length);
    assert(res == 111111);
}
void test5()
{
    int numbers[] = {32123};
    int length = 1;
    long res;
    res = getMinValue_1(numbers, length);
    assert(res == 32123);
    res = getMinValue_2(numbers, length);
    assert(res == 32123);
}
void test6()
{
    int numbers[] = {3, 5, 1, 4, 2};
    int length = 5;
    long res;
    res = getMinValue_1(numbers, length);
    assert(res == 12345);
    res = getMinValue_2(numbers, length);
    assert(res == 12345);
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
//3, 5, 1, 4, 2
//