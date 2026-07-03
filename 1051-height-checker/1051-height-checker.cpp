class Solution {
public:
    int heightChecker(vector<int>& heights) {
       vector<int>temp;
       vector<int>ans;
       int count=0;
      for(int i=0;i<heights.size();i++){
        temp.push_back(heights[i]);
      }
        sort(heights.begin(),heights.end());
       for(int i=0;i<heights.size();i++){
             ans.push_back(heights[i]);
         if(ans[i]!=temp[i]){
            count++;
         }
       }
       return count;
    }
};