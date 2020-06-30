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

class Solution
{
public:
    //递归比较，区分a*
    bool isMatch(string s, string p)
    {
        return isMatchHelper(s, 0, p, 0);
    }
    bool isMatchHelper(string &s, int sindex, string &p, int pindex)
    {
        // 1）两个同时结束
        if (sindex == s.length() && pindex == p.length())
        {
            return true;
        }
        // 2）模式先结束，还没匹配完，肯定不匹配
        if (sindex != s.length() && pindex == p.length())
        {
            return false;
        }
        // 3）s没结束，模式没有结束，但是模式是a*
        if (p.length() - pindex >= 2 && p[pindex + 1] == '*')
        {
            //.*,相当于.出现0或多次
            if (p[pindex] == '.' && s.length() - sindex > 0)
            {
                return isMatchHelper(s, sindex + 0, p, pindex + 2) || isMatchHelper(s, sindex + 1, p, pindex + 0) || isMatchHelper(s, sindex + 1, p, pindex + 2);
            }
            // 正常的a*
            else
            {
                //  a*匹配0个
                bool res = isMatchHelper(s, sindex + 0, p, pindex + 2);
                if (s[sindex] == p[pindex])
                {
                    //  a*继续匹配
                    res = res || isMatchHelper(s, sindex + 1, p, pindex + 0);
                }
                return res;
            }
        }
        // 4）s结束，模式没有结束
        else if (sindex == s.length())
        {
            return false;
        }
        // 5）s，模式都没有结束，且模式是普通的
        else if (sindex != s.length() && p[pindex] == '.' || p[pindex] == s[sindex])
        {
            return isMatchHelper(s, sindex + 1, p, pindex + 1);
        }
        return 0;
    }
};

int main()
{
    {
        Solution s;
        assert(s.isMatch("aaa", "a.a") == true);
        assert(s.isMatch("aaa", "ab*ac*a") == true);
        assert(s.isMatch("aa", "aaa") == false);
        assert(s.isMatch("aa", "a*") == true);
        assert(s.isMatch("ab", ".*") == true);
        assert(s.isMatch("aab", "c*a*b") == true);
        assert(s.isMatch("mississippi", "mis*is*p*.") == false);
        assert(s.isMatch("ab", "abb*b*a*") == true);
        assert(s.isMatch("abd", "abb*") == false);
        assert(s.isMatch("ab", ".*c") == false);
        assert(s.isMatch("a", ".*..a") == false);
        assert(s.isMatch("a", ".*.a*") == true);
        assert(s.isMatch("", "") == true);
        assert(s.isMatch("", "a.") == false);
        assert(s.isMatch("", "a*") == true);
        assert(s.isMatch("aa", "") == false);
    }
}