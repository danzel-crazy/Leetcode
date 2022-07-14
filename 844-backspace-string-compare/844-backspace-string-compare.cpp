class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack <char> st;
        stack <char> tt;
        
        for(char c : s){
            if(c != '#'){
                st.push(c);
            }
            else if(c == '#' && !st.empty()){
                st.pop();
            }
        }
        
        for(char c : t){
            if(c != '#'){
                tt.push(c);
            }
            else if(c == '#' && !tt.empty()){
                tt.pop();
            }
        }
        
        return st == tt;
    }
};