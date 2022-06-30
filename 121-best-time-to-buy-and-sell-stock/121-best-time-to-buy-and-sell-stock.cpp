class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // vector <int> temp = prices;
        // sort(temp.begin(), temp.end());
        int ans = 0;
        int left = 0;
        int right = 0;
        for(int i =1; i < prices.size()-1; i++){
            if(prices[left] > prices[i] ){
                left = i;
                right = i;
            }
            
            if(prices[right] < prices[i]){
                right = i;
                ans = max(prices[right] - prices[left], ans);
            }
        }
        
        if(prices[prices.size()-1] > prices[right]){
            right = prices.size()-1;
        }
        
        ans = max(prices[right] - prices[left], ans);
        return ans;
    }
};