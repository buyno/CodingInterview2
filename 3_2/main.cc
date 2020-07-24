// 寻找重复数：n+1个数，取值范围是1-n，
// 要求：数组不能变，空间复杂度O(n)，时间复杂度小于O(n*n)，有一个数至少重复一次，其他数字都是不重复的
// 解法1：类似于二分查找，1-n分为两边，统计整个数组中属于[1-n/2]区间的值的个数，
//      如果这个区间没有重复的值，那么个数肯定刚好等于middle，就换到另一个区间
//      如果有重复值，就继续二分
//      直到start和end相等时，指向的这个值就是要找的重复值
// 解法2：环。因为题设规定了只会有一个数字重复，可能重复多次，那么如果用数组的下标和值构建一个图的话，肯定是一个有向有环图，且环只有一个
//       那么就可以用快慢指针找到环，找到环的入口节点，入口节点就是重复元素(因为有两个入度)
// 解法3：二进制位运算。如果重复的值在那一位是1，那么因为重复，1出现的值一定是比正常时多的(如果重复一次，多一次，如果重复更多次，那就要看被替换的值在对应位上是否为一)
//        如果重复的值在那一位是0，那么可能不变，或减少
//        所以，总的来说，如果1的次数增加就是1，不变或减少就是0
// 总结：上面三种解法都是在有且仅有一个数字重复，可能重复多次的情况下，并且题设要求不能改数组，空间O1。
//       如果可以改数组，那么可以先排序再遍历一遍即可。
//       如果不要求空间O1，那么可以用一个辅助数组记录出现次数
#include <vector>
#include <assert.h>

using namespace std;

class Solution
{
public:
    // 解法一
    // int findDuplicate(vector<int> &nums)
    // {
    //     int n = nums.size() - 1;
    //     int start = 1;
    //     int end = n;
    //     int middle = (n + 1) / 2;
    //     while (start <= end)
    //     {
    //         if (end == start)
    //         {
    //             return start;
    //         }
    //         middle = (end + start) / 2;

    //         // 如果有重复的，就在这边继续缩小范围
    //         if (getcount(nums, nums.size(), start, middle) > middle - start + 1)
    //         {
    //             end = middle;
    //         }
    //         // 否则取另一半
    //         else
    //         {
    //             start = middle + 1;
    //         }
    //     }
    //     return -1;
    // }
    // 解法二
    // int findDuplicate(vector<int> &nums)
    // {
    //     int width = sizeof(nums[0]) * 8; //32
    //     assert(width == 32);
    //     int vecchance = 0;
    //     int numchance = 0;
    //     int result = 0;
    //     for (int i = 0; i < width; i++)
    //     {
    //         vecchance = 0;
    //         numchance = 0;
    //         for (int j = 0; j < nums.size(); j++)
    //         {
    //             if ((nums[j] & 1 << i) != 0)
    //             {
    //                 vecchance++;
    //             }
    //         }
    //         for (int j = 1; j < nums.size(); j++)
    //         {
    //             if ((j & 1 << i) != 0)
    //             {
    //                 numchance++;
    //             }
    //         }
    //         if (vecchance > numchance)
    //         {
    //             result = result | 1 << i;
    //         }
    //     }
    //     return result;
    // }
    // 解法三
    int findDuplicate(vector<int> &nums)
    {
        int slow = 0;
        int fast = 0;
        slow = nums[slow];
        fast = nums[fast];
        fast = nums[fast];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
        }
        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
    //nums中，大于等于start，小于等于end的数的个数
    int getcount(vector<int> &nums, int length, int start, int end)
    {
        int count = 0;
        for (int i = 0; i < length; i++)
        {
            if (nums[i] >= start && nums[i] <= end)
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    {
        vector<int> vec = {1, 3, 4, 2, 2};
        Solution s;
        assert(s.getcount(vec, vec.size(), 1, 3) == 4);
        assert(s.getcount(vec, vec.size(), 2, 4) == 4);
        assert(s.getcount(vec, vec.size(), 3, 4) == 2);
        s.findDuplicate(vec);
    }
    {
        vector<int> vec = {1, 3, 4, 2, 2};
        Solution s;
        int res = s.findDuplicate(vec);
        assert(res == 2);
    }

    {
        vector<int> vec = {1, 2, 2};
        Solution s;
        int res = s.findDuplicate(vec);
        assert(res == 2);
    }
    {
        vector<int> vec = {1, 2, 1};
        Solution s;
        int res = s.findDuplicate(vec);
        assert(res == 1);
    }

    {
        vector<int> vec = {1, 1};
        Solution s;
        int res = s.findDuplicate(vec);
        assert(res == 1);
    }
    {
        vector<int> vec = {2, 1, 2, 2};
        Solution s;
        int res = s.findDuplicate(vec);
        assert(res == 2);
    }
    {
        vector<int> vec = {1, 3, 2, 2, 5, 6, 2};
        Solution s;
        int res = s.findDuplicate(vec);
        assert(res == 2);
    }
}