class Solution {
public:
    int dp[1005] = {0};
    int minCostClimbingStairs(vector<int>& cost) {
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i <= cost.size(); i++){
            if(dp[i-1] + cost[i-1] > dp[i-2] + cost[i-2]){
                if(dp[i] > dp[i-2] + cost[i-2] || dp[i] == 0)
                    dp[i] = dp[i-2] + cost[i-2];
            }
            else{
                if(dp[i] > dp[i-1] + cost[i-1] || dp[i] == 0)
                    dp[i] = dp[i-1] + cost[i-1];
            }
        
        }
        
        return dp[cost.size()];
    }
};