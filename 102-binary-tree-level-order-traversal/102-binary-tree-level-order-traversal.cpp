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
        map<int,vector<int>>mp;
        vector<vector<int>> ans;
        
        if(!root) return ans;
        queue <pair<TreeNode*, int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            TreeNode* cur = q.front().first;
            int level=q.front().second;
            if(ans.size() >= level+1){
                ans[level].push_back(cur->val);
            }
            else{
                vector <int> a;
                a.push_back(cur->val);
                ans.push_back(a);
            }
            if(cur->left)
                q.push({cur->left, level+1});
            if(cur->right)
                q.push({cur->right, level+1});
            q.pop();
        }
        
        return ans;
    }
};