#include <string>
#include <sstream>
#include <vector>
#include <set>
using namespace std;
class Solution
{
public:
    vector<string> permutation(string s)
    {
        vector<string> vec;
        set<string> tmp; //set保存结果，并自动去重
        if (s.empty())
            return vec;
        permutation(s, 0, tmp);

        for (auto x : tmp)
        {
            vec.push_back(x);
        }
        return vec;
    }
    void permutation(string &s, int index, set<string> &vec)
    {
        if (index >= s.length() - 1)
        {
            vec.insert(s);
            return;
        }
        for (int i = index; i < s.length(); i++)
        {
            char tmp = s[index];
            s[index] = s[i];
            s[i] = tmp;
            permutation(s, index + 1, vec);
            tmp = s[index];
            s[index] = s[i];
            s[i] = tmp;
        }
    }
};

int main()
{
    Solution s;
    // auto res = s.permutation("kzfxxx");
    auto res = s.permutation("baa");

    for (auto x : res)
    {
        printf("%s\n", x.c_str());
    }
    printf("%ld\n", res.size());
}

// ->job->分配ip(虚拟网络接口/vlan..??)->私有网段->启动docker->接口？