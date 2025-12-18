class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        
        // Step 1: base profit
        long long base = 0;
        for (int i = 0; i < n; i++) {
            base += 1LL * strategy[i] * prices[i];
        }
        
        int half = k / 2;
        
        // A[i] = strategy[i] * prices[i]
        // B[i] = (1 - strategy[i]) * prices[i]
        vector<long long> A(n), B(n);
        for (int i = 0; i < n; i++) {
            A[i] = 1LL * strategy[i] * prices[i];
            B[i] = 1LL * (1 - strategy[i]) * prices[i];
        }
        
        long long maxGain = 0;
        long long firstSum = 0, secondSum = 0;
        
        // Initial window
        for (int i = 0; i < half; i++) firstSum += A[i];
        for (int i = half; i < k; i++) secondSum += B[i];
        
        maxGain = max(maxGain, -firstSum + secondSum);
        
        // Sliding window
        for (int l = 1; l + k - 1 < n; l++) {
            firstSum -= A[l - 1];
            firstSum += A[l + half - 1];
            
            secondSum -= B[l + half - 1];
            secondSum += B[l + k - 1];
            
            maxGain = max(maxGain, -firstSum + secondSum);
        }
        
        return base + maxGain;
    }
};
