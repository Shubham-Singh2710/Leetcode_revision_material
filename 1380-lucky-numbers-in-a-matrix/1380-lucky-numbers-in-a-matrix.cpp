class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<int> ans;

        for(int i = 0; i < n; i++)
        {
            int minValue = mat[i][0];
            int colIndex = 0;

            for(int j = 1; j < m; j++)
            {
                if(mat[i][j] < minValue)
                {
                    minValue = mat[i][j];
                    colIndex = j;
                }
            }

           
            bool isLucky = true;

            for(int k = 0; k < n; k++)
            {
                if(mat[k][colIndex] > minValue)
                {
                    isLucky = false;
                    break;
                }
            }

            if(isLucky)
            {
                ans.push_back(minValue);
            }
        }

        return ans;
    }
};