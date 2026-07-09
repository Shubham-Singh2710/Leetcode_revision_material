class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        int n = s.size();
        int m = p.size();

        if(m > n)
            return ans;

        vector<int> pFreq(26, 0);
        vector<int> sFreq(26, 0);

        // Frequency of p
        for(int i = 0; i < m; i++)
        {
            pFreq[p[i] - 'a']++;
            sFreq[s[i] - 'a']++;
        }

        if(pFreq == sFreq)
            ans.push_back(0);

        // Slide the window
        for(int i = m; i < n; i++)
        {
            // Add new character
            sFreq[s[i] - 'a']++;

            // Remove old character
            sFreq[s[i - m] - 'a']--;

            if(pFreq == sFreq)
            {
                ans.push_back(i - m + 1);
            }
        }

        return ans;
    }
};