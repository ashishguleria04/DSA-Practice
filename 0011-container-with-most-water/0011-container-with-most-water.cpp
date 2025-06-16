class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, maxA = 0;
        while (l < r) {
            int h = min(height[l], height[r]);
            maxA = max(maxA, h * (r - l));
            if (height[l] < height[r]) l++;
            else r--;
        }
        return maxA;
    }
};
