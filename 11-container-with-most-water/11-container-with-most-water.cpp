class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int water = 0;
        int temp = 0;
        int finish = false;
        while(left <= right || finish){     
            temp = (height[left] > height[right]) ? height[right] * (right - left): height[left] * (right - left);
            if(temp > water) water = temp;
            if(height[left] > height[right]) right--;
            else left++;
        }
        return water;
    }
};