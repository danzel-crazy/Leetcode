class Solution {
    vector<pair<int, int>> directions {{0,1}, {1,0}, {-1,0}, {0,-1}};
    int srcColor;
public:
    void recur(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == srcColor) {
            image[sr][sc] = color;
        }
        
        for (auto& p : directions) {
            int x = sr + p.first;
            int y = sc + p.second;
            if (x > -1 && x < image.size() && y > -1 && y < image[0].size() && image[x][y] == srcColor) {
                recur(image, x, y, color);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        srcColor = image[sr][sc];
        if (color != srcColor) {
            recur(image, sr, sc, color);
        }
        return image;
    }
};