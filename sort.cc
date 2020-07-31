// 一些排序方式的实现排序：
// 冒泡排序
// 插入排序
// 归并排序
// 选择排序
// 快排

#include <stdio.h>
#include <iostream>
using namespace std;

//冒泡排序
void bubble_sort(int *nums, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}
// 插入排序
void insert_sort(int nums[], int length)
{
    for (int i = 1; i < length; i++)
    {
        int currentvalue = nums[i];
        int index = i;
        while (nums[index - 1] > currentvalue)
        {
            nums[index] = nums[index - 1];
            index--;
        }
        nums[index] = currentvalue;
    }
}

// 这不是插入排序，这是选择排序
void select_sort(int nums[], int length)
{

    for (int i = 0; i < length - 1; i++)
    {
        //从i到结尾，找到最小值的下标，然后与i交换
        int minindex = i;
        for (int j = i + 1; j < length; j++)
        {
            if (nums[j] < nums[minindex])
            {
                minindex = j;
            }
        }
        if (minindex != i)
        {
            int temp = nums[minindex];
            nums[minindex] = nums[i];
            nums[i] = temp;
        }
    }
}
// 归并排序
//合并
void merge(int nums[], int start, int end)
{
    int mid = (start + end) / 2;
    int *a = new int[mid - start + 1]();
    int *b = new int[end - mid]();
    for (int i = start; i <= mid; i++)
    {
        a[i - start] = nums[i];
    }
    for (int i = mid + 1; i <= end; i++)
    {
        b[i - mid - 1] = nums[i];
    }
    int i = start, j = 0, k = 0;
    while ((j <= mid - start) && (k < end - mid))
    {
        if (a[j] <= b[k])
        {
            nums[i++] = a[j++];
        }
        else
        {
            nums[i++] = b[k++];
        }
    }
    if (j <= mid - start)
    {
        for (int l = j; l <= mid - start; l++)
        {
            nums[i++] = a[l];
        }
    }
    else
    {
        for (int l = k; l < end - mid; l++)
        {
            nums[i++] = b[l];
        }
    }

    delete[] b;
    delete[] a;
}
//递归归并排序
void merge_sort(int nums[], int start, int end)
{
    if (end - start > 1)
    {
        int mid = (start + end) / 2;
        merge_sort(nums, start, mid);
        merge_sort(nums, mid + 1, end);
        merge(nums, start, end);
    }
    else if (end == start + 1)
    {
        if (nums[start] > nums[end])
        {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
        }
    }
}
void merge_sort(int nums[], int length)
{
    merge_sort(nums, 0, length - 1);
}
// 快排
// 思路1：随机选一个位置，与末尾交换，然后从0开始遍历，分为大于小于的两部分，一个small指针指向“小于部分”的最后一个，当遍历到的值是小于的时候交换到“小于部分”，当遍历到的值是大于的时候,index++
// 思路2：填坑 https://blog.csdn.net/liuchen1206/article/details/6954074

int partition(int data[], int start, int end);
void quicsort(int data[], int start, int end);
void quicsort(int data[], int length)
{
    if (length <= 0)
    {
        return;
    }
    quicsort(data, 0, length - 1);
}
//思路1
void quicsort(int data[], int start, int end)
{
    if (start == end)
    {
        return;
    }
    int index = partition(data, start, end);
    if (index > start)
    {
        quicsort(data, start, index - 1);
    }
    if (index < end)
    {
        quicsort(data, index + 1, end);
    }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int data[], int start, int end)
{
    int index = end;
    swap(data + index, data + end);
    int small = start - 1;
    for (index = start; index < end; index++)
    {
        if (data[index] < data[end])
        {
            ++small;
            if (small != index)
            {
                swap(data + index, data + small);
            }
        }
    }
    ++small;
    swap(data + small, data + end);
    return small;
}
// 思路2
// void quicsort(int s[], int l, int r)
// {
//     if (l < r)
//     {
//         int i = l, j = r, x = s[l];
//         while (i < j)
//         {
//             while (i < j && s[j] >= x) // 从右向左找第一个小于x的数
//                 j--;
//             if (i < j)
//                 s[i++] = s[j];
//             while (i < j && s[i] < x) // 从左向右找第一个大于等于x的数
//                 i++;
//             if (i < j)
//                 s[j--] = s[i];
//         }
//         s[i] = x;
//         quicsort(s, l, i - 1); // 递归调用
//         quicsort(s, i + 1, r);
//     }
// }
int main()
{
    {
        int nums[] = {1, 15, 12, 2, 43, 65, 87, 3, 45, 49, 4, 61, 92, 5, 39, 6, 7, 99, 8, 90, 9};
        cout << "array:" << endl;
        for (int x : nums)
        {
            printf("%d ", x);
        }
        printf("\n");
        // int nums[] = {1,15,12,2,43,65,8};
        // bubble_sort(nums,sizeof(nums)/sizeof(nums[0]));
        insert_sort(nums, sizeof(nums) / sizeof(nums[0]));
        // merge_sort(nums, sizeof(nums) / sizeof(nums[0]));
        cout << "sorted:" << endl;
        for (int x : nums)
        {
            printf("%d ", x);
        }
        printf("\n");
    }
    {
        int nums[] = {1, 15, 12, 2, 4};
        quicsort(nums, sizeof(nums) / sizeof(nums[0]));
        for (int x : nums)
        {
            printf("%d ", x);
        }
        printf("\n");
    }
    {
        int nums[] = {1, 15, 12, 2, 43, 65, 87, 3, 45, 49, 4, 61, 92, 5, 39, 6, 7, 99, 8, 90, 9};
        quicsort(nums, sizeof(nums) / sizeof(nums[0]));
        for (int x : nums)
        {
            printf("%d ", x);
        }
        printf("\n");
    }
    {
        int nums[] = {};
        quicsort(nums, 0);
        for (int x : nums)
        {
            printf("%d ", x);
        }
        printf("\n");
    }
    {
        int nums[] = {4};
        quicsort(nums, sizeof(nums) / sizeof(nums[0]));
        for (int x : nums)
        {
            printf("%d ", x);
        }
        printf("\n");
    }
    {
        int nums[] = {1, 15};
        quicsort(nums, sizeof(nums) / sizeof(nums[0]));
        for (int x : nums)
        {
            printf("%d ", x);
        }
        printf("\n");
    }
    {
        int nums[] = {15, 12};
        quicsort(nums, sizeof(nums) / sizeof(nums[0]));
        for (int x : nums)
        {
            printf("%d ", x);
        }
        printf("\n");
    }
    {
        int nums[] = {2, 5, 3, 15, 11, 14, 12};
        quicsort(nums, sizeof(nums) / sizeof(nums[0]));
        for (int x : nums)
        {
            printf("%d ", x);
        }
        printf("\n");
    }
    {
        int nums[] = {2, 11, 11};
        quicsort(nums, sizeof(nums) / sizeof(nums[0]));
        for (int x : nums)
        {
            printf("%d ", x);
        }
        printf("\n");
    }
}