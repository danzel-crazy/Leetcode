class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin() , nums.end());
        
        unordered_map <int, int> hash;
        for(int i = 0 ; i < nums.size() ; ++i){    
            hash[nums[i]] = i;
        }
        
        for(int i = 0; i < nums.size()-2; i++){
            if(nums[i] > 0) break;
            
            for(int j = i+1; j < nums.size()-1; j++){
                int sum =  -(nums[i] + nums[j]);
                if(hash.count(sum) && hash.find(sum)->second > j){
                    ans.push_back({nums[i] , nums[j] , sum});
                }
                j = hash.find(nums[j])->second;
            }
            i = hash.find(nums[i])->second;
        }
        
        return ans;
    }
};