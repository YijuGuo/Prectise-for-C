/**
 * 
给出一个二叉树，输入两个树节点，求它们的最低公共祖先。

一个树节点的祖先节点包括它本身。

注意：

输入的二叉树不为空；
输入的两个节点一定不为空，且是二叉树中的节点；
样例
二叉树[8, 12, 2, null, null, 6, 4, null, null, null, null]如下图所示：
    8
   / \
  12  2
     / \
    6   4

1. 如果输入的树节点为2和12，则输出的最低公共祖先为树节点8。

2. 如果输入的树节点为2和6，则输出的最低公共祖先为树节点2。

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//如何求公共祖先的位置
//考点：二叉树和递归
//root的左子树和右子树都有p、q的时候，root是最低公共祖先
//情况1:如果一个点不是另一个点的祖先：公共祖先的位置在分叉的位置
//情况2:如果一个点是另一个点的祖先：公共祖先为其中的一个点的位置
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //空树
        if (!root) return NULL;
        //通过递归找到p or q
        if (root == p || root == q) return root;
        //先看root的左子树和右子树分别是否都有p、q
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        //如果左子树和右子树中p、q同时存在，root为公共祖先
        if (left && right) return root;
        //若左子树中两个节点都找不到，说明最低公共祖先一定在右子树中，反之亦然
        //假设p,q同时存在在左边，返回的是二者的最低公共的祖先
        if (left) return left;
        return right;//如果右边有，则返回二者的最低公共的祖先
    }
};