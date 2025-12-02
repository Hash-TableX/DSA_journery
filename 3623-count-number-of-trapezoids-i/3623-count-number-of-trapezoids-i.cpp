class Solution {
public:
    static const long long MOD = 1000000007;

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, long long> freq; 
        for (auto &p : points) freq[p[1]]++;

        vector<long long> pairs; 
        pairs.reserve(freq.size());

        for (auto &it : freq) {
            long long c = it.second;
            if (c >= 2) {
                long long ways = (c * (c - 1) / 2) % MOD; 
                pairs.push_back(ways);
            }
        }

        long long ans = 0, prefixSum = 0;
        for (long long x : pairs) {
            ans = (ans + x * prefixSum) % MOD;
            prefixSum = (prefixSum + x) % MOD;
        }

        return ans % MOD;
    }
};
