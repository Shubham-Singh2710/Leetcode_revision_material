class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string> words;
        string word;

        stringstream ss(s);

        while(ss >> word) {
            words.push_back(word);
        }

        if(pattern.size() != words.size())
            return false;

        unordered_map<char, string> mp;
        unordered_map<string, char> check;

        for(int i = 0; i < pattern.size(); i++) {

            char ch = pattern[i];

            if(mp.count(ch)) {
                if(mp[ch] != words[i])
                    return false;
            }
            else {
                if(check.count(words[i]))
                    return false;

                mp[ch] = words[i];
                check[words[i]] = ch;
            }
        }

        return true;
    }
};