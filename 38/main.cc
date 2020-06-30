// 字符串的排列
// 字符串不重复
// "abc" -> {abc,acb,bac,bca,cab,cba}

//
#include <stdio.h>
int count = 0;
void permutation(char *str, char *start)
{
    if (*start == 0)
    {
        count++;
        printf("%s\n", str);
    }
    else
    {
        char *mark = start;
        while (*mark != 0)
        {
            char tmp = *mark;
            *mark = *start;
            *start = tmp;
            permutation(str, start + 1);

            tmp = *mark;
            *mark = *start;
            *start = tmp;
            mark++;
        }
    }
}
void permutation(char *str)
{
    if (str == nullptr)
    {
        return;
    }
    permutation(str, str);
}
int main()
{
    char str[] = "kzfxxx";
    printf("str:%s\n", str);
    permutation(str);
    printf("%d\n", count);
    // permutation(nullptr);
    // str[1] = 0;
    // permutation(str);
    // str[0] = 0;
    // permutation(str);
}
