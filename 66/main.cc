//构建乘积数组：由A[n]得到B[n]，B[i] = A[0]*A[1]*...*A[i-1]*A[i+1]*...A[n]

//两个循环，第一个从前往后，得到截止A[i-1]的乘积，保存在B[i]中。
// 第二个循环从后往前，得到后半部的乘积在累乘到B[]对应位置
#include <stdio.h>
// O(n*n)
void getArray_1(int *a, int length, int *b)
{
    int tmp = 1;
    for (int i = 0; i < length; i++)
        tmp *= a[i];
    for (int i = 0; i < length; i++)
    {
        if (a[i] != 0)
        {
            b[i] = tmp / a[i];
        }
        else
        {
            for (int j = 0; j < length; j++)
            {
                if (i != j)
                {
                    b[i] *= a[j];
                }
            }
        }
    }
}
//O(n)
void getArray_2(int *a, int length, int *b)
{
    if (a == nullptr || b == nullptr || length <= 1)
    {
        return;
    }
    b[0] = 1;
    for (int i = 1; i < length; i++)
    {
        b[i] = b[i - 1] * a[i - 1];
    }
    int tmp = 1;
    for (int i = length - 1 - 1; i >= 0; i--)
    {
        tmp *= a[i + 1];
        b[i] *= tmp;
    }
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int length = sizeof(a) / sizeof(a[0]);
    int b[length] = {1, 1, 1, 1, 1};
    getArray_2(a, length, b);
    for (int i = 0; i < length; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
}