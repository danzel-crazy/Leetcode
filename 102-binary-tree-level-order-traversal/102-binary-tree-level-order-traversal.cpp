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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int i = 0;
        if(!root) return ans;
        vector <int> a;
        a.push_back(root->val);
        ans.push_back(a);
        level(root->left, ans, i+1);
        level(root->right, ans, i+1);
        return ans;
    }
    
    void level(TreeNode* root, vector<vector<int>>& ans, int i){
        if(!root) return;
        if(ans.size() >= i+1) ans[i].push_back(root->val);
        else{
            vector <int> a;
            a.push_back(root->val);
            ans.push_back(a);
        }
        level(root->left, ans, i+1);
        level(root->right, ans, i+1);
    }
};