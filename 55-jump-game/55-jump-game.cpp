class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        int dp[10001] = {0};
        dp[0] = 1;
        
        for(int i = 0; i < n-1; i++){
            if(dp[i] == 0) continue;
            int temp = nums[i];
            while(temp){
                if(temp + i < n){
                    dp[temp+i] = 1;
                }
                temp--;
            }
        }
            
        return dp[n-1];
    }
};