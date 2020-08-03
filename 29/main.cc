// 顺时针打印矩阵
#include <vector>
using namespace std;

//打印矩阵中从(start,start)开始的一圈数字

// 1，test.cc中注释掉的是多余的判断
// 2，**start < rows/2 && start < cols/2与start*2 < rows && start*2 < cols不同

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int start = 0;
        int column = matrix.size();
        if (!column)
        {
            return {};
        }
        int row = matrix[0].size();
        if (!row)
        {
            return {};
        }
        vector<int> result(column * row);
        int index = 0;
        while (start * 2 < column && start * 2 < row)
        {

            for (int i = start; i < row - start; i++)
            {
                result[index++] = matrix[start][i];
                // result.push_back(matrix[start][i]);
                // cout << matrix[start][i] << " ";
            }
            for (int i = start + 1; i < column - start; i++)
            {
                result[index++] = matrix[i][row - start - 1];
                // result.push_back(matrix[i][row-start-1]);
                // cout << matrix[i][row-start-1] << " ";
            }
            if (start != column - start - 1)
            {
                for (int i = row - start - 2; i >= start; i--)
                {
                    result[index++] = matrix[column - start - 1][i];
                    // result.push_back(matrix[column-start-1][i]);
                    // cout << matrix[column-start-1][i] << " " ;
                }
            }
            if (row - start - 1 != start)
            {
                for (int i = column - start - 2; i > start; i--)
                {
                    result[index++] = matrix[i][start];
                    // result.push_back(matrix[i][start]);
                    // cout << matrix[i][start] << " " ;
                }
            }

            start++;
        }
        return result;
    }
};

int main()
{
    {
        Solution s;
        vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        s.spiralOrder(matrix);
    }
    {
        Solution s;
        vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}};
        s.spiralOrder(matrix);
    }
    {
        Solution s;
        vector<vector<int>> matrix = {{1, 2, 3}};
        s.spiralOrder(matrix);
    }
}