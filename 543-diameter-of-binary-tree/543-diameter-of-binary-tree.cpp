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
    int max = 0;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        // cout << left << " " << right << endl;
        if(max < left + right) max = left + right;
        return (left < right) ? right+1 : left+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = dfs(root);
        
        return max;
    }
};