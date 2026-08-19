class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, set<int>> reserved;

        for(auto seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            reserved[row].insert(col);
        }

        int ans = 0;

        ans = (n - reserved.size()) * 2;

        for(auto row : reserved) {

            set<int>& seats = row.second;

            bool left = true;
            bool middle = true;
            bool right = true;

            for(int i = 2; i <= 5; i++) {
                if(seats.count(i)) {
                    left = false;
                }
            }

            for(int i = 4; i <= 7; i++) {
                if(seats.count(i)) {
                    middle = false;
                }
            }

            for(int i = 6; i <= 9; i++) {
                if(seats.count(i)) {
                    right = false;
                }
            }

            if(left && right) {
                ans += 2;
            }
            else if(left || middle || right) {
                ans += 1;
            }
        }

        return ans;
    }
};