// 矩阵中的路径
// :请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。
// [["a","b","c","e"],
// ["s","f","c","s"],
// ["a","d","e","e"]]
// 但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。

// 回溯法
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
    }
};
void test1()
{
    vector<vector<char>> board = {
        'a',
        'b',
        't',
        'g',
        'c',
        'f',
        'c',
        's',
        'j',
        'd',
        'e',
        'h'
    } char array[] = {'a', 'b', 't', 'g', 'c', 'f', 'c', 's', 'j', 'd', 'e', 'h'};
    int row = 3, col = 4;
    char path[] = "abtc";
    int visited[row * col];
    for (int i = 0; i < row * col; i++)
    {
        visited[i] = 0;
    }
    int res = findPath(array, row, col, path, sizeof(path) / sizeof(path[0]) - 1, visited);
    assert(res == 1);
}
void test2()
{
    char array[] = {'a', 'b', 't', 'g',
                    'c', 'f', 'c', 's',
                    'j', 'd', 'e', 'h'};
    int row = 3, col = 4;
    char path[] = "abtb";
    int visited[row * col];
    for (int i = 0; i < row * col; i++)
    {
        visited[i] = 0;
    }
    int res = findPath(array, row, col, path, sizeof(path) / sizeof(path[0]) - 1, visited);
    assert(res == 0);
}
void test3()
{
    char array[] = {'a', 'b', 't', 'g',
                    'c', 'f', 'c', 's',
                    'j', 'd', 'e', 'h'};
    int row = 3, col = 4;
    char path[] = "bss";
    int visited[row * col];
    for (int i = 0; i < row * col; i++)
    {
        visited[i] = 0;
    }
    int res = findPath(array, row, col, path, sizeof(path) / sizeof(path[0]) - 1, visited);
    assert(res == 0);
}
void test4()
{
    char array[] = {'a', 'b', 't', 'g',
                    'c', 's', 'c', 's',
                    'j', 'd', 'e', 'h'};
    int row = 3, col = 4;
    char path[] = "cshe";
    int visited[row * col];
    for (int i = 0; i < row * col; i++)
    {
        visited[i] = 0;
    }
    int res = findPath(array, row, col, path, sizeof(path) / sizeof(path[0]) - 1, visited);
    assert(res == 1);
}
void test5()
{
    char array[] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    int row = 5, col = 8;
    char path[] = "SGGFIECVAASABCEEJIGOEM";
    int visited[row * col];
    for (int i = 0; i < row * col; i++)
    {
        visited[i] = 0;
    }
    int res = findPath(array, row, col, path, sizeof(path) / sizeof(path[0]) - 1, visited);
    assert(res == 0);
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
}