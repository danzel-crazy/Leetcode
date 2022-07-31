class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0;
        int num = 0;
        map <char, int> words;
        for(int i = 0; i < tasks.size(); i++){
            words[tasks[i]]++;
            num = max(num, words[tasks[i]]);
        }
        
        ans = (num -1) * (n+1);
        for(auto i : words){
            if(i.second == num) ans ++;
        }
        return max(ans, (int)tasks.size());
   }
};