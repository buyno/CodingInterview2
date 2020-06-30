// n个骰子的点数。点数之和为s，输出s的所有可能值的概率
#include <stdio.h>
#include <map>
#include <math.h>

//递归
// (第n个骰子，总骰子数，面数，当前和，保存结果)
void func_1(int n, int number, int faces, int sum, int *res)
{
    if (n <= 0)
    {
        res[0] = -1;
        return;
    }
    else if (n == 1)
    {
        res[sum - number]++;
        return;
    }
    for (int i = 1; i <= faces; i++)
    {
        func_1(n - 1, number, faces, sum + i, res);
    }
}
// 循环解法
// void func_2(int n, int number, int faces, int sum, int *res)
// {
// }
// void f(int number, int faces)
// {
//     int *res = new int[number * faces - number + 1];
//     f(number, number, faces, res);
// }
void test(int number, int faces)
{
    int res[faces * number - number + 1];
    for (int i = 0; i < faces * number - number + 1; i++)
    {
        res[i] = 0;
    }
    for (int i = 1; i <= faces; i++)
    {
        func_1(number, number, faces, i, res);
    }

    for (int i = 0; i < faces * number - number + 1; i++)
    {
        printf("%d %d %f\n", i + number, res[i], res[i] / pow(faces, number));
    }
}
int main()
{
    test(1, 6);
    test(2, 6);
    test(3, 6);
    // test(4, 6);
    // test(11, 6);
    test(0, 6);
}