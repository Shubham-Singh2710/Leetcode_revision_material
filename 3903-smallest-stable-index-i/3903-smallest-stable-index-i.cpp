class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> right(n);

        right[n - 1] = nums[n - 1];

        for(int i = n - 2; i >= 0; i--) {
            right[i] = min(right[i + 1], nums[i]);
        }

        int maxi = INT_MIN;

        for(int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);

            int sub = maxi - right[i];

            if(sub <= k) {
                return i;
            }
        }

        return -1;
    }
};