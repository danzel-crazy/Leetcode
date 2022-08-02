/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check = true; 
    
    int dfs(TreeNode* root, bool &check){
        if(root == nullptr) return 0;
        
        int left = dfs(root->left, check);
        int right = dfs(root->right, check);
        
        if (abs(left - right) > 1) check = false;
        return max(left, right) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        bool check = true;
        
        if(root == nullptr) return true;
        int ans = dfs(root, check);
        
        return check;
    }
};