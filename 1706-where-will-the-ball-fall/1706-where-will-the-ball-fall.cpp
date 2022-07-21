class Solution {
public:
    int dfs(int start, vector<vector<int>>& grid, int col, int row){
        if(grid[col][row] == 1){
            if(row+1 < grid[col].size()){
                if(grid[col][row+1] == -1){
                    return -1;
                }
                else{
                    if(col+1 >= grid.size()){
                        return row+1;
                    }
                    else return dfs(start, grid, col+1, row+1);
                }
            }
            else{
                if(col+1 >= grid.size() && grid.size() != 1 && row != grid[col].size()-1){
                        return row;
                }
                else return -1;
            }
        }
        else{
            if(row-1 >= 0){
                if(grid[col][row-1] == 1){
                    return -1;
                }
                else{
                    if(col+1 >= grid.size()){
                        return row-1;
                    }
                    else return dfs(start, grid, col+1, row-1);
                }
            }
            else{
                if(col+1 >= grid.size() && grid.size() != 1 && row != 0){
                        return row;
                }
                else return -1;
            }
        }
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        vector <int> ans;
        int col = 0, row = 0;
        for(int i = 0; i < grid[0].size(); i++){
            row = i;
            int a = dfs(i, grid, col, row);
            ans.push_back(a);
        }
        
        return ans;
    }
};