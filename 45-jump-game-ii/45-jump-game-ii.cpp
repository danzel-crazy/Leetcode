class Solution {
public:
    int jump(vector<int>& nums) {
        int n = size(nums);
        vector<int> dp(n, 10001);
        dp[n - 1] = 0;
        
        for(int i = n-2; i >= 0; i--){
            for(int step = 1; step <= nums[i]; step++){
                dp[i]= min(dp[i], 1 + dp[min(n-1, i+step)]);
            }
        }
        
        return dp[0];
    }
};