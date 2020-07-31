// 打印从1到最大的n位数

// *int最高到9位
// leetcode上的题有问题，本来应该是考察大数问题的，位数也不应该有限制
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <iostream>
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
class Solution
{
public:
    vector<int> printNumbers(int n)
    {
        // 因为返回值限制为int，所以还是不能处理大数问题
        vector<int> result(pow(10, n) - 1);
        // int lastnumber = pow(10, n) - 1;
        // for (int i = 1; i <= lastnumber; i++)
        // {
        //     result[i - 1] = i;
        // }
        string str(n + 1, '0');
        string end(n, '9');
        end = "0" + end;
        int i = 0;
        while (str != end)
        {
            // result[i++] = stoi(str);
            strAddOne(str);
            // cout << str << endl;
            result[i++] = stoi(str);
        }
        return result;
    }
    void strAddOne(string &str)
    {
        int bit = 1;
        for (int i = str.size() - 1; i >= 0; i--)
        {
            int value = str[i] - '0' + bit;
            if (value >= 10)
            {
                str[i] = value - 10 + '0';
                bit = 1;
            }
            else
            {
                str[i] = value + '0';
                bit = 0;
            }
        }
        // cout << str << endl;
    }
};
int main()
{
    Solution s;
    auto res = s.printNumbers(2);
    for (auto x : res)
    {
        cout << x << endl;
    }
}
