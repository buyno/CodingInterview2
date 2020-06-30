// 打印从1到最大的n位数

// int最高到9位

#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;

int addone(char *nums)
{
    int length = 0; //
    char *mark = nums;
    while (*mark)
    {
        length++;
        mark++;
    }
    int bit = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        int tempNumber = nums[i] - '0';
        if (i == length - 1)
        {
            tempNumber++;
        }
        tempNumber += bit;
        bit = 0;
        if (tempNumber >= 10)
        {
            bit = tempNumber / 10;
            nums[i] = tempNumber % 10 + '0';
            if (i == 0 && bit == 1)
            {
                return 0;
            }
        }
        else
        {
            nums[i] = tempNumber + '0';
        }
    }
    // printf("length:%d\n",length);
    return 1;
}

void printNumber(char *nums)
{
    int start = 0;
    char *iter = nums;
    while (*iter == '0')
    {
        iter++;
    }

    printf("%s\n", iter);
}

void print(int n)
{
    vector<int> vec;
    if (n <= 0)
        return;
    char *nums = new char[n + 1];
    for (int i = 0; i < n; i++)
    {
        nums[i] = '0';
    }
    nums[n] = 0;

    while (addone(nums))
    {
        vec.push_back(atoi(nums));
        printNumber(nums);
    }
}

int main()
{
    print(-2);
    print(6);
}
