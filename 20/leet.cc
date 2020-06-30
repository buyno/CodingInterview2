#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <math.h>
#include <limits.h>
#include <stack>
#include <unordered_map>

using namespace std;
// 1234  0345  1.23  +123 -123 -1.23 .23 -.23 1e20 -2e-20 4e-4 -1e4 1.3e10  -1.3e20
// false : 2e-2.3 3e2.3
class Solution
{
public:
    bool isNumber(string s)
    {
        //删除前后空格
        s = deleteblank(s);
        if (s.length() == 0)
        {
            return false;
        }
        int index = 0;

        int tmp;
        // +/-
        if (s[index] == '+' || s[index] == '-')
        {
            index++;
        }
        //first
        tmp = getFirstOrSecondNumber(s, index);
        //判断有无first这个数
        int firstexist = 1;
        if (tmp == index)
        {
            firstexist = 0;
        }
        if (tmp >= s.length())
        {
            return true;
        }
        index = tmp;
        //如果有小数
        if (s[index] == '.')
        {
            index++;
            tmp = getFirstOrSecondNumber(s, index);
            //要求first/second至少有一个，如果first和second都没有，那return false
            if (tmp == index && !firstexist)
            {
                return false;
            }
            index = tmp;
        }
        else
        {
            if (!firstexist)
            {
                return false;
            }
        }
        if (index >= s.length())
        {
            return true;
        }
        if (s[index] == 'e')
        {
            index++;
        }
        else
        {
            return false;
        }
        if (index < s.length() && s[index] == '+' || s[index] == '-')
        {
            index++;
        }
        // third,要求必须存在数字，也就是说返回值要比index大
        tmp = getThirdNumber(s, index);
        if (tmp == index)
        {
            return false;
        }
        if (tmp != s.length())
        {
            return false;
        }
        return true;
    }
    string deleteblank(string str)
    {
        int start = 0;
        int end = str.length() - 1;
        while (start < str.length() && str[start] == ' ')
        {
            start++;
        }
        while (end >= 0 && str[end] == ' ')
        {
            end--;
        }
        return str.substr(start, end - start + 1);
    }
    int getFirstOrSecondNumber(string s, int index)
    {
        // 0123
        while (index < s.length() && s[index] == '0')
        {
            index++;
        }
        while (index < s.length() && s[index] >= '0' && s[index] <= '9')
        {
            index++;
        }
        return index;
    }
    int getThirdNumber(string s, int index)
    {
        while (index < s.length() && s[index] >= '0' && s[index] <= '9')
        {
            index++;
        }
        return index;
    }
};

int main()
{
    {
        Solution s;
        string str = "23.23";
        assert(s.getFirstOrSecondNumber(str, 0) == 2);
        assert(s.getFirstOrSecondNumber("-23.34", 1) == 3);
        assert(s.getFirstOrSecondNumber("-23", 1) == 3);
        assert(s.getFirstOrSecondNumber("-023", 1) == 4);
    }
    // 1234  0345  1.23  +123 -123 -1.23 .23 -.23 1e20 -2e-20 4e-4 -1e4 1.3e10  -1.3e20
    // false : 2e-2.3 3e2.3 a123 12a3 1.a23
    {
        Solution s;
        assert(s.isNumber("1234") == true);
        assert(s.isNumber("0345") == true); //23e023
        assert(s.isNumber("1.23") == true);
        assert(s.isNumber("+123") == true);
        assert(s.isNumber("-123") == true);
        assert(s.isNumber("-1.23") == true);
        assert(s.isNumber(".23") == true);
        assert(s.isNumber("-.23") == true);
        assert(s.isNumber("1e20") == true);
        assert(s.isNumber("-2e-20") == true);
        assert(s.isNumber("4e-4") == true);
        assert(s.isNumber("-1e4") == true);
        assert(s.isNumber("1.3e10") == true);
        assert(s.isNumber("-1.3e20") == true);
        assert(s.isNumber("12.") == true);
        assert(s.isNumber("-1e-16") == true);
        assert(s.isNumber("  12.") == true);
        assert(s.isNumber("12.  ") == true);
        assert(s.isNumber("  123  ") == true);

        assert(s.isNumber("2e-2.3") == false);
        assert(s.isNumber("3e2.3") == false);
        assert(s.isNumber("a123") == false);
        assert(s.isNumber("12a3") == false);
        assert(s.isNumber("1.a23") == false);
        assert(s.isNumber(".23.") == false);
        assert(s.isNumber("1e") == false);
        assert(s.isNumber("1e.") == false);
        assert(s.isNumber(".23.") == false);
        assert(s.isNumber(".23.") == false);
        assert(s.isNumber(".23.") == false);
        assert(s.isNumber(".23.") == false);
        assert(s.isNumber("+-5") == false);
        assert(s.isNumber("-1E-16") == false);
        assert(s.isNumber(".") == false);
        assert(s.isNumber("19e") == false);
        assert(s.isNumber("e23") == false);
        assert(s.isNumber(" ") == false);
        assert(s.isNumber("96 e5") == false);
        assert(s.isNumber("23.") == true);
    }
    {
        Solution s;

        assert(s.deleteblank("aaa") == "aaa");
        assert(s.deleteblank("   aaa   ") == "aaa");
        assert(s.deleteblank("   ") == "");
    }
}