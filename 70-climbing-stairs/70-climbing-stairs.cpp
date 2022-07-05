class Solution {
public:
    int dp[100]= {0};
    int climbStairs(int n) {
        dp[0] = 1;
        for(int i = 0; i <= n; i++){
            if(i+1 <= n){
               dp[i+1] += dp[i]; 
            }
            if(i+2 <= n){
               dp[i+2] += dp[i]; 
            }
            
        }
        
        return dp[n];
    }
};