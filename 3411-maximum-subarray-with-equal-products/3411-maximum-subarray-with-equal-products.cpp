
class Solution {
public:
    int gcdVal(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int lcmVal(int a, int b) {
        return (a / gcdVal(a, b)) * b;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        int mx = 0;
        int ml = 1;

        for (int x : nums) {
            mx = max(mx, x);
            ml = lcmVal(ml, x);
        }

        int maxP = ml * mx;

        for (int i = 0; i < n; i++) {
            int p = 1;
            int g = 0;
            int l = 1;

            for (int j = i; j < n; j++) {
                p *= nums[j];

                g = gcdVal(g, nums[j]);

                l = lcmVal(l, nums[j]);

                if (p == g * l) {
                    ans = max(ans, j - i + 1);
                }

                if (p > maxP) {
                    break;
                }
            }
        }

        return ans;
    }
};
