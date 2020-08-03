// 调整数组顺序使奇数位于偶数前面
// [1,2,3,4,5] -> [1,3,5,2,4]

#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class Solution
{
public:
    vector<int> exchange(vector<int> &nums)
    {
        if (!nums.size())
        {
            return {};
        }
        int index = nums.size() - 1;
        int value = nums[index]; //保存值，留出一个坑
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            //从左边开始找到第一个偶数
            while (left < right && nums[left] % 2)
            {
                left++;
            }
            // 填坑
            nums[index] = nums[left];
            //换坑
            index = left;
            //从右边开始找到第一个奇数
            while (left < right && !(nums[right] % 2))
            {
                right--;
            }
            //填坑
            nums[index] = nums[right];
            // 换坑
            index = right;
        }
        //最后将值填回去
        nums[index] = value;
        return nums;
    }
};
int main()
{
    {
        Solution s;
        vector<int> vec = {1, 2, 3, 4};
        auto res = s.exchange(vec);
        for (auto x : res)
        {
            cout << x << endl;
        }
    }
    {
        Solution s;
        vector<int> vec = {1, 2, 3, 4};
        auto res = s.exchange(vec);
        for (auto x : res)
        {
            cout << x << endl;
        }
    }
}