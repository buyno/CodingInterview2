// 给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B 中的元素 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

//两个循环，第一个从前往后，得到截止A[i-1]的乘积，保存在B[i]中。
// 第二个循环从后往前，得到后半部的乘积在累乘到B[]对应位置
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> constructArr(vector<int> &a)
    {
        if (a.size() == 0)
        {
            return {};
        }
        else if (a.size() == 1)
        {
            return {1};
        }
        vector<int> result(a.size());
        int temp = 1;
        result[0] = 1;
        for (int i = 1; i < a.size(); i++)
        {
            temp *= a[i - 1];
            result[i] = temp;
        }
        temp = 1;
        for (int i = a.size() - 2; i >= 0; i--)
        {
            temp = temp * a[i + 1];
            result[i] = result[i] * temp;
        }

        return result;
    }
};
int main()
{
    {
        Solution s;
        vector<int> data = {1, 2, 3, 4, 5};
        auto res = s.constructArr(data);
        for (auto x : res)
        {
            cout << x << endl;
        }
    }
}