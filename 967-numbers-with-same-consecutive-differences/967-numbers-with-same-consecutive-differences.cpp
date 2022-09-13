class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector <int> ans;
        queue <int> a;
        
        for(int i = 1; i <= 9; i++){
            a.push(i);
        }
        
        for(int i = 2; i <= n; i++){
            int size = a.size();
            while(size--){
                int num = a.front();
                a.pop();
                if(k == 0){
                    int new_num = num*10 + (num%10);
                    a.push(new_num);
                }
                else{
                    if((num%10)+k <= 9){
                        int new_num = num*10 + (num%10) + k;
                        a.push(new_num);
                    }

                    if((num%10)-k >= 0){
                        int new_num = num*10 + (num%10) - k;
                        a.push(new_num);
                    }
                }
                
            }
        }
        
        while(!a.empty()){
            int num = a.front();
            a.pop();
            ans.push_back(num);
        }
        
        return ans;
    }
};