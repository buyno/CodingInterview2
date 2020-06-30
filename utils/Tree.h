struct TreeNode{
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode():value(0){
    }
    TreeNode(int n):value(n){

    }
};