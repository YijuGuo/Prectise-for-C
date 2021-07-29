

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//考点：二叉树，递归
class Solution {
public:
    bool hasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot1 || !pRoot2) return false;
        //判断根节点是否匹配
        if (isSame(pRoot1, pRoot2)) return true;
        //递归判断左子树或者右子树是否有一样的结构
        return hasSubtree(pRoot1->left, pRoot2) || hasSubtree(pRoot1->right, pRoot2);
    }

    bool isSame(TreeNode* pRoot1, TreeNode* pRoot2) {
        //如果树B的节点为空，则匹配，返回true
        if (!pRoot2) return true;
        //如果树A为空，树B不为空，不匹配返回false
        //如果树A和树B均不为空，返回false
        if (!pRoot1 || pRoot1->val != pRoot2->val) return false;
        //当前节点匹配，递归判断左子树和右子树
        return isSame(pRoot1->left, pRoot2->left) && isSame(pRoot1->right, pRoot2->right);
    }
};

class Solution {
public:
    bool hasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if(!pRoot1||!pRoot2)return false;
        if(hasSubtree(pRoot1,pRoot2))return true;
        return hasSubtree(pRoot1->left,pRoot2)||hasSubtree(pRoot1->right,pRoot2);
    }

    bool isSame(TreeNode* pRoot1, TreeNode* pRoot2) {
        if(!pRoot2)return true;
        if(!pRoot1||pRoot1->val!=pRoot2->val)return false;
        return isSame(proot1->left,pRoot2->left)&&isSame(proot1->right,pRoot2->right);
        
    }
};
