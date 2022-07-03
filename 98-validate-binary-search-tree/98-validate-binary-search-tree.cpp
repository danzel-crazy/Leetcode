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
    bool isValidBST(TreeNode* root) {
        stack <TreeNode*> ans;
        TreeNode* pre = nullptr;
        while(!ans.empty() || root!= nullptr){
            while(root != nullptr){
                ans.push(root);
                root = root -> left;
            }
            
            root = ans.top();
            ans.pop();
                
            if(pre != nullptr && pre->val >= root->val){
                return false;
            }
            
            pre = root;
            root = root->right;   
        }
        return true;
    }
};