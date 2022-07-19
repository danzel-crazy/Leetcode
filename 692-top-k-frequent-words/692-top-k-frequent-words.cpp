class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector <string> ans;
        map <string, int> w;
        for(auto c : words){
            w[c]++;
        }
        
        priority_queue <pair<string, int>, vector <pair<string, int>>, cmp> q;
        
        for(auto a : w){
            q.push({a.first, a.second});
        }
        
        while(k--){
            ans.push_back(q.top().first);
            q.pop();
        }
        return ans;
    }
    
    struct cmp {
        bool operator()(pair<string, int> a, pair<string, int> b) {
            if(a.second == b.second){
                return a.first > b.first;
            }
            else return a.second < b.second;
        }
    };
};