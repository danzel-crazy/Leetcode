class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        for(int i = 0 ; i<s.length() ; i++){
            if(s[i] != ']' ){
                st.push(s[i]);
            }
            else{
                string str = "";
                while(st.top() != '['){
                    str = st.top()+str;
                    st.pop();
                }
                st.pop();
                string num = "";
                while(!st.empty() && isdigit(st.top())){
                    num += st.top();
                    st.pop();
                }
                reverse(num.begin(),num.end());
                int k = stoi(num);
                while(k--){
                    for(int j = 0 ; j<str.size() ; j++){
                        st.push(str[j]);
                    }
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            ans +=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};