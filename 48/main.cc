// 最长不含重复字符的子字符串，返回长度

// 思路：动态规划。f(i)表示以第i个字符结尾的字符串中最长的不重复子串。
// 当data[i]之前不曾出现过时，f(i) = f(i-1)+1
// 当data[i]出现过，计算data[i]与上次出现的距离d。如果上次出现在f(i-1)代表的字符串之前，也就是d>f(i-1)，那么f(i) = f(i-1)+1；
// 如果上次出现在f(i-1)代表的字符串之中，f(i) = d
#include <stdio.h>
#include "string"
#include <assert.h>

using namespace std;
//计算该char上次出现的位置与当前位置的距离，从1开始,没出现过就是-1

int getNoneRepeatArray(const char *str, int length)
{
    if (str == nullptr || length <= 0)
    {
        return -1;
    }

    int tmpdata[length]; //tmpdata[i]表示以第i个字母结尾的字符串中不重复且最长的长度
    tmpdata[0] = 1;
    for (int i = 1; i < length; i++)
    {
        tmpdata[i] = 0;
    }
    int lastindex[26]; //辅助数组，记录字符上次出现的位置，-1表示未出现过

    for (int i = 0; i < 26; i++)
        lastindex[i] = -1;
    lastindex[str[0] - 'a'] = 0;
    for (int i = 1; i < length; i++)
    {
        int d;
        //如果没有出现过，就d=-1并记录这次的位置
        if (lastindex[str[i] - 'a'] == -1)
        {
            d = -1;
            lastindex[str[i] - 'a'] = i;
        }
        //如果出现过，就计算d，并记录这次的位置
        else
        {
            d = i - lastindex[str[i] - 'a'];
            lastindex[str[i] - 'a'] = i;
        }
        //如果字母上次出现的位置很远，或者没有出现过
        if (d > tmpdata[i - 1] || d < 1)
        {
            tmpdata[i] = tmpdata[i - 1] + 1;
        }
        else
        {
            tmpdata[i] = d;
        }
    }
    //找最大的字串，并返回
    int maxlength = tmpdata[0];
    for (int i = 1; i < length; i++)
    {
        if (tmpdata[i] > maxlength)
        {
            maxlength = tmpdata[i];
        }
    }
    return maxlength;
}
void test1()
{
    int res = getNoneRepeatArray(nullptr, 0);
    assert(res == -1);
}
void test2()
{
    string str = "arabcacfr";
    int res = getNoneRepeatArray(str.c_str(), 0);
    assert(res == -1);
}
void test3()
{
    string str = "arabcacfr";
    int res = getNoneRepeatArray(str.c_str(), str.length());
    assert(res == 4);
}
void test4()
{
    string str = "b";
    int res = getNoneRepeatArray(str.c_str(), str.length());
    assert(res == 1);
}
void test5()
{
    string str = "cccccc";
    int res = getNoneRepeatArray(str.c_str(), str.length());
    assert(res == 1);
}
void test6()
{
    string str = "armdbecfn";
    int res = getNoneRepeatArray(str.c_str(), str.length());
    assert(res == 9);
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