class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1;
        int j = t.length() - 1;
        int back_s = 0, back_t = 0;
        
        while(i >= 0 || j >= 0){
            while(i >= 0){
                if(s[i] == '#'){
                    back_s += 1;
                    i--;
                }
                else if(back_s != 0){
                    i--;
                    back_s--;
                }
                else{
                   break; 
                }
            }
            while(j >= 0){
                if(t[j] == '#'){
                    back_t += 1;
                    j--;
                }
                else if(back_t != 0){
                    j--;
                    back_t--;
                }
                else{
                    break;
                }
            }
            if (i >= 0 && j >= 0 && s[i] != t[j]){
                cout << s[i] <<" " << t[j] << endl;
                return false;   
            }
            if ((i >= 0) != (j >= 0)){
                return false;
            }

            i--;
            j--;
        }
        
        return true;
    }
};