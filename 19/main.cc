// 正则表达式匹配
// .表示一个字符，*表示前面的字符出现0次或多次
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int indexs, indexp;
        indexs = 0;
        indexp = 0;
        return isMatch(s, 0, p, 0);
    }
    int isMatch(string &s, int indexs, string &p, int indexp)
    {
        //同时结束
        if (indexs == s.length() && indexp == p.length())
        {
            return 1;
        }
        // s没结束，p先结束,一定不匹配
        if (indexs < s.length() && indexp == p.length())
        {
            return 0;
        }
        if (indexp + 1 < p.length() && p[indexp + 1] == '*')
        {
            if (p[indexp] == '.')
            {
                //.*不起作用 || .*匹配多个字符
                // 涉及到indexs的都必须检查是否越界
                auto res = isMatch(s, indexs, p, indexp + 2) ||
                           (indexs < s.length() && isMatch(s, indexs + 1, p, indexp));
                return res;
            }
            else
            {
                // a* 0次 || >1次
                // 涉及到indexs的都必须检查是否越界
                auto res = isMatch(s, indexs, p, indexp + 2) ||
                           (s[indexs] == p[indexp] && isMatch(s, indexs + 1, p, indexp));

                return res;
            }
        }
        else
        {
            if (indexs < s.length() && (s[indexs] == p[indexp] || p[indexp] == '.'))
            {
                return isMatch(s, indexs + 1, p, indexp + 1);
            }
            else
            {
                return false;
            }
        }
    }
};
void test(string str, string pattern, int expected)
{
    Solution s;

    assert(s.isMatch(str, pattern) == expected);
}
int main()
{
    Solution s;
    assert(s.isMatch("", ""));
    assert(!s.isMatch("", "abc"));
    assert(!s.isMatch("abc", ""));
    assert(s.isMatch("abc", "abc"));
    assert(s.isMatch("abc", "a.c"));
    assert(s.isMatch("ac", "ab*c"));
    assert(s.isMatch("abc", "ab*c"));
    assert(s.isMatch("abbc", "ab*c"));
    assert(s.isMatch("ac", "ab*c"));
    assert(s.isMatch("abc", "a.*c"));
    assert(s.isMatch("ac", "a.*c"));
    assert(s.isMatch("abec", "a.*c"));

    assert(s.isMatch("aa", "a*"));
    assert(!s.isMatch("mississippi", "mis*is*p*."));
    assert(!s.isMatch("aaaaaaaaaaaaab",
                      "a*a*a*a*a*a*a*a*a*a*c"));

    assert(!s.isMatch("bccbbabcaccacbcacaa", ".*b.*c*.*.*.c*a*.c"));
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
    // // .*是0或n个.
    test("abcc", ".*cc", 1);
    test("ab", ".*c", 0);

    test("abcb", "abc*b*", 1);
    printf("All tests pass.\n");
}
