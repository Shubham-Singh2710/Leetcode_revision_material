class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());
        coins.erase(unique(coins.begin(), coins.end()), coins.end());

        auto count = [&](long long x) {
            long long ans = 0;
            int n = coins.size();

            for (int mask = 1; mask < (1 << n); mask++) {
                long long lcm = 1;
                int bits = 0;
                bool valid = true;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;

                        long long g = gcd(lcm, (long long)coins[i]);
                        lcm = lcm / g * coins[i];

                        if (lcm > x) {
                            valid = false;
                            break;
                        }
                    }
                }

                if (!valid)
                    continue;

                long long ways = x / lcm;

                if (bits % 2 == 1)
                    ans += ways;
                else
                    ans -= ways;
            }

            return ans;
        };

        long long left = 1;
        long long right = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (left < right) {
            long long mid = left + (right - left) / 2;

            if (count(mid) >= k)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};