// 数组中的逆序对

// 递归的思想：左半边与右半边比较，存在逆序对就+1，但是要先在内部的左半与右半比较，内部比较完之后会归并排序

//data里从start到end的数字，先找逆序对数，再归并排序到tmp中,再将tmp中的值复制会data中

#include <assert.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        vector<int> temp(nums.begin(), nums.end());
        return reversePairs(nums, 0, nums.size() - 1, temp);
    }
    int reversePairs(vector<int> &nums, int left, int right, vector<int> &temp)
    {
        if (left == right)
        {
            return 0;
        }
        int mid = (left + right) / 2;
        int count = 0;
        count += reversePairs(nums, left, mid, temp);
        count += reversePairs(nums, mid + 1, right, temp);
        //遍历，目的是找到左右两边的逆序对数，和将左右两边归并排序到temp中
        int leftindex = left;
        int rightindex = mid + 1;
        int index = left;
        while (leftindex <= mid && rightindex <= right)
        {
            if (nums[leftindex] <= nums[rightindex])
            {
                temp[index] = nums[leftindex];
                index++;
                leftindex++;
            }
            else
            {
                count += mid - leftindex + 1;
                temp[index] = nums[rightindex];
                index++;
                rightindex++;
            }
        }
        while (leftindex <= mid)
        {
            temp[index++] = nums[leftindex++];
        }
        while (rightindex <= right)
        {
            temp[index++] = nums[rightindex++];
        }
        //从temp中拷贝回nums
        for (int i = left; i <= right; i++)
        {
            nums[i] = temp[i];
        }
        return count;
    }
};

int main()
{
    {
        Solution s;
        vector<int> data = {1, 3, 2, 3, 1};
        int res = s.reversePairs(data);
        cout << res << endl;
        assert(res == 4);
    }
    {
        Solution s;
        vector<int> data = {7, 5, 6, 4};
        int res = s.reversePairs(data);
        cout << res << endl;
        assert(res == 5);
    }
    {
        Solution s;
        vector<int> data = {4, 5, 6, 7};
        int res = s.reversePairs(data);
        cout << res << endl;
        assert(res == 0);
    }
}