// 左旋转字符串：abcdefg，n=2 -> cdefgab
#include <stdio.h>
#include <string.h>
#include <assert.h>
void rotate(char *str, int length, int n)
{
    if (str == nullptr || length <= 0 || n < 0 || n > length)
    {
        return;
    }
    for (int i = 0; i < length / 2; i++)
    {
        char tmp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = tmp;
    }
    for (int i = 0; i < (length - n) / 2; i++)
    {
        char tmp = str[i];
        str[i] = str[length - n - i - 1];
        str[length - n - i - 1] = tmp;
    }
    for (int i = length - n; i < length - n + n / 2; i++)
    {
        char tmp = str[i];
        str[i] = str[length - (i - (length - n)) - 1];
        str[length - (i - (length - n)) - 1] = tmp;
    }
    printf("%s\n", str);
}
int main()
{
    int length = 7;
    char *str = new char[length + 1];
    strcpy(str, "abcdefg");
    int n = 2;
    rotate(str, length, n);
    strcpy(str, "abcdefg");
    rotate(str, length, 7);
    rotate(str, length, 8);

    rotate(nullptr, length, n);
    rotate(str, 0, n);
}