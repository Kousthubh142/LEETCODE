class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0,zero=0,right=0;
        int res=0;

        for(int right=0;right<nums.size();right++) {
            if(nums[right]==0) zero++;

            while(zero>k) {
                if(nums[left]==0) zero--;
                
                left++;
            }

            res=max(res,right-left+1);
        }
        return res;
    }
};