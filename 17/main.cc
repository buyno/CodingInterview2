// 打印从1到最大的n位数

// 限制：n最高到9位
// leetcode上的题有问题，本来应该是考察大数问题的，位数也不应该有限制
// 但是他也是有苦衷的。因为9位数，10位数以上的结果保存到vector中会消耗很大的内存(>6GB)(内存耗光之后就是：terminate called after throwing an instance of 'std::bad_alloc')
// 如果不保存他又不能验证结果是否正确

// 最后：不用vector保存，直接输出(输出结果也要一段时间)
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    void printNumbers(int n)
    {

        string str(n + 1, '0');
        string end(n, '9');
        end = "0" + end;
        int i = 0;
        while (str != end)
        {
            strAddOne(str);
            cout << deletezero(str) << endl;
        }
        return;
    }
    //输出的时候去掉前面的0
    string deletezero(string &str)
    {
        int index = 0;
        while (str[index] == '0')
        {
            index++;
        }
        return str.substr(index);
    }
    // 处理大数+1
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
    }
};
int main()
{
    Solution s;
    s.printNumbers(9);
}
