// 翻转字符串:"i am a student."->"student. a am i"
// 1) 先全部反转，再每个单词反转
// 2) STL的栈
#include <stdio.h>
#include <string.h>
#include <stack>
#include <string>
using namespace std;

// length是不包含\0的实际长度
void reverseString(char *str, int length)
{
    if (str == nullptr || length <= 0)
    {
        return;
    }
    printf("str:%s\n", str);
    for (int i = 0; i < length / 2; i++)
    {
        char tmp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = tmp;
    }
    int start = 0;
    int end = 0;
    for (int i = 0; i <= length; i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            end = i - 1;
            for (int j = start; j < start + (end - start + 1) / 2; j++)
            {
                char tmp = str[j];
                str[j] = str[end - (j - start)];
                str[end - (j - start)] = tmp;
            }
            start = i + 1;
        }
    }
    printf("reverse:%s\n", str);
}
void reverseString_2(char *str, int length)
{
    if (str == nullptr || length <= 0)
    {
        return;
    }
    printf("str:%s\n", str);
    stack<string> s;
    int start = 0;
    int end = 0;
    for (int i = 0; i <= length; i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            string tmp(str + start, end - start);
            end++;
            start = i + 1;
            s.push(tmp);
        }
        else
        {
            end++;
        }
    }
    printf("reverse:");
    while (!s.empty())
    {
        printf("%s ", s.top().c_str());
        s.pop();
    }
    printf("\n");
}
int main()
{
    int length = 19;
    char *str = new char[length + 1];
    strcpy(str, "intel am a student.");
    reverseString(str, length);
    strcpy(str, "busy");
    length = 4;
    reverseString(str, length);
    delete str;
    str = nullptr;
    reverseString(str, length);

    length = 19;
    str = new char[length + 1];
    strcpy(str, "intel am a student.");
    reverseString_2(str, length);
    strcpy(str, "busy");
    length = 4;
    reverseString_2(str, length);
    delete str;
    str = nullptr;
    reverseString_2(str, length);
}