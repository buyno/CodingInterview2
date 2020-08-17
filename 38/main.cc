// 字符串的排列
// 字符串不重复
// "abc" -> {abc,acb,bac,bca,cab,cba}

//字符可能重复出现，需要剪枝-》
// 比如，abcbd,到第二个b时发现已经出现过了，就跳过
// 1)用set保存这次遍历已经出现过的字符，如果已经出现过就跳过
// 2)每次要交换一个字符之前都遍历前面的所有字符，看是否已经出现过
#include <vector>
#include <string>
#include <iostream>
#include <set>
using namespace std;

class Solution
{
public:
    vector<string> permutation(string s)
    {
        vector<string> result;

        permutation(s, 0, result);

        return result;
    }
    void permutation(string &s, int i, vector<string> &result)
    {
        if (i == s.length() - 1)
        {
            result.push_back(s);
            return;
        }
        set<int> temp;
        for (int j = i; j < s.size(); j++)
        {
            if (temp.find(s[j]) != temp.end())
            {
                continue;
            }
            temp.insert(s[j]);
            swap(s, i, j);
            permutation(s, i + 1, result);
            swap(s, i, j);
        }
    }
    void swap(string &str, int i, int j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
};
int main()
{
    {
        Solution s;
        string str = "abc";
        auto res = s.permutation(str);
        for (auto x : res)
        {
            cout << x << endl;
        }
    }
    {
        Solution s;
        string str = "abcc";
        auto res = s.permutation(str);
        for (auto x : res)
        {
            cout << x << endl;
        }
    }
    {
        Solution s;
        string str = "kzfxxx";
        auto res = s.permutation(str);
        cout << "size:" << res.size() << endl;
        // for (auto x : res)
        // {
        //     cout << x << endl;
        // }
    }
}