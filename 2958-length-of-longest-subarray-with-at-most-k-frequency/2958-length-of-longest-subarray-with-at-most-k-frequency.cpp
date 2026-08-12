class Solution {
public:

    int maxSubarrayLength(vector<int>& nums, int k) {

        unordered_map<int, int> fq;

        int left = 0;
      int ans = 0;

        for(int right = 0; right < nums.size(); right++) {

            fq[nums[right]]++;

            while(fq[nums[right]] > k) {

                fq[nums[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};