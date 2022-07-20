class Solution {
public:
    int getnext(int n){
        int temp = 0;
        while(n != 0){
            int a = n % 10;
            n = n / 10;
            temp += a*a;
        }
        
        return temp;
    }
    
    bool isHappy(int n) {
        set <int> check;
        while(n != 1 && !check.count(n)){
            check.insert(n);
            n = getnext(n);
        }
        
        return n == 1;
    }
};