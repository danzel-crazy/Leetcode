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
        int count = 0;
    map<long long, int>m;
    void dfs(TreeNode* root, int targetSum, long long currSum){
        if(root == NULL)
            return;
        currSum += root->val;
        if(currSum == targetSum)count++;
        if(m.find(currSum - targetSum)!= m.end())
            count += m[currSum - targetSum];
        m[currSum]++;
        dfs(root->left, targetSum, currSum);
        dfs(root->right, targetSum, currSum);
        m[currSum]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum, 0);
        return count;
    }
};