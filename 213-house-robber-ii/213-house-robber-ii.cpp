class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        else if(n == 2){
            return max(nums[0], nums[1]);
        }
        int dp[n];
        int dp_[n];
        dp[0] = nums[0];
        dp[1] = nums[1];
        for(int i = 2; i < nums.size()-1; i++){
            if((i-3) >= 0){
                dp[i] = max(dp[i-2], dp[i-3]) + nums[i];
            }
            else dp[i] = dp[i-2] + nums[i];
        }
        int ans = max(dp[n-2] ,dp[n-3]);
        
        dp_[0] = nums[1];
        dp_[1] = nums[2];
        for(int i = 3; i < nums.size(); i++){
            if((i-4) >= 0){
                dp_[i-1] = max(dp_[i-3], dp_[i-4]) + nums[i];
            }
            else dp_[i-1] = dp_[i-3] + nums[i];
        }
        int temp = max(dp_[n-2], dp_[n-3]);
        ans = max(ans, temp);
        return ans;
    }
};