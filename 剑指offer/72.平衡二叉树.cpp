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
    bool ans= true;
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return ans;
    }
    dfs(TreeNode* root){
        if(!root)return 0;
        int left=dfs(root->left),right = dfs(root->right);
        //abs返回绝对值
        if(abs(left-right)>1)ans=false;
        return max(left,right)+1;
    }



};