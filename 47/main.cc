// 礼物的最大价值

// 动态规划
// res[i][j]是到达(i,j)点的最大礼物价值
// 那么res[i][j]等于max{res[i-1][j],res[i][j-1]},ij不越界
// 从后往前循环

// 改进：res不用rowXcol的矩阵，只需要一行
// 因为对于(i,j)及之后的所有点来说，其所必需的信息仅仅是i行的前半部分(i,0~j-1)和i-1行的后半部分(i-1，j~col)
#include <stdio.h>
#include <assert.h>

int getMaxValue(const int *data, int row, int col)
{
    if (data == nullptr || row <= 0 || col <= 0)
    {
        return -1;
    }
    int res[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 0 && j == 0)
                res[i][j] = data[col * i + j];
            else if (i > 0 && j > 0)
            {
                if (res[i - 1][j] > res[i][j - 1])
                {
                    res[i][j] = res[i - 1][j] + data[col * i + j];
                }
                else
                {
                    res[i][j] = res[i][j - 1] + data[col * i + j];
                }
            }
            else if (i > 0)
            {
                res[i][j] = res[i - 1][j] + data[col * i + j];
            }
            else if (j > 0)
            {
                res[i][j] = res[i][j - 1] + data[col * i + j];
            }
        }
    }
    return res[row - 1][col - 1];
}
void test1()
{
    int *data = nullptr;
    int row = 4;
    int col = 4;
    int res;
    res = getMaxValue((const int *)data, row, col);
    assert(res == -1);
}
void test2()
{
    int row = -4;
    int col = 4;
    int data[4][4] = {{1, 10, 3, 8}, {12, 2, 9, 6}, {5, 7, 4, 11}, {3, 7, 16, 5}};
    int res;
    res = getMaxValue((const int *)data, row, col);
    assert(res == -1);
}
void test3()
{
    int row = 4;
    int col = 4;
    int data[row][col] = {{1, 10, 3, 8}, {12, 2, 9, 6}, {5, 7, 4, 11}, {3, 7, 16, 5}};
    int res;
    res = getMaxValue((const int *)data, row, col);
    assert(res == 53);
}
void test4()
{
    int row = 1;
    int col = 4;
    int data[row][col] = {1, 10, 3, 8};
    int res;
    res = getMaxValue((const int *)data, row, col);
    assert(res == 22);
}
void test5()
{
    int row = 4;
    int col = 1;
    int data[row][col] = {{1}, {12}, {5}, {3}};
    int res;
    res = getMaxValue((const int *)data, row, col);
    assert(res == 21);
}
void test6()
{
    int row = 1;
    int col = 1;
    int data[row][col] = {{3}};
    int res;
    res = getMaxValue((const int *)data, row, col);
    assert(res == 3);
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
}