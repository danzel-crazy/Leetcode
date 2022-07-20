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
        int slow = n;
        int fast = getnext(n);
        while(slow != 1 && slow != fast){
            slow = getnext(slow);
            fast = getnext(getnext(fast));
        }
        
        return fast == 1;
    }
};