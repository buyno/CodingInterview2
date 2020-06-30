// 正则表达式匹配
// .表示一个字符，*表示前面的字符出现0次或多次
#include <string.h>
#include <stdio.h>
#include <assert.h>
// return:1匹配,0不匹配
int compare(const char *str, const char *pattern)
{
    if (str == nullptr || pattern == nullptr)
        return 0;
    //两个一起结束
    if (*str == 0 && *pattern == 0)
    {
        return 1;
    }
    // str结束，pattern没结束
    // if(*str == 0  && *pattern != 0){

    // }
    // str没结束，pattern结束
    if (*str != 0 && *pattern == 0)
    {
        return 0;
    }
    //有*的时候，分为.*和a*两种情况
    if (pattern[1] == '*')
    {
        if (pattern[0] == '.' && *str != '\0')
        { // str+1可能越界，所以要加判断
            // .*出现0次 || .*已匹配一次再匹配 || .*只匹配一次
            return compare(str, pattern + 2) || compare(str + 1, pattern) || compare(str + 1, pattern + 2);
        }
        else
        {
            int res = compare(str, pattern + 2);
            if (pattern[0] == str[0])
            {
                res = res || compare(str + 1, pattern);
            }
            return res;
        }
    }
    if (pattern[0] == '.' || str[0] == pattern[0])
    {
        return compare(str + 1, pattern + 1);
    }
    return 0;
}

void test(const char *str, const char *pattern, int expected)
{
    assert(compare(str, pattern) == expected);
}

int main()
{
    test("abc", "a*bc", 1);
    test("abc", "a.c", 1);
    test("abc", "acc", 0);
    test("abc", ".bc", 1);
    test("bc", "a*bc", 1);
    test("aabc", "a*bc", 1);
    test("aabc", "", 0);
    test("abc", "", 0);

    test("", "a*bc", 0);
    test("", "", 1);
    test("", ".*", 1);
    test("", ".", 0);
    test("", "c*", 1);
    test("a", ".*", 1);
    test("a", "a.", 0);
    test("a", "", 0);
    test("a", ".", 1);
    test("a", "ab*", 1);
    test("a", "ab*a", 0);
    test("aa", "aa", 1);
    test("aa", "a*", 1);
    test("aa", ".*", 1);
    test("aa", ".", 0);
    test("ab", ".*", 1);
    test("aaa", "a*", 1);
    test("aaa", "aa.a", 0);
    test("aaa", "a.a", 1);
    test("aaa", ".a", 0);
    test("aaa", "a*a", 1);
    test("aaa", "ab*a", 0);
    test("aaa", "ab*ac*a", 1);
    test("aaa", "ab*a*c*a", 1);
    test("aaa", ".*", 1);
    test("aab", "c*a*b", 1);
    test("aaca", "ab*a*c*a", 1);
    test("aaba", "ab*a*c*a", 0);
    test("bbbba", ".*a*a", 1);
    test("bcbbabab", ".*a*a", 0);
    // .*是0或n个.
    test("abcc", ".*cc", 1);
    test("ab", ".*c", 1);

    test("abcb", "abc*b*", 1);
    printf("All tests pass.\n");
}
