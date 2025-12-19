class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros,ones,twos;
        zeros=ones=twos=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zeros++;
            }
            else if(nums[i]==1){
                ones++;
            }
            else{
                twos++;
            }
        }

        int i=0;
        while(zeros!=0){
            nums[i]=0;
            i++;
            zeros--;
        }

        while(ones!=0){
            nums[i]=1;
            i++;
            ones--;
        }

        while(twos!=0){
            nums[i]=2;
            i++;
            twos--;
        }
    }
};