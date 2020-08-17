// n个骰子的点数。点数之和为s，输出s的所有可能值的概率
// 递归时间效率不够，，只能用动态规划
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
                // if (j - 1 >= i)
                //     result[i][j] = result[i][j] + result[i - 1][j - 1];
                // if (j - 2 >= i)
                //     result[i][j] = result[i][j] + result[i - 1][j - 2];
                // if (j - 3 >= i)
                //     result[i][j] = result[i][j] + result[i - 1][j - 3];
                // if (j - 4 >= i)
                //     result[i][j] = result[i][j] + result[i - 1][j - 4];
                // if (j - 5 >= i)
                //     result[i][j] = result[i][j] + result[i - 1][j - 5];
                // if (j - 6 >= i)
                //     result[i][j] = result[i][j] + result[i - 1][j - 6];
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
            // cout << x << endl;
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
}