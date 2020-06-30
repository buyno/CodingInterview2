#include <stdio.h>
class Solution
{
public:
    int add(int a, int b)
    {
        int num1 = a ^ b;
        int num2 = a & b;
        while (num2)
        {
            a = num1;
            b = num2 << 1;
            num1 = a ^ b;
            num2 = a & b;
        }
        return num1;
    }
};

int main()
{
    Solution s;
    int res = s.add(-1, 2);
    printf("%d\n", res);
}
