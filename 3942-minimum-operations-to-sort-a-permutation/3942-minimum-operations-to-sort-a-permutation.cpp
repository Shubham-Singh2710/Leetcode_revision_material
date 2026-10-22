class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int pos = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                pos = i;
                break;
            }
        }

        bool is_asc = true;
        for (int i = 0; i < n; i++) {
            if (nums[(pos + i) % n] != i) {
                is_asc = false;
                break;
            }
        }

        bool is_desc = true;
        for (int i = 0; i < n; i++) {
            if (nums[(pos - i + n) % n] != i) {
                is_desc = false;
                break;
            }
        }

        int ans = INT_MAX;

        if (is_asc) {
            ans = min(ans, pos);
            ans = min(ans, n - pos + 2);
        }

        if (is_desc) {
            ans = min(ans, (pos + 1) % n + 1);
            ans = min(ans, n - 1 - pos + 1);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};