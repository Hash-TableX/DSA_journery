class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0;
        int r=0;
        int maxLength=0;
        int zero=0;

        while(r<n){
            if(nums[r]==0){
                zero++;
            }
            if(zero>k){
                if(nums[l]==0){
                    zero--;
                }
                l++;
            }
            else if(zero<=k){
                int len = r-l+1;
                maxLength=max(maxLength,len);
            }
            r++;
        }
        return maxLength;
    }
};