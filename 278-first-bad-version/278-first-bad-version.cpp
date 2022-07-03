// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long mid = 0 , left = 1, right = n;
        int ans = mid;
        while(left <= right){
            mid = (left + right)/2;
            if(isBadVersion(mid)){
                ans = mid;
                right = mid-1;
            }
            else{
                // if(isBadVersion(mid+1)) return mid+1;
                left = mid+1;
            }
        }
        return ans;
    }
};