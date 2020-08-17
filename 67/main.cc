// 写一个函数 StrToInt，实现把字符串转换成整数这个功能。不能使用 atoi 或者其他类似的库函数。
// 在任何情况下，若函数不能进行有效的转换时，请返回 0。
// 假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。
#include <string>
#include <iostream>
#include <math.h>
#include <unistd.h>
#include <assert.h>
using namespace std;
#define INT_MAX pow(2, 31) - 1
#define INT_MIN -pow(2, 31)
class Solution
{
public:
    int strToInt(string str)
    {

        int index = 0;
        while (index < str.length() && str[index] == ' ')
        {
            index++;
        }
        int positive = 1;
        if (str[index] == '-')
        {
            positive = 0;
            ++index;
        }
        else if (str[index] == '+')
        {
            ++index;
        }
        int endindex = index;
        while (endindex != str.length())
        {
            if (str[endindex] >= '0' && str[endindex] <= '9')
            {
                endindex++;
            }
            else
            {
                break;
            }
        }
        // cout << "," <<str.substr(index,endindex-index) << ","<< endl;
        string clearstr = str.substr(index, endindex - index);
        double res = 0;
        for (int i = 0; i < clearstr.length(); i++)
        {

            res = res * 10 + clearstr[i] - '0';
            if (res >= pow(2, 31) && positive)
            {
                return INT_MAX;
            }
            if (res > pow(2, 31) && !positive)
            {
                return INT_MIN;
            }
        }

        return positive ? res : -res;
    }
};
int main()
{
    {
        Solution s;
        int res = s.strToInt("123");
        cout << res << endl;
        assert(res == 123);
    }
    {
        Solution s;
        int res = s.strToInt(" -42");
        cout << res << endl;
        assert(res == -42);
    }
    {
        Solution s;
        int res = s.strToInt("123 sdasda");
        cout << res << endl;
        assert(res == 123);
    }
    {
        Solution s;
        int res = s.strToInt("asd 123");
        cout << res << endl;
        assert(res == 0);
    }
}