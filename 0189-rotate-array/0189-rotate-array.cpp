class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int l = k%n;

        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+l);
        reverse(nums.begin()+l,nums.end());
    }
};