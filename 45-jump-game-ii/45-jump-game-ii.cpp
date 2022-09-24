class Solution {
public:
    int jump(vector<int>& nums) {
        int n = size(nums);
        int i = 0, step = 0, last = 0, max_reach = 0;
        while(last < n -1){
           max_reach = max(max_reach, i + nums[i]);  
            if(i == last) {			  
                last = max_reach;     
                step++;                          
            }            
            i++; 
        }
        
        return step;
    }
};