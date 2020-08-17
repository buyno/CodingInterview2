// 翻转字符串:"i am a student."->"student. a am i"
// 1) 先全部反转，再每个单词反转
// 2) STL的栈
// 3) 从后往前遍历，得到一个单词就把它加到result的前边(result += temp比result = result+temp效率高得多)
//
// 如果要求去掉单词中间的多余空格，就不能用反转再反转的方法了。
#include <stdio.h>
#include <string.h>
#include <stack>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        if (s == "")
        {
            return "";
        }
        string result;
        int index = s.length() - 1;
        int end = index;
        while (index >= 0)
        {
            if (s[index] == ' ')
            {
                if (index != end)
                {
                    result += s.substr(index + 1, end - index - 1 + 1) + " ";
                    // cout << s.substr(index + 1, end - index - 1 + 1) << endl;
                    // index--;
                    end = index - 1;
                }
                else
                {
                    end--;
                    // index--;
                }
            }
            index--;
        }
        if (index != end)
        {
            result += s.substr(index + 1, end - index - 1 + 1);
        }
        else
        {
            if (result.length() > 0)
            {
                result.erase(result.length() - 1, 1);
            }
        }
        return result;
    }
};

int main()
{
    {
        Solution s;
        string str = "the sky is blue";
        auto res = s.reverseWords(str);
        cout << res << endl;
    }
    {
        Solution s;
        string str = "   the sky   is blue  ";
        auto res = s.reverseWords(str);
        cout << res << endl;
    }
}