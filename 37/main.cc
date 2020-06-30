// 实现两个函数，序列化和反序列化二叉树

// 1) 按照先序遍历，子树为空时填null/&
// 2）层序遍历

//读数时要考虑数是-1

//参考test.cc(负数，性能)
#include "../Tree.h"
#include <stdio.h>
#include <string>
#include <string.h>
#include <assert.h>
using namespace std;

void serialize(TreeNode *node, string &str)
{
    if (node != nullptr)
    {
        str += to_string(node->value);
        str += ",";
        serialize(node->left, str);
        serialize(node->right, str);
    }
    else
    {
        str += "$,";
    }
}
char *serialize(TreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    string str;
    serialize(root, str);
    // printf("strlen:%d\n",str.length());
    char *res = new char[str.length() + 1];

    for (int i = 0; i < str.length() + 1; i++)
    {
        res[i] = 0;
    }
    strcpy(res, str.c_str());
    return res;
}
TreeNode *deserialize(char **str)
{
    if (*str == nullptr)
    {
        return nullptr;
    }
    if (**str == '$')
    {

        return nullptr;
    }
    int value = 0;
    while (**str >= '0' && **str <= '9')
    {
        value = value * 10 + (**str - '0');
        (*str)++;
    }
    (*str)++;
    // printf("%d\n",value);
    TreeNode *root = new TreeNode(value);
    root->left = deserialize(str);
    if (root->left == nullptr)
        (*str) += 2;
    root->right = deserialize(str);
    if (root->right == nullptr)
        (*str) += 2;
    return root;
}
TreeNode *deserialize(char *str, int length)
{
    if (str == nullptr || length == 0)
    {
        return nullptr;
    }
    return deserialize(&str);
}
// 空
void test1()
{
    TreeNode *root = nullptr;
    // 序列化
    char *res = serialize(root);
    assert(res == nullptr);
    // 反序列化
    TreeNode *newRoot = deserialize(res, 0);
    assert(newRoot == nullptr);
}
// 普通树
void test2()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(8);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(66);

    // 序列化
    char *res = serialize(root);

    printf("%s\n", res);
    int length = 0;
    char *tt = res;
    while (*tt)
    {
        length++;
        tt++;
    }

    // 反序列化
    TreeNode *newRoot = deserialize(res, length);

    assert(newRoot->value == 1);
    assert(newRoot->left->value == 2);
    assert(newRoot->left->left->value == 4);
    assert(newRoot->left->right == nullptr);
    assert(newRoot->right->value == 3);
    assert(newRoot->right->left->value == 5);
    assert(newRoot->right->right->value == 66);
    assert(newRoot->right->left->left == nullptr);
    assert(newRoot->right->left->right == nullptr);
    assert(newRoot->right->right->right == nullptr);
    assert(newRoot->right->right->left == nullptr);
}
// 全左
void test3()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(8);
    // root->right->left = new TreeNode(5);
    // root->right->right = new TreeNode(66);
    // 序列化
    char *res = serialize(root);

    printf("%s\n", res);
    int length = 0;
    char *tt = res;
    while (*tt)
    {
        length++;
        tt++;
    }

    // 反序列化
    TreeNode *newRoot = deserialize(res, length);

    assert(newRoot->value == 1);
    assert(newRoot->left->value == 2);
    assert(newRoot->left->left->value == 4);
    assert(newRoot->left->right == nullptr);
    assert(newRoot->left->left->left == nullptr);
    assert(newRoot->left->left->right == nullptr);
    assert(newRoot->right == nullptr);
}
// 全右
void test4()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(66);
    // 序列化
    char *res = serialize(root);

    printf("%s\n", res);
    int length = 0;
    char *tt = res;
    while (*tt)
    {
        length++;
        tt++;
    }

    // 反序列化
    TreeNode *newRoot = deserialize(res, length);

    assert(newRoot->value == 1);
    assert(newRoot->right->value == 3);
    assert(newRoot->right->right->value == 66);
    assert(newRoot->right->left == nullptr);
    assert(newRoot->right->right->left == nullptr);
    assert(newRoot->right->right->right == nullptr);
    assert(newRoot->left == nullptr);
}
//一个节点
void test5()
{
    TreeNode *root = new TreeNode(1);

    // 序列化
    char *res = serialize(root);

    printf("%s\n", res);
    int length = 0;
    char *tt = res;
    while (*tt)
    {
        length++;
        tt++;
    }

    // 反序列化
    TreeNode *newRoot = deserialize(res, length);

    assert(newRoot->value == 1);
    assert(newRoot->left == nullptr);
    assert(newRoot->right == nullptr);
}
//节点值全部相同
void test6()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(3);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(3);
    // 序列化
    char *res = serialize(root);

    printf("%s\n", res);
    int length = 0;
    char *tt = res;
    while (*tt)
    {
        length++;
        tt++;
    }

    // 反序列化
    TreeNode *newRoot = deserialize(res, length);

    assert(newRoot->value == 3);
    assert(newRoot->left->value == 3);
    assert(newRoot->left->left->value == 3);
    assert(newRoot->left->right == nullptr);
    assert(newRoot->right->value == 3);
    assert(newRoot->right->left->value == 3);
    assert(newRoot->right->right->value == 3);
    assert(newRoot->right->left->left == nullptr);
    assert(newRoot->right->left->right == nullptr);
    assert(newRoot->right->right->right == nullptr);
    assert(newRoot->right->right->left == nullptr);
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
}