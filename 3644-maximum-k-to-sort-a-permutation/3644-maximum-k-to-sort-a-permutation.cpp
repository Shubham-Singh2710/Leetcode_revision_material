class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int res = -1; 
        for (int i = 0; i < n; i++) {
            
            if (nums[i] == i) {
                continue;
            }
            
            if (res == -1) {
                res = nums[i];
            } else {
                res &= nums[i];
            }
        }
        
       
        if (res == -1) {
            return 0;
        } else {
            return res;
        }
    }
};