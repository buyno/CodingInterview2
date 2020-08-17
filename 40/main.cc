// 最小的k个数
// 第一种方法，排序之后输出前k个数，时间复杂度O(nlogn)
// 第二种方法，类似快排的机制，不断的partition直到找到的index是第k个，这时他左边的所有值就是最小的k个数
// 第三种方法，用一个k大小的容器保存最小的k个值

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        if (k == 0)
        {
            return {};
        }
        if (k == arr.size())
        {
            return arr;
        }
        int start = 0;
        int end = arr.size() - 1;
        int res = partition(arr, start, end);

        while (res != k)
        {
            if (res < k)
            {
                start = res + 1;
                res = partition(arr, start, end);
            }
            else
            {
                end = res - 1;
                res = partition(arr, start, end);
            }
        }
        return vector<int>(arr.begin(), arr.begin() + k);
    }
    //快排有两种思路，一种挖坑填坑，一种small指针指向小的那部分的末尾。这里是第二种
    // 第二种效率低一些，因为交换的次数更多
    int partition(vector<int> &arr, int start, int end)
    {
        int small = start - 1;
        int saved = arr[end];
        for (int i = start; i < end; i++)
        {
            if (arr[i] > saved)
            {
                continue;
            }
            else
            {
                swap(arr, small + 1, i);
                small++;
            }
        }
        swap(arr, small + 1, end);
        return small + 1;
    }
    void swap(vector<int> &arr, int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
};

int main()
{
    Solution s;
    vector<int> data = {4, 5, 1, 6, 2, 7, 3, 8};
    int k = 7;
    auto res = s.getLeastNumbers(data, k);
    for (auto x : res)
    {
        cout << x << endl;
    }
}