// 左旋转字符串：abcdefg，n=2 -> cdefgab
// 1）substr
// 2）先整个串反转，再两半分别反转

#include <stdio.h>
#include <string.h>
#include <assert.h>
// void rotate(char *str, int length, int n)
// {
//     if (str == nullptr || length <= 0 || n < 0 || n > length)
//     {
//         return;
//     }
//     for (int i = 0; i < length / 2; i++)
//     {
//         char tmp = str[i];
//         str[i] = str[length - i - 1];
//         str[length - i - 1] = tmp;
//     }
//     for (int i = 0; i < (length - n) / 2; i++)
//     {
//         char tmp = str[i];
//         str[i] = str[length - n - i - 1];
//         str[length - n - i - 1] = tmp;
//     }
//     for (int i = length - n; i < length - n + n / 2; i++)
//     {
//         char tmp = str[i];
//         str[i] = str[length - (i - (length - n)) - 1];
//         str[length - (i - (length - n)) - 1] = tmp;
//     }
//     printf("%s\n", str);
// }
// int main()
// {
//     int length = 7;
//     char *str = new char[length + 1];
//     strcpy(str, "abcdefg");
//     int n = 2;
//     rotate(str, length, n);
//     strcpy(str, "abcdefg");
//     rotate(str, length, 7);
//     rotate(str, length, 8);

//     rotate(nullptr, length, n);
//     rotate(str, 0, n);
// }
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    string reverse(string &s, int i, int j)
    {
        while (i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
    string reverseLeftWords(string s, int n)
    {
        int size = (int)s.size();
        if (size <= 1)
            return s;
        reverse(s, 0, n - 1);
        reverse(s, n, size - 1);
        reverse(s, 0, size - 1);
        return s;
    }
};

int main()
{
    Solution s;
    auto res = s.reverseLeftWords("abcdefg", 2);
    cout << res << endl;
    assert(res == "cdefgab");
}