class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        string ans(num1.size()+num2.size(), '0');
        
        for(int i = 0; i < num2.size(); i++){
            int temp2 = num2[i] - '0';
            
            for(int j = 0; j < num1.size(); j++){
                int temp1 = num1[j] - '0';
                int zero = i + j;
                
                int carry = ans[zero] - '0';
                int mul = temp1 * temp2 + carry;
                
                ans[zero] = mul % 10 + '0';
                ans[zero+1] += mul / 10;
            }
        }
        
        if(ans.back() == '0'){
            ans.pop_back();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};