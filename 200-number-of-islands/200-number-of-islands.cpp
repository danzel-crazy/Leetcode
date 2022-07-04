class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0') return;
        
        grid[i][j] = '0';
        bfs(grid, i+1, j);
        bfs(grid, i, j+1);
        bfs(grid, i-1, j);
        bfs(grid, i, j-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    bfs(grid, i, j);
                    // cout << '1' << endl;
                    ans += 1;
                }
            }
        }
        
       return ans; 
    }
};