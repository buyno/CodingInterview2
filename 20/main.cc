// 表示数值的字符串，判断字符串是否表示一个数字
// 比如+100,-100,2e5,3.14,-1E-10,.12

// (1) [+/-]整数部分[.小数部分[e/E指数]]
// (2) .小数[e/E指数]
//
// https://github.com/zhedahht/CodingInterviewChinese2/blob/master/20_NumericStrings/NumericStrings.cpp

// 没有考虑前后空格，E不行
#include <string>
#include <iostream>
#include <assert.h>
using namespace std;

int isNumber(string str)
{
    if (str.empty())
    {
        return 0;
    }
    int start = 0;
    if (str[0] == '+' || str[0] == '-')
    {
        start = 1;
    }
    // (1) [+/-]整数部分[.小数部分[e/E指数]]
    if (str[start] != '.')
    {
        // 整数部分
        int mark = start;
        while (mark < str.length() && str[mark] >= '0' && str[mark] <= '9')
        {
            mark++;
        }
        // 如果没有整数部分，错误
        if (mark == start)
        {
            return 0;
        }
        //没有小数或指数部分，直接到末尾，比如20，正确
        if (mark == str.length())
        {
            return 1;
        }
        start = mark;
        // 以.结尾，比如400.
        if (start == str.length() - 1 && str[start] == '.')
        {
            return 1;
        }
        if (start < str.length() - 1 && str[start] == '.')
        {
            // 小数部分
            start++; //跳过.
            mark = start;
            while (mark < str.length() && str[mark] >= '0' && str[mark] <= '9')
            {
                mark++;
            }
            if (mark == start)
            {
                return 0; //比如400.a
            }
        }
        // 指数部分
        start = mark;
        if (start <= str.length() - 1 && (str[start] == 'E' || str[start] == 'e')) //E不行
        {
            start++;
            if (start < str.length() && (str[start] == '+' || str[start] == '-'))
            {
                start++;
            }
            mark = start;
            while (mark < str.length() && str[mark] >= '0' && str[mark] <= '9')
            {
                mark++;
            }
            // 20e/20e30a
            if (!(mark == str.length() && mark != start))
            {
                return 0;
            }
        }
        else if (start <= str.length() - 1 && str[start] != 'E' && str[start] != 'e')
        {
            return 0; //比如400.12a
        }
        return 1;
    }
    else
    {
        // (2) .小数[e/E指数]
        start++;
        int mark = start;
        while (mark < str.length() && str[mark] >= '0' && str[mark] <= '9')
        {
            mark++;
        }
        if (mark == start)
        {
            return 0;
        }
        start = mark;
        if (mark < str.length() && (str[mark] == 'e' || str[mark] == 'E'))
        {
            mark++;
        }
        if (mark < str.length() && mark == start)
        {
            return 0;
        }
        return 1;
    }
}
int main()
{
    assert(isNumber("100") == 1);
    assert(isNumber("1.23e10") == 1);
    assert(isNumber(".23e10") == 1);
    assert(isNumber("+100") == 1);
    assert(isNumber("-100") == 1);
    assert(isNumber("2e5") == 1);
    assert(isNumber("3.14") == 1);
    assert(isNumber("-1E-10") == 1);
    assert(isNumber(".12") == 1);
    assert(isNumber("123.45e+6") == 1);
    assert(isNumber("600.") == 1);
    assert(isNumber("-.123") == 1);
    assert(isNumber("-1E-16") == 1);
    assert(isNumber("1.79769313486232E+308") == 1);

    assert(isNumber("12e") == 0);
    assert(isNumber("1a3.14") == 0);
    assert(isNumber("1+23") == 0);
    assert(isNumber("1.2.3") == 0);
    assert(isNumber("+-5") == 0);
    assert(isNumber("12e+5.4") == 0);
    assert(isNumber(".") == 0);
    assert(isNumber(".e1") == 0);
    assert(isNumber("e1") == 0);
    assert(isNumber("+.") == 0);
    assert(isNumber("") == 0);
    assert(isNumber("..12") == 0);
    assert(isNumber("1..2") == 0);
    assert(isNumber(".12.") == 0);
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
    assert(isNumber("12.") == true);
    assert(isNumber("-1e-16") == true);

    // assert(isNumber("  12.") == true);
    // assert(isNumber("12.  ") == true);
    // assert(isNumber("  123  ") == true);

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
}