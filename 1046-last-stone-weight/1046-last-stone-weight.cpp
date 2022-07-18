class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> a;
        for(auto c: stones){
            a.push(c);
        }
        
        while(a.size() > 1){
            auto c = a.top();
            a.pop();
            auto b = a.top();
            a.pop();
            
            if(c == b){
                continue;
            }
            else if(c > b){
                a.push(c-b);
            }
            else{
                a.push(b-c);
            }
        }
        
        if(a.size() == 0) return 0;
        else return a.top();
    }
};