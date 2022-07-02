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
    vector<vector<int>> res;
    if(root==NULL)
        return res;
    
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    
    while(!q.empty())
    {
        TreeNode* node=q.front().first;
        int level=q.front().second;
        q.pop();
        
        mp[level].push_back(node->val);
        if(node->left)
            q.push({node->left,level+1});
        if(node->right)
            q.push({node->right,level+1});
    }
    
    
    for(auto i:mp)
        res.push_back(i.second);
    return res;
}
    
};