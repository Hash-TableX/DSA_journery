class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = INT_MAX;
        int n = nums.size();
        for(int i=0;i<n;i++){
           mini = min(mini,nums[i]); 
        }
        return mini;
    }
};