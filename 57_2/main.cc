// 和为s的连续整数序列：给定s，输出所有和为s的连续正数序列.s为正数
// 比如s=15，序列有1~5，4~6，7~8
#include <stdio.h>
#include <assert.h>

int getSum(int s)
{
    if (s <= 2)
    {
        return 0;
    }
    int found = 0;
    int start = 1;
    int end = 2;
    while (start < end)
    {
        int sum = (end + start) * (end - start + 1) / 2;
        if (sum == s)
        {
            found = 1;
            printf("%d~%d\n", start, end);
            start++;
        }
        else if (sum > s)
        {
            start++;
        }
        else
        {
            end++;
        }
    }
    printf("\n");
    if (found)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int s = 15;
    int res;
    res = getSum(s);
    assert(res == 1);
    assert(getSum(4) == 0);
    assert(getSum(1) == 0);
    assert(getSum(3) == 1);
    assert(getSum(100) == 1);
}