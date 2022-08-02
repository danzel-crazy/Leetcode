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
    
    int dfs(TreeNode* root){
        if(root == nullptr) return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        if(left == -1 || right == -1) return -1;
        
        left +=1;
        right += 1;
        
        if (abs(left - right) > 1) return -1;
        if(right > left) return right;
        else return left;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(left == -1 || right == -1) return false;
        if (abs(left - right) <= 1) return true;
        else return false;
    }
};