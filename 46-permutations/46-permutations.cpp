class Solution {
public:
    void findpermute(vector<int>& nums,vector<vector<int>>&ans, vector<int>&temp, int visited[]){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(visited[i] != 1){
                temp.push_back(nums[i]);
                visited[i] = 1;
                findpermute(nums, ans, temp, visited);
                visited[i] = 0;
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int visited[n];
        for(int i = 0; i < n; i++){
            visited[i] = 0;
        }
        vector<int> temp;
        findpermute(nums, ans, temp, visited);
        return ans;
    }
};