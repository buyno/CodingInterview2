// 旋转数组中查找最小的元素
// :把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

// 旋转：1,2,3,4,5,6 -> 5,6,1,2,3,4

// 1)顺序查找
// 2）类二分查找:比较第0个值与mid值，如果mid更大，说明min在后半部分；如果mid更小，说明min在前半部分
// 特殊：nullptr，只有一个值，全部递增没有旋转
//      start/mid/end的值相等时，不能判断min在前面还是后面，转为顺序查找
#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int minArray(vector<int> &numbers)
    {
        int start = 0;
        int end = numbers.size() - 1;
        while (start <= end)
        {
            // if (end == start)
            // {
            //     return numbers[start];
            // }
            // if (end - start == 1)
            // {
            //     return min(numbers[start], numbers[end]);
            // }
            int mid = (start + end) / 2;
            if (numbers[start] < numbers[end])
            {
                return numbers[start];
            }
            if (numbers[mid] > numbers[start])
            {
                start = mid;
                continue;
            }
            if (numbers[mid] < numbers[end])
            {
                end = mid;
                continue;
            }
            int minvalue = numbers[start];
            for (int i = start; i <= end; i++)
            {
                if (numbers[i] < minvalue)
                {
                    minvalue = numbers[i];
                }
            }
            return minvalue;
        }
        return 0;
    }
};

int main()
{
    {
        Solution s;
        int nums[] = {1, 0, 1, 1, 1};
        vector<int> vec(nums, nums + 5);
        int res = s.minArray(vec);
        cout << res << endl;
        assert(res == 0);
    }

    {
        Solution s;
        int nums[] = {3, 4, 5, 1, 2};
        vector<int> vec(nums, nums + 5);
        int res = s.minArray(vec);
        cout << res << endl;
        assert(res == 1);
    }
    {
        Solution s;
        int nums[] = {3, 4, 5, 1, 1, 2};
        vector<int> vec(nums, nums + 6);
        int res = s.minArray(vec);
        cout << res << endl;
        assert(res == 1);
    }
    {
        Solution s;
        int nums[] = {3, 4, 5, 1, 2, 2};
        vector<int> vec(nums, nums + 6);
        int res = s.minArray(vec);
        cout << res << endl;
        assert(res == 1);
    }
    {
        Solution s;
        int nums[] = {2};
        vector<int> vec(nums, nums + 1);
        int res = s.minArray(vec);
        cout << res << endl;
        assert(res == 2);
    }
    {
        Solution s;
        int nums[] = {1, 2};
        vector<int> vec(nums, nums + 2);
        int res = s.minArray(vec);
        cout << res << endl;
        assert(res == 1);
    }
    {
        Solution s;
        int nums[] = {2, 1};
        vector<int> vec(nums, nums + 2);
        int res = s.minArray(vec);
        cout << res << endl;
        assert(res == 1);
    }
    {
        Solution s;
        int nums[] = {1, 2, 3, 4, 5};
        vector<int> vec(nums, nums + 5);
        int res = s.minArray(vec);
        cout << res << endl;
        assert(res == 1);
    }
    {
        Solution s;
        int nums[] = {1, 3, 3};
        vector<int> vec(nums, nums + 3);
        int res = s.minArray(vec);
        cout << res << endl;
        assert(res == 1);
    }
}