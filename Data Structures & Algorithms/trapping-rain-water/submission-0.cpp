class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int l = 0;
        int r = n - 1;

        int left_max = height[l];
        int right_max = height[r];
        int total = 0;
        while(l < r) {
            if(left_max < right_max) {
                l++;
                if(height[l] > left_max) {
                    left_max = height[l];
                }
                else {
                    total += left_max - height[l];
                }
            }
            else {
                r--;
                if(height[r] > right_max) {
                    right_max = height[r];
                }
                else {
                    total += right_max - height[r];
                }
            }
        }
        return total;
    }
};