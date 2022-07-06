class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a=0;
        int b=0,c;
        for(int i=2;i<=cost.size();i++){
            c=min(cost[i-1]+a,cost[i-2]+b);
            b=a;
            a=c;
        }
        return c;
    }
};