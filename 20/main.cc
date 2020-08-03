// 表示数值的字符串，判断字符串是否表示一个数字
// 比如+100,-100,2e5,3.14,-1E-10,.12

// (1) [+/-]整数部分[.小数部分[e/E指数]]
// (2) .小数[e/E指数]
//
// https://github.com/zhedahht/CodingInterviewChinese2/blob/master/20_NumericStrings/NumericStrings.cpp

// E=e
#include <string>
#include <iostream>
#include <assert.h>
using namespace std;

class Solution
{
public:
    bool isNumber(string s)
    {
        //删掉前后空格
        deleteblank(s);
        //
        int part1 = 0, part2 = 0, part3 = 0;
        if (s.length() == 0)
        {
            return false;
        }
        int index = 0;
        //处理第一部分
        if (!firstOrThirdPart(s, index, part1))
        {
            return false;
        }
        //处理第二部分
        if (!secondPart(s, index, part2))
        {
            return false;
        }

        //如果第一第二部分都没出现
        if (!part1 && !part2)
        {
            return false;
        }

        if (index < s.length() && !(s[index] == 'e' || s[index] == 'E'))
        {
            return false;
        }
        if (index == s.length())
        {
            return true;
        }
        index++;
        if (index == s.length())
        {
            return false;
        }
        //处理第三部分
        if (!firstOrThirdPart(s, index, part3) || index < s.length())
        {
            return false;
        }
        return true;
    }
    //不符合规范时返回0
    int firstOrThirdPart(string &s, int &index, int &part)
    {
        // int part1exist = 0;
        if (s[index] == '+' || s[index] == '-')
        {
            index++;
        }
        if (index == s.length())
        {
            return 0;
        }
        while (index < s.length() && s[index] >= '0' && s[index] <= '9')
        {
            part = 1;
            index++;
        }
        return 1;
    }
    int secondPart(string &s, int &index, int &part)
    {
        if (s[index] == '.')
        {
            index++;
            while (index < s.length() && s[index] >= '0' && s[index] <= '9')
            {
                part = 1;
                index++;
            }
        }
        return 1;
    }
    void deleteblank(string &str)
    {
        int start = 0;
        while (start < str.length() && str[start] == ' ')
        {
            start++;
        }
        int end = str.length() - 1;
        while (end >= 0 && str[end] == ' ')
        {
            end--;
        }
        if (start <= end)
        {
            str = str.substr(start, end - start + 1);
        }
        else
        {
            str = "";
        }
    }
};
int isNumber(string str)
{
    Solution s;
    return s.isNumber(str);
}
int main()
{
    Solution s;

    assert(s.isNumber("100") == 1);
    assert(s.isNumber("1.23e10") == 1);
    assert(s.isNumber(".23e10") == 1);
    assert(s.isNumber("+100") == 1);
    assert(s.isNumber("-100") == 1);
    assert(s.isNumber("2e5") == 1);
    assert(s.isNumber("3.14") == 1);
    assert(s.isNumber("-1E-10") == 1);
    assert(s.isNumber(".12") == 1);
    assert(s.isNumber("123.45e+6") == 1);
    assert(s.isNumber("600.") == 1);
    assert(s.isNumber("-.123") == 1);
    assert(s.isNumber("-1E-16") == 1);
    assert(s.isNumber("1.79769313486232E+308") == 1);
    assert(s.isNumber(".14") == 1);
    assert(s.isNumber("14.") == 1);
    assert(s.isNumber(".") == 0);

    assert(s.isNumber("12e") == 0);
    assert(s.isNumber("1a3.14") == 0);
    assert(s.isNumber("1+23") == 0);
    assert(s.isNumber("1.2.3") == 0);
    assert(s.isNumber("+-5") == 0);
    assert(s.isNumber("12e+5.4") == 0);
    assert(s.isNumber(".") == 0);
    assert(s.isNumber(".e1") == 0);
    assert(s.isNumber("e1") == 0);
    assert(s.isNumber("+.") == 0);
    assert(s.isNumber("") == 0);
    assert(s.isNumber("..12") == 0);
    assert(s.isNumber("1..2") == 0);
    assert(s.isNumber(".12.") == 0);
    //leetcode
    assert(isNumber("1234") == true);
    assert(isNumber("0345") == true); //23e023
    assert(isNumber("1.23") == true);
    assert(isNumber("+123") == true);
    assert(isNumber("-123") == true);
    assert(isNumber("-1.23") == true);
    assert(isNumber(".23") == true);
    assert(isNumber("-.23") == true);
    assert(isNumber("1e20") == true);
    assert(isNumber("-2e-20") == true);
    assert(isNumber("4e-4") == true);
    assert(isNumber("-1e4") == true);
    assert(isNumber("1.3e10") == true);
    assert(isNumber("-1.3e20") == true);
    assert(isNumber("12.") == true); //!!!
    assert(isNumber("-1e-16") == true);

    assert(isNumber("  12.") == true);
    assert(isNumber("12.  ") == true);
    assert(isNumber("  123  ") == true);

    assert(isNumber("2e-2.3") == false);
    assert(isNumber("3e2.3") == false);
    assert(isNumber("a123") == false);
    assert(isNumber("12a3") == false);
    assert(isNumber("1.a23") == false);
    assert(isNumber(".23.") == false);
    assert(isNumber("1e") == false);
    assert(isNumber("1e.") == false);
    assert(isNumber(".23.") == false);
    assert(isNumber(".23.") == false);
    assert(isNumber(".23.") == false);
    assert(isNumber(".23.") == false);
    assert(isNumber("+-5") == false);
    // assert(isNumber("-1E-16") == false);
    assert(isNumber(".") == false);
    assert(isNumber("19e") == false);
    assert(isNumber("e23") == false);
    assert(isNumber(" ") == false);
    assert(isNumber("96 e5") == false);
    assert(isNumber("96e+") == false);
    assert(isNumber("56670244781.326") == true);
    assert(isNumber("+") == false);
}