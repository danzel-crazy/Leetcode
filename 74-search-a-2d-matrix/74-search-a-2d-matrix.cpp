class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int i = 0;
        int j = n-1;
        bool ans = false;
        
        while( i<m and j>=0 ){
            
            if(matrix[i][j] == target){
                ans = true;
                break;
            }else if (matrix[i][j] < target){
                i++;
            }else{
                j--;
            }
        }
        
        return ans; 
        
    }
};