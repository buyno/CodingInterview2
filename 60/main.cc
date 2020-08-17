// n个骰子的点数。点数之和为s，输出s的所有可能值的概率
// 递归时间效率不够，，只能用动态规划

// 第i+1个骰子，取值范围是i+1~6(i+1)
// result[i][j]表示投第i+1个骰子之后，总和为j的次数
// 时间复杂度O(n*n)，空间复杂度O(N*n)
#include <stdio.h>
#include <map>
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<double> twoSum(int n)
    {
        // result[i][j]表示投第i+1个骰子之后，总和为j的次数
        vector<vector<double>> result(n, vector<double>(6 * n + 1, 0));
        int count = 0;
        for (int i = 1; i <= 6; i++)
        {
            result[0][i] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            //第i+1个骰子，取值范围是i+1~6(i+1)
            for (int j = i + 1; j <= 6 * (i + 1); j++)
            {
                for (int k = 1; k <= 6; k++)
                {
                    // result[i][j]表示投第i+1个骰子之后，总和为j的次数
                    if (j - k >= i)
                        result[i][j] = result[i][j] + result[i - 1][j - k];
                }
            }
        }
        int sum = pow(6, n);
        for (int i = n; i <= 6 * n; i++)
        {
            result[n - 1][i] = result[n - 1][i] / sum;
        }
        return vector<double>(result[n - 1].begin() + n, result[n - 1].begin() + 6 * n + 1);
    }
};
int main()
{
    {
        Solution s;
        auto res = s.twoSum(1);
        for (auto x : res)
        {
            cout << x << endl;
        }
    }
    {
        Solution s;
        auto res = s.twoSum(2);
        for (auto x : res)
        {
            cout << x << endl;
        }
    }
    {
        Solution s;
        auto res = s.twoSum(5);
        for (auto x : res)
        {
            cout << x << endl;
        }
    }
}