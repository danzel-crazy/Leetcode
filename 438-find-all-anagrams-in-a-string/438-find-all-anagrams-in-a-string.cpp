class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> sarr(26,0);
        vector<int> parr(26,0);
        vector<int> ans;
        
        if(s.length()<p.length())
            return ans;
        
        for(int i = 0; i<p.length(); i++){
            sarr[s[i]-'a']++;
            parr[p[i]-'a']++;
        }
        if(sarr == parr){
            ans.push_back(0);
        }
        int j =0;
        for(int i = p.length(); i<s.length(); i++,j++){
            sarr[s[j]-'a']--;
            sarr[s[i]-'a']++;
            if(sarr == parr){
                ans.push_back(j+1);
            }
        }
        return ans;
    }
};