class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
       vector<int>nums2(n);
       for(int i=0;i<nums1.size();i++){
        if(nums1[i]%2==0){
          return true;
        }
        else if(nums1[i]%2!=0){
            return true;
        }
        else{
            nums2[i]=nums1[i]-nums1[i+1];

        }
       } 
       return false;
    }
};