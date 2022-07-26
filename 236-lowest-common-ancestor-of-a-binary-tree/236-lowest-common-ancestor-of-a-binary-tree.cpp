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
    //TC=O(n), n = no. of nodes, SC=O(n)
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==p || root==q || root==NULL)
            return root;
        TreeNode* leftParent = dfs(root->left, p, q);
        TreeNode* rightParent = dfs(root->right, p, q);
        if(leftParent && rightParent)
            return root;
        else
            return leftParent ? leftParent : rightParent;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};