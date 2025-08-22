class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        for(int i=0;i<nums.size();i++) {
            int curSum=0;
            for(int j=i;j<nums.size();j++) {
                curSum+=nums[j];
                if(curSum==k) {
                    count++;
                }
            }
        }
        return count;
    }
};