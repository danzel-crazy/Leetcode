class Solution {
public:
    static bool compare(vector <int> &a, vector <int> &b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int ans = 0;
        int max_def = 0;
        sort(properties.begin(), properties.end(), compare);
        for(int i = properties.size()-1; i >= 0; i--){
            if(properties[i][1] < max_def){
                ans++;
            }
            max_def = max(max_def, properties[i][1]);
        }
        return ans;
    }
};