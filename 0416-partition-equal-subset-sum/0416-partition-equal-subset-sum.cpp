class Solution {
public:
    bool subsetK(int n, int target,vector<int>&nums) {
        vector<vector<bool>> dp(n,vector<bool>(target+1,false));

        for(int i=0;i<n;i++) dp[i][0]=true;
        if(nums[0]<=target)dp[0][nums[0]]=true;

        for(int i=1;i<n;i++) {
            for(int j=1;j<=target;j++) {
                bool nottaken=dp[i-1][j];
                bool taken=false;
                if(nums[i]<=j) {
                    taken=dp[i-1][j-nums[i]];
                }

                dp[i][j]=taken|nottaken;
            }
        }
        return dp[n-1][target];

        
    }

    bool canPartition(vector<int>& nums) {
        int totsum=0;
        for(int i:nums) totsum+=i;
        if(totsum%2!=0) return false;

        int target=totsum/2;

        return subsetK(nums.size(),target,nums);
    }
};