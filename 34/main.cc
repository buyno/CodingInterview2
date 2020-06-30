// 二叉树中和为某一值的路径

//用vector模拟栈记录路径

#include <vector>
#include <stdio.h>
#include "../Tree.h"

using namespace std;
void findPath(TreeNode *root,int requestSum,vector<vector<int> > &pathes,vector<int> &path){
    if(root == nullptr){
        return ;
    }
    //到了叶子节点
    if(!root->left && !root->right){
        if(root->value == requestSum){
            path.push_back(root->value);
            pathes.push_back(path);
            path.pop_back();
        }else{
            //找到底了还是不符合，退回到上一层
            return ;
        }
    }else{
    //没有到底，就只是减去value
        path.push_back(root->value);
        findPath(root->left,requestSum-root->value,pathes,path);
        findPath(root->right,requestSum-root->value,pathes,path);
        path.pop_back();
    }
}
vector<vector<int> > findPath(TreeNode *root,int requestSum){

    vector<vector<int> > pathes;
    vector<int> path;
    
    findPath(root,requestSum,pathes,path);

    return pathes;
}
int main(){
//没有路径
    // TreeNode *root = new TreeNode(10);
    // root->left = new TreeNode(5);
    // root->right = new TreeNode(13);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(6);
//一条路径
    // TreeNode *root = new TreeNode(10);
    // root->left = new TreeNode(5);
    // root->right = new TreeNode(12);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(6);
//两条路径
    // TreeNode *root = new TreeNode(10);
    // root->left = new TreeNode(5);
    // root->right = new TreeNode(12);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(7);
//null
    TreeNode *root = nullptr;
    
    vector<vector<int> > res = findPath(root,22);

    for(auto x : res){
        for(auto y : x){
            printf("%d ",y);
        }
        printf("\n");
    }
}