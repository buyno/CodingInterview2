#include <string>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <sstream>

// 使用sstream之后反而降低了，说明sstream是浪费性能的
// 未使用sstream的在leetcode提交
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode *deserialize(istringstream &sstream)
{
    char *temp = new char[256];
    if (sstream.getline(temp, 256, ','))
    {
        if (strcmp(temp, "null") == 0)
        {
            return nullptr;
        }
        int value = atoi(temp);
        TreeNode *root = new TreeNode(value);
        root->left = deserialize(sstream);
        root->right = deserialize(sstream);
        return root;
    }
    return nullptr;
}
TreeNode *deserialize(string data)
{
    istringstream stream(data);
    return deserialize(stream);
}
void serialize(TreeNode *node, string &str)
{
    if (node != nullptr)
    {
        str += to_string(node->val);
        str += ",";
        serialize(node->left, str);
        serialize(node->right, str);
    }
    else
    {
        str += "null,";
    }
}
string serialize(TreeNode *root)
{
    if (root == nullptr)
    {
        return "";
    }
    string str;
    serialize(root, str);
    return str.substr(0, str.length() - 1);
}

int main()
{
    // string str = "1,2,3,null,null,4,5";
    // TreeNode *res = deserialize(str);

    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(3);
    // root->left->right = new TreeNode(4);
    // // root->right->left = new TreeNode(5);
    // // root->right->right = new TreeNode(66);
    // root->left->right->left = new TreeNode(5);
    string str = "1,2,3,null,null,4,5";

    // TreeNode *res = ;
    // str = serialize(root);
    // printf("%s\n", str.c_str());
    TreeNode *node = deserialize(str);
    str = serialize(node);
    printf("%s\n", str.c_str());
}