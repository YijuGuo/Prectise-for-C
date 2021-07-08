/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//所有点的左儿子和右儿子进行了互换
class Solution {
public:
    void mirror(TreeNode* root) {
        //遍历树里面的所有的点
        //树空，return
        if (!root) return;
        //swap左右儿子
        swap(root->left, root->right);
        //递归
        mirror(root->left);
        mirror(root->right);
    }
};

