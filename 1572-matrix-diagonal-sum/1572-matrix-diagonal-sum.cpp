class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum1=0,sum2=0;
        int n=mat.size();
        for(int i=0;i<mat.size();i++){
            sum1+=mat[i][i];
        } 
        for(int i=0;i<mat.size();i++){
            if(i!=(n-1-i)){
                sum2+=mat[i][n-1-i];
            }
            
        }  
        int result=sum1+sum2;
        
            
        return result;
    }
};