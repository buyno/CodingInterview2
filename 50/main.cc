// 第一个只出现一次的字符
// 在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。
#include <stdio.h>
#include <string>
#include <assert.h>

using namespace std;
#define MAX_CHAR 26 //只有小写字母
char getFirstAndNotRepeat(const char *str, int length)
{
    if (str == nullptr || length == 0)
    {
        return 0;
    }
    int res;
    int indexes[MAX_CHAR]; //初始是-1，出现一次记录index，再出现变-2。
    int times[MAX_CHAR];   //多余的
    for (int i = 0; i < MAX_CHAR; i++)
    {
        indexes[i] = -1;
        times[i] = 0;
    }
    for (int i = 0; i < length; i++)
    {
        //长度变，这里也要变
        if (indexes[str[i] - 'a'] == -1)
        {
            indexes[str[i] - 'a'] = i;
        }
        times[str[i] - 'a']++;
    }
    int minindex = MAX_CHAR;
    for (int i = 0; i < MAX_CHAR; i++)
    {
        if (times[i] == 1 && indexes[i] != -1)
        {
            if (indexes[i] < minindex)
            {
                minindex = indexes[i];
            }
        }
    }
    // printf("%d\n", minindex);
    // printf("%c\n", str[minindex]);
    return minindex == MAX_CHAR ? 0 : str[minindex];
}
int main()
{
    string str = "abaccdeff";
    assert(getFirstAndNotRepeat(str.c_str(), str.length()) == 'b');
    str = "sbklcdegf";
    assert(getFirstAndNotRepeat(str.c_str(), str.length()) == 's');
    str = "ssbbkkllfcdcedgefg";
    assert(getFirstAndNotRepeat(str.c_str(), str.length()) == '\0');
    assert(getFirstAndNotRepeat(nullptr, 2) == 0);
    assert(getFirstAndNotRepeat(str.c_str(), 0) == 0);
}