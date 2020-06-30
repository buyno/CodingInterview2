// 动态规划问题：剪绳子
// n长的绳子剪成m段，使得每段长度的乘积最大
#include <stdio.h>
#include <assert.h>
int main()
{
    int n = 50;
    int result[n + 1];
    for (int i = 0; i < n + 1; i++)
        result[i] = 0;
    result[1] = 1;
    result[2] = 2;
    result[3] = 3;
    for (int i = 4; i < n + 1; i++)
    {
        int max = 0;
        for (int j = 1; j <= i / 2; j++)
        {
            if (result[j] * result[i - j] > max)
                max = result[j] * result[i - j];
        }
        result[i] = max;
    }
    assert(result[2] == 2);
    // assert(result[3] == 3); // 3->2
    assert(result[7] == 12);
    assert(result[8] == 18);
    assert(result[9] == 27);
    assert(result[10] == 36);
    assert(result[50] == 86093442);
}