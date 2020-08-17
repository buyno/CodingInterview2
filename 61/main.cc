// 扑克牌中的顺子：随机抽五张牌，判断是不是顺子，A,2-10,J,Q,K,大王小王看作任意数字

// 1）排序之后查找空缺和大小王的数量
// 2）不排序
// 如果我们能够知道 5 张扑克牌中的最大值 maxValuemaxValuemaxValue 和最小值 minValueminValueminValue ，那我们就知道，要使它为顺子需要 maxValue−minValue+1maxValue - minValue + 1maxValue−minValue+1 张牌。

//     在查找 maxValuemaxValuemaxValue 和 minValueminValueminValue 过程中，跳过大小王 000 。
//     如果 maxValue−minValue+1>5maxValue - minValue + 1 > 5maxValue−minValue+1>5，说明题目给的 5 张牌不足以构成顺子，返回 falsefalsefalse .
//         即使里面有大小王，也不够用来填补使它构成顺子。
//     如果 maxValue−minValue+1<=5maxValue - minValue + 1 <= 5maxValue−minValue+1<=5，说明 5 张牌足以构成顺子，返回 truetruetrue。
//         里面的大小王填补在合适位置即可。

// 同时，我们再定义一个标志数组判断是否有重复数字，发现重复数字直接返回 falsefalsefalse 即可。
#include <vector>
#include <iostream>
#include <assert.h>
#include <algorithm>
using namespace std;

// class Solution
// {
// public:
//     bool isStraight(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end());
//         int zerocount = 0;
//         int blanks = 0;
//         for (int i = 0; i < nums.size() - 1; i++)
//         {
//             if (nums[i] == 0)
//             {
//                 zerocount++;
//             }
//             else
//             {
//                 if (nums[i] == nums[i + 1])
//                 {
//                     return false;
//                 }
//                 if (nums[i] != nums[i + 1] + 1)
//                 {
//                     blanks += nums[i + 1] - nums[i] - 1;
//                 }
//             }
//         }
//         if (zerocount >= blanks)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
// };

class Solution
{
public:
    bool isStraight(vector<int> &nums)
    {
        int temp[15] = {0};
        int minvalue = 14;
        int maxvalue = 0;
        for (auto x : nums)
        {
            if (x == 0)
            {
                continue;
            }
            if (temp[x])
            {
                return false;
            }
            temp[x] = 1;
            minvalue = min(x, minvalue);
            maxvalue = max(x, maxvalue);
        }
        return maxvalue - minvalue + 1 <= 5;
    }
};

int main()
{
    {
        Solution s;
        vector<int> data = {1, 2, 3, 4, 5};
        bool res = s.isStraight(data);
        cout << res << endl;
        assert(res == true);
    }
    {
        Solution s;
        vector<int> data = {1, 2, 3, 4, 6};
        bool res = s.isStraight(data);
        cout << res << endl;
        assert(res == false);
    }
    {
        Solution s;
        vector<int> data = {1, 2, 3, 4, 3};
        bool res = s.isStraight(data);
        cout << res << endl;
        assert(res == false);
    }
    {
        Solution s;
        vector<int> data = {1, 2, 3, 5, 0};
        bool res = s.isStraight(data);
        cout << res << endl;
        assert(res == true);
    }
}