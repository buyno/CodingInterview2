// 替换空格为%20

// 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
// 输入：s = "We are happy."
// 输出："We%20are%20happy."
#include <iostream>
#include <assert.h>
#include <string>
using namespace std;
class Solution
{
public:
    string replaceSpace(string s)
    {
        int originlength = s.length();
        int spacecount = 0;
        for (int i = 0; i < originlength; i++)
        {
            if (s[i] == ' ')
            {
                spacecount++;
            }
        }
        //不要新创建字符串，直接连接效率更高
        s += string(spacecount * 2, ' ');
        int index = s.length() - 1;
        for (int i = originlength - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
            {
                s[index--] = s[i];
                // continue;
            }
            else
            {
                s[index--] = '0';
                s[index--] = '2';
                s[index--] = '%';
            }
        }
        return s;
    }
};

int main()
{
    {
        Solution s;
        string str;
        string res = s.replaceSpace(str);
        cout << res << endl;
        assert(res == "");
    }
    {
        Solution s;
        string str = "  ";
        string res = s.replaceSpace(str);
        cout << res << endl;
        assert(res == "%20%20");
    }
    {
        Solution s;
        string str = "we are ill";
        string res = s.replaceSpace(str);
        cout << res << endl;
        assert(res == "we%20are%20ill");
    }
}