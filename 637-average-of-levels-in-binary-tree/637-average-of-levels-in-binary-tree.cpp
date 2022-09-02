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
    void bfs(vector <pair<double, double>> &count, TreeNode* root, int level){
        if(root == nullptr) return;
        
        if(count.size() <= level){
            count.push_back(make_pair(root->val, 1));
        }
        else{
            count[level].first += root->val;
            count[level].second += 1;
        }
        
        bfs(count, root->left, level+1);
        bfs(count, root->right, level+1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector <pair<double, double>> count;
        vector <double> ans;
        bfs(count, root, 0);
        for(auto i : count){
            double temp = (double)i.first / (double)i.second;
            ans.push_back(temp);
        }
        return ans;
    }
};