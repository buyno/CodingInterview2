// 分行从上到下打印二叉树

// 用队列，但是需要记录当前层还没有打印的节点数和下一层的节点数目

#include <queue>
#include <map>
#include "../Tree.h"

using namespace std;

void printTree(TreeNode *root){
    queue<TreeNode *> data;
    data.push(root);

    int numberToPrint = 1;
    int nextLevelNumber = 0;


    while(!data.empty()){
        auto tmp = data.front();
        data.pop();

        printf("%d ",tmp->value);
        numberToPrint--;

        if(tmp->left){
            data.push(tmp->left);
            nextLevelNumber++;
        }
        if(tmp->right){
            data.push(tmp->right);
            nextLevelNumber++;
        }
        if(numberToPrint == 0){
            printf("\n");
            numberToPrint = nextLevelNumber;
            nextLevelNumber = 0;
        }
    }
}
int main(){
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(6);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(7);
    // root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(11);
    printTree(root);

}