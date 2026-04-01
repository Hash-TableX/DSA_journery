class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int j = 1;

        for(int k=1;k<n;k++){
            if(nums[k]!=nums[k-1]){
                nums[j]=nums[k];
                j++;
            }
        }
        return j;
    }
};