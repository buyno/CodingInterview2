//找出数组中任意一个重复的数字
//在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

//in:2, 3, 1, 0, 2, 5, 3
//out:2 or 3

#include <iostream>
#include <assert.h>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        // (0)先排序在顺序查找
        // (1)hash表存出现过的值
        //
        // unordered_set<int> tmp;
        // for (auto x : nums)
        // {
        //     if (tmp.find(x) != tmp.end())
        //     {
        //         return x;
        //     }
        //     else
        //     {
        //         tmp.insert(x);
        //     }
        // }
        // return -1;
        //(2) 内部交换值
        for (int i = 0; i < nums.size(); i++)
        {
            // if(nums[i])
            while (nums[i] != i)
            {

                int m = nums[i];
                if (nums[m] == m)
                {
                    return m;
                }
                int tmp = nums[m];
                nums[m] = m;
                nums[i] = tmp;
            }
        }
        return -1;
    }
};

int main()
{
    {
        Solution s;
        vector<int> vec = {1, 2, 3, 6, 4, 5, 6};
        int res = s.findRepeatNumber(vec);
        cout << res << endl;
        assert(res == 6);
    }
    {
        Solution s;
        vector<int> vec = {1, 2, 1, 6, 4, 5, 6};
        int res = s.findRepeatNumber(vec);
        cout << res << endl;
        assert(res == 1 || res == 6);
    }
    {
        Solution s;
        vector<int> vec = {0, 1, 2, 3, 4, 5, 6};
        int res = s.findRepeatNumber(vec);
        cout << res << endl;
        assert(res == -1);
    }
}