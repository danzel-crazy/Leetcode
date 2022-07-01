class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        map <char, int> a;
        for(int i = 0; i < s.size(); i++){
            a[s[i]]++;
        }
        
        for(auto s: a){
            int d = s.second%2;
            int c = s.second/2;
            ans += c*2;
            if(d == 1 && ans % 2 == 0){
                ans += 1;
            }
        }
        return ans;
    }
};