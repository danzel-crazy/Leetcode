class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        map <char, int> a, b;
        
        for(int i = 0; i < secret.length(); i++){
            if(secret[i] == guess[i]){
                bulls += 1;
            }
            else{
                a[secret[i]]++;
                b[guess[i]]++;
            }
        }
        
        for(int i = 0; i < 10; i++){
            cows += min(a['0' + i], b['0'+i]); 
        }
        
        string ans = "";
        ans += to_string(bulls);
        ans += "A";
        ans += to_string(cows);
        ans += "B";
        
        return ans;
    }
};