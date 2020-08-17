// 队列的最大值,滑动窗口的最大值。
// k=3,{2, 3, 4, 2, 6, 2, 5, 1} -> {4, 4, 6, 6, 6, 5}

// 利用双端队列，队列的front是最大值，back是最小值。
// 新到一个值，如果比当前的最大值还大，那其他值肯定不再可能是最大值，去掉。
// 如果比当前最大值小，可能会再之后成为最大值，所以加到队列末尾
// 同时还要清理超过滑动窗口的过期数字。
#include <vector>
#include <assert.h>
#include <deque> //双端队列
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        if (k < 1 || k > nums.size())
        {
            return {};
        }
        deque<int> temp;
        for (int i = 0; i < k; i++)
        {
            while (!temp.empty() && nums[i] > nums[temp.back()])
            {
                temp.pop_back();
            }
            temp.push_back(i);
        }
        vector<int> result;
        result.push_back(nums[temp.front()]);
        for (int i = k; i < nums.size(); i++)
        {
            while (!temp.empty() && nums[i] > nums[temp.back()])
            {
                temp.pop_back();
            }
            temp.push_back(i);
            while (!temp.empty() && temp.front() <= i - k)
            {
                temp.pop_front();
            }
            result.push_back(nums[temp.front()]);
        }
        return result;
    }
};
int main()
{
    Solution s;
    vector<int> data = {1, 3, -1, -3, 5, 3, 6, 7};
    auto res = s.maxSlidingWindow(data, 1);
    for (auto x : res)
    {
        cout << x << endl;
    }
}