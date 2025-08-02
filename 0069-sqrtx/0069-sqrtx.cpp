class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }

        long long left = 1;
        long long right = x;
        long long ans = 0; 
        while (left <= right) {
            long long mid = left + (right - left) / 2;

            if (mid * mid == x) {
                return mid;
            } else if (mid * mid < x) {
                ans = mid; 
                left = mid + 1;
            } else {
                right = mid - 1; 
            }
        }
        return static_cast<int>(ans);
    }
};