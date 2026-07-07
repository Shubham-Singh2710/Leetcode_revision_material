class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        int l= 0;

        string st = to_string(n);

        for (int i = 0; i < st.length(); i++) {
            int digit = st[i] - '0';
            sum += digit;

            if (digit != 0) {
                l=l*10+digit;
            }
        }

        return  1LL*sum * l;
    }
};