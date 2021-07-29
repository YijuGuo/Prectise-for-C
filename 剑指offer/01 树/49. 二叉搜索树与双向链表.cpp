/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。

要求不能创建任何新的结点，只能调整树中结点指针的指向。

注意：

需要返回双向链表最左侧的节点。
例如，输入下图中左边的二叉搜索树，则输出右边的排序双向链表。

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//二叉搜索树遍历顺序就是双线链表的建立顺序
//记录左子树为pre:每一个结点访问时它的左子树肯定被访问过了
//pre指向的结点保存的数肯定小于当前结点，左右子树均访问过，
//因此right指针可以进行修改
//修改指针
//left指向双链表里面的左侧结点
//right指向双链表里面的右侧结点
class Solution {
public:

    //保存中序遍历的前一个结点
    TreeNode* pre = NULL;


    TreeNode* convert(TreeNode* root) {
        dfs(root);
        while(root && root->left) root = root->left;
        return root;
    }
    void dfs(TreeNode* root){
        //空
        if(!root) return;
        //递归搜索左子树
        dfs(root->left);
        
        //左子树访问结束
        root->left = pre; //root的左指针指向前一个结点
        if(pre) pre->right = root; //前一个结点的右指针指向root
        pre = root;//更新pre结点为当前的root

        //递归搜索右子树
        dfs(root->right);
    }
};