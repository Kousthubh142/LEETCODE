class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> ans;

        for(int i=0;i<nums.size();i++) {
            int complement=target-nums[i];
            if(ans.count(complement)) {
                return {ans[complement],i};
            }

            ans[nums[i]]=i;
        }
        return {};
    }
};