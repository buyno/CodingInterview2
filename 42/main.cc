// 连续子数组的最大和

// 解：maxSum[i]表示以numbers[i]结尾的所有序列中的和最大的序列
// 而以numbers[i]结尾的所有序列中的最大和要么是数字本身(numbers[i-1] < 0时)，要么是maxSum[i-1]+numbers[i](numbers[i-1] > 0时)
#include <stdio.h>
#include <climits>
#include <assert.h>

int getMaxSubSum(int *numbers, int length)
{
    if (numbers == nullptr || length == 0)
    {
        return -1;
    }
    int maxSum[length] = {numbers[0]}; //以numbers[i]结尾的序列的最大和
    int maxvalue = numbers[0];         //总计的最大和
    for (int i = 1; i < length; i++)
        maxSum[i] = 0;
    for (int i = 1; i < length; i++)
    {
        if (maxSum[i - 1] < 0)
        {
            maxSum[i] = numbers[i];
        }
        else
        {
            maxSum[i] = maxSum[i - 1] + numbers[i];
        }

        if (maxSum[i] > maxvalue)
        {
            maxvalue = maxSum[i];
        }
    }
    return maxvalue;
}
void test1()
{
    int *numbers = nullptr;

    int length = 0;
    int maxsum = getMaxSubSum(numbers, length);
    assert(maxsum == -1);
}
void test2()
{
    int numbers[] = {};

    int length = 0;
    int maxsum = getMaxSubSum(numbers, length);
    assert(maxsum == -1);
}
void test3()
{
    int numbers[] = {-2};

    int length = 1;
    int maxsum = getMaxSubSum(numbers, length);
    assert(maxsum == -2);
}
void test4()
{
    int numbers[] = {1, -2, 3, 10, -4, 7, 2, -5};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    int maxsum = getMaxSubSum(numbers, length);
    assert(maxsum == 18);
}
void test5()
{
    int numbers[] = {1, 3, 10, 7, 2};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    int maxsum = getMaxSubSum(numbers, length);
    assert(maxsum == 23);
}
void test6()
{
    int numbers[] = {-5, -4, -7, -2, -5};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    int maxsum = getMaxSubSum(numbers, length);
    assert(maxsum == -2);
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