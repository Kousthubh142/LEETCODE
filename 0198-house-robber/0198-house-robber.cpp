class Solution {
public:
    vector<int> dp=vector<int>(101,-1);
    int recur(vector<int> &nums,int n) {
        if(n==0) return nums[0];
        if(n<0) return 0;

        if(dp[n]!=-1) return dp[n];

        int pick=nums[n]+recur(nums,n-2);
        int notpick=0+recur(nums,n-1);

        return dp[n]=max(pick,notpick);
    }

    int rob(vector<int>& nums) {
        int n=nums.size()-1;
        int ans=recur(nums,n);
        return ans;
    }
};