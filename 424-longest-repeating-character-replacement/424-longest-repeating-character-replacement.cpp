class Solution {
public:
    int characterReplacement(string s, int k) {
        map <char, int> a;
        
        int ans = 0;
        int cur_max = 0;
        int i = 0, j = 0;
        
        while(j < s.length()){
            a[s[j]]++;
            cur_max = max(cur_max, a[s[j]]);
            if(j - i + 1 - cur_max > k){
                a[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};