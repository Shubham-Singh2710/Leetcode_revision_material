class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size();

        int maxi = INT_MIN;
        int mini = INT_MAX;

        int maxIndex = 0;
        int minIndex = 0;

        for(int i = 0; i < n; i++) {

            if(nums[i] > maxi) {
                maxi = nums[i];
                maxIndex = i;
            }

            if(nums[i] < mini) {
                mini = nums[i];
                minIndex = i;
            }
        }

        int front = max(maxIndex, minIndex) + 1;

        int back = n - min(maxIndex, minIndex);

        
        int both = min(maxIndex, minIndex) + 1
                   + n - max(maxIndex, minIndex);

        return min({front, back, both});
    }
};