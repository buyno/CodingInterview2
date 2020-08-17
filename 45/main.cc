// 把数组排列成最小的数
// 1)全排列，比较每种情况生成的值的大小，得到最小值  缺点：大数不行
// 2)用自定义的compare函数排序，得到最小值

// 两种sort：sort/qsort
// qsort是标准c库提供的，sort是STL提供的，sort效率更高
// void qsort(void *base, size_t num, size_t size,
//            int (*compar)(const void *, const void *));
// template <class RandomAccessIterator, class Compare>
// void sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);
// qsort直接比较，sort需要先生成对应的vector
// qsort的compare函数是 int compare(const void *num1,const void *num2);
// sort的compare函数是 bool compare(int a,int b);

#include <string>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <iostream>
using namespace std;

bool compare(string a, string b)
{
    return a + b < b + a;
}
class Solution
{
public:
    string minNumber(vector<int> &nums)
    {
        vector<string> temp;
        for (auto x : nums)
        {
            temp.emplace_back(to_string(x));
        }
        sort(temp.begin(), temp.end(), compare);
        string result;
        for (auto x : temp)
        {
            result += x;
        }
        return result;
    }
};
int main()
{
    Solution s;
    vector<int> data = {10, 2};
    string res = s.minNumber(data);
    cout << res << endl;
    assert(res == "102");
}