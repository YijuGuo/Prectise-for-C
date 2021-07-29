/*
请实现一个函数，用来判断一棵二叉树是不是对称的。

如果一棵二叉树和它的镜像一样，那么它是对称的。

样例
如下图所示二叉树[1,2,2,3,4,4,3,null,null,null,null,null,null,null,null]为对称二叉树：
    1
   / \
  2   2
 / \ / \
3  4 4  3

如下图所示二叉树[1,2,2,null,4,4,3,null,null,null,null,null,null]不是对称二叉树：
    1
   / \
  2   2
   \ / \
   4 4  3
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
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        //root为零时满足条件
        //root不为零是，判断root的左子树和右子树是否呈镜像
        return !root||dfs(root->left,root->right);
    }
    bool dfs(TreeNode*p , TreeNode*q)
    {
        if(!p||!q)return !p&&!q;
        return p->val==q->val&&dfs(p->left,q->left)&&(p->right,q->left);
    }
};
