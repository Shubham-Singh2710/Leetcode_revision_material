class Solution {
public:

    int sum(vector<int>&nums){
        int total=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                total+=nums[i];
            }
            else{
                break;
            }
        }
        return total;
        
    }
    int missingInteger(vector<int>& nums) {
        int target=sum(nums);
        while(true){
            bool found=false;
        for(int x:nums){
            if(x==target){
                found=true;
                break;
            }
        }
        if(!found){
            return target;
        }
        target++;
        }
    }
};