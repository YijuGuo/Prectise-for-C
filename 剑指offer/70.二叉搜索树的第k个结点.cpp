//二叉搜索树的中序遍历是有序序列
//因此本题是求解二叉搜索树中序遍历时的第k个元素
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//中序：按照左边、根节点、右边进行遍历
//将k从上往下传下来，每遍历一个点就--
//当k=0的时候，节点是要找的中序遍历的第k个节点
class Solution {
public:
    TreeNode * ans;//设置全局变量
    TreeNode* kthNode(TreeNode* root, int k) {
        dfs(root,k);
        return ans;
    }
    void dfs(TreeNode* root,int k)
    {
        if(!root) return;//边界
        dfs(root->left,k);//中序遍历
        k--;
        //当k=0的时候，遍历的节点为第k个节点
        if(!k)ans = root;
        if(k>0) dfs(root->right,k);
    }
};