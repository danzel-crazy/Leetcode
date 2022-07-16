class Solution {
public:
    string decodeString(string s) {
        stack <pair <int, string>> a;
        string ans = "";
        pair <int, string> temp = {0,""};
        for(int i = 0; i < s.length(); i++){
            if(s[i] <= '9'){
                temp.first = temp.first*10 + s[i]-'0';
            }
            else if(s[i] == '['){
                a.push(temp);
                temp = {0,""};
            }
            else if(s[i] == ']'){    
                cout << a.top().first << endl;
                for(int i = 0; i < a.top().first; i++){
                    a.top().second.append(temp.second);
                }
                temp.second = a.top().second;
                a.pop();
            }
            else{
                temp.second.push_back(s[i]);
            }
        }
        return temp.second;
    }
};