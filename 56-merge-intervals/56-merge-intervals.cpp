class Solution {
public:
    static bool mycompare(vector <int> &a, vector <int> &b){
        return a[0] < b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), mycompare);
        vector<vector<int>> ans;
        
        bool check = false;
        for(int i = 0; i < intervals.size(); i++){
            check = false;
            int n = ans.size();
            if(n > 0){
                if(ans[n-1][1] >= intervals[i][0]){
                    if(ans[n-1][1] < intervals[i][1]){
                        int temp = ans[n-1][0];
                        ans.pop_back();
                        ans.push_back({temp, intervals[i][1]}); 
                        check = true;
                    }
                    else{
                        continue;
                    }
                }
            }
            
            if(!check && i+1 < intervals.size()){
                if(intervals[i][1] >= intervals[i+1][0]){
                    if(intervals[i][1] > intervals[i+1][1])
                        ans.push_back(intervals[i]);
                    else{
                        ans.push_back({intervals[i][0], intervals[i+1][1]});
                    }
                }
                else{
                    ans.push_back(intervals[i]);
                }
            }
            else if(!check){
                ans.push_back(intervals[i]);
            }
        }
        
        return ans;
    }
};