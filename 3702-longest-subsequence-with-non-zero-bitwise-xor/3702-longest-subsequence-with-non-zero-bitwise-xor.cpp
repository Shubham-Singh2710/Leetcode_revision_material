class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorVal = 0, count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            xorVal ^= nums[i];
            if (xorVal == 0) {
                count++;
            }
        }
        
        if (xorVal != 0) {
            return n;
        }
        
        if (count == n) {
            return 0;
        } else {
            return n - 1;
        }
    }
};