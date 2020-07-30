// 矩阵中的路径
// :请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。
// [["a","b","c","e"],
// ["s","f","c","s"],
// ["a","d","e","e"]]
// 但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。

// 回溯法

// 提升空间利用率：因为是回溯，可以先保存board[i][j]的值，将board[i][j]置为0表示已经访问过(因为是都是字符串),回溯返回的时候再设置为之前的值。
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<char>> tmp;
        for (int i = 0; i < board.size(); i++)
        {
            vector<char> vec;
            for (int j = 0; j < board[0].size(); j++)
            {
                vec.push_back(0);
            }
            tmp.push_back(vec);
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    tmp[i][j] = 1;
                    if (exist_helper(board, tmp, i, j, word, 1))
                    {
                        return 1;
                    }
                    tmp[i][j] = 0;
                }
            }
        }
        return false;
    }
    int exist_helper(vector<vector<char>> &board, vector<vector<char>> &tmp, int x, int y, string &word, int start)
    {
        if (start == word.length())
        {
            return 1;
        }
        if (y + 1 < board[0].size() && board[x][y + 1] == word[start] && tmp[x][y + 1] == 0)
        {
            tmp[x][y + 1] = 1;
            if (exist_helper(board, tmp, x, y + 1, word, start + 1))
            {
                return 1;
            }
            tmp[x][y + 1] = 0;
        }
        if (x + 1 < board.size() && board[x + 1][y] == word[start] && tmp[x + 1][y] == 0)
        {
            tmp[x + 1][y] = 1;
            if (exist_helper(board, tmp, x + 1, y, word, start + 1))
            {
                return 1;
            }
            tmp[x + 1][y] = 0;
        }
        if (y - 1 >= 0 && board[x][y - 1] == word[start] && tmp[x][y - 1] == 0)
        {
            tmp[x][y - 1] = 1;
            if (exist_helper(board, tmp, x, y - 1, word, start + 1))
            {
                return 1;
            }
            tmp[x][y - 1] = 0;
        }
        if (x - 1 >= 0 && board[x - 1][y] == word[start] && tmp[x - 1][y] == 0)
        {
            tmp[x - 1][y] = 1;
            if (exist_helper(board, tmp, x - 1, y, word, start + 1))
            {
                return 1;
            }
            tmp[x - 1][y] = 0;
        }
        return 0;
    }
};

int main()
{
    {
        Solution s;
        string word = "abfd";
        vector<vector<char>> board = {{'a', 'b', 't', 'g'},
                                      {'c', 'f', 'c', 's'},
                                      {'j', 'd', 'e', 'h'}};
        int res = s.exist(board, word);
        cout << res << endl;
        assert(res == 1);
    }
    {
        Solution s;
        string word = "abfb";
        vector<vector<char>> board = {{'a', 'b', 't', 'g'},
                                      {'c', 'f', 'c', 's'},
                                      {'j', 'd', 'e', 'h'}};
        int res = s.exist(board, word);
        cout << res << endl;
        assert(res == 0);
    }
    {
        Solution s;
        string word = "abte";
        vector<vector<char>> board = {{'a', 'b', 't', 'g'},
                                      {'c', 'f', 'c', 's'},
                                      {'j', 'd', 'e', 'h'}};
        int res = s.exist(board, word);
        cout << res << endl;
        assert(res == 0);
    }
}