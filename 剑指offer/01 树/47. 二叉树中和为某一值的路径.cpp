/*
输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。

从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

样例
给出二叉树如下所示，并给出num=22。
      5
     / \
    4   6
   /   / \
  12  13  6
 /  \    / \
9    1  5   1

输出：[[5,4,12,1],[5,6,6,5]]

*/


class Solution {
public:

    //定义答案数组
    vector<vector<int>> ans;

    vector<vector<int>> findPath(TreeNode* root, int sum) {
        vector<int> path; //存储从根结点到当前点的路径
        dfs(root, sum, path);
        return ans;
    }

    //sum为当前的总和，target为目标值
    void dfs(TreeNode *root, int sum, vector<int> &path)
    {
        //如果根结点为空，则直接返回
        if (!root) return;
        //存储当前遍历的路径
        path.push_back(root->val);
        sum -= root->val;
        //判断当前点是否为叶结点，如果是则判断当前点是否为目标值，如果是则记录路径
        //如果一个结点既没有左儿子又没有右儿子，则为叶结点
        if (!root->left && !root->right ){
            if(sum==target)ans.push_back(path);
        }else{
            //递归遍历左子树和右子树
            if(root->left)dfs(root->left,sum,target);
            if(root->left)dfs(root->right,sum,target);
        }
            
        //删除当前的点（递归之后恢复现场）
        path.pop_back();
        
    }
};


class Solution {
public:

    
    vector<vector<int>>ans;
    vector<vector<int>> findPath(TreeNode* root, int sum) {
        vector<int>path;
        dfs(root,sum,path);
        return ans; 
    }

    //sum为当前的总和，target为目标值
    void dfs(TreeNode *root, int sum, vector<int> &path)
    {
        if(!root)return;
        path.push(root);
        sum+=root->val;
        if(!root->right&&!root->left){
            if(sum==target)ans.push_back(path);
        }else{
            if(root->left)dfs(root->left,sum,target);
            if(root->right)dfs(root->right,sum,target);
        }
        path.pop_back();
       
    }
};