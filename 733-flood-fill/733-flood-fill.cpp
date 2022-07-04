class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int origin = image[sr][sc],m=image.size(),n=image[0].size();;
        queue <pair<int, int>> q;
        q.push({sr,sc});
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            image[row][col] = color;
            
            
            if(row-1>=0){ 
                if(image[row-1][col]!=color && image[row-1][col]==origin)
                    q.push({row-1,col});                     
            }
            if(col-1>=0){
                if( image[row][col-1]!=color && image[row][col-1]==origin)
                    q.push({row,col-1});
            }
            if(row+1<m){ 
                if(image[row+1][col]!=color && image[row+1][col]==origin)
                    q.push({row+1,col});
            }
            if(col+1<n){
                if(image[row][col+1]!=color && image[row][col+1]==origin)
                    q.push({row,col+1});
            }
        }
        
        return image;
    }
};