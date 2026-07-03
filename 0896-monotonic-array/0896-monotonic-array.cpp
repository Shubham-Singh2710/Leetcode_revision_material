class Solution {
public:
    bool isMonotonic(vector<int>& nums) {

        int n = nums.size();

        bool increasing = true;
        bool decreasing = true;

        int i = 1;

        while(i < n)
        {
            if(nums[i] > nums[i-1])
            {
                decreasing = false;
            }

            if(nums[i] < nums[i-1])
            {
                increasing = false;
            }

            i++;
        }

        if(increasing || decreasing)
        {
            return true;
        }

        return false;
    }
};