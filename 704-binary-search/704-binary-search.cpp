class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1;
        ans = binary(nums, 0, nums.size()-1, target);
        return ans;
    }
    
    int binary(vector<int>& nums, int start, int end, int target){ 
        if(start > end) return -1;
        int mid = (start+end)/2;
        
        if(nums[mid] > target){
            return binary(nums, start, mid-1, target);
        }
        else if(nums[mid] < target){
            return binary(nums, mid+1, end, target);
        }
        else{
            return mid;
        }
    }
};