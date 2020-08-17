// 和为s的连续整数序列：给定s，输出所有和为s的连续正数序列.s为正数
// 比如s=15，序列有1~5，4~6，7~8
#include <stdio.h>
#include <assert.h>

// int getSum(int s)
// {
//     if (s <= 2)
//     {
//         return 0;
//     }
//     int found = 0;
//     int start = 1;
//     int end = 2;
//     while (start < end)
//     {
//         int sum = (end + start) * (end - start + 1) / 2;
//         if (sum == s)
//         {
//             found = 1;
//             printf("%d~%d\n", start, end);
//             start++;
//         }
//         else if (sum > s)
//         {
//             start++;
//         }
//         else
//         {
//             end++;
//         }
//     }
//     printf("\n");
//     if (found)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
// int main()
// {
//     int s = 15;
//     int res;
//     res = getSum(s);
//     assert(res == 1);
//     assert(getSum(4) == 0);
//     assert(getSum(1) == 0);
//     assert(getSum(3) == 1);
//     assert(getSum(100) == 1);
// }
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findContinuousSequence(int target)
    {
        int left = 1;
        int right = 1;
        int sum = 1;
        vector<vector<int>> result;
        while (left <= target && right <= target)
        {
            if (sum == target)
            {
                if (right - left + 1 < 2)
                {
                    break;
                }
                vector<int> temp;
                for (int i = left; i <= right; i++)
                {
                    temp.push_back(i);
                }
                result.push_back(temp);
                sum -= left;
                left++;
            }
            else if (sum < target)
            {

                right++;
                sum += right;
            }
            else
            {
                if (right - left + 1 == 2)
                {
                    break;
                }
                sum -= left;
                left++;
            }
        }
        return result;
    }
};
int main()
{
    Solution s;
    int n = 9;
    auto res = s.findContinuousSequence(n);
    for (auto x : res)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}