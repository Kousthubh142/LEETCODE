class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);

        int prev=nums[0];
        int prev2=0;

        for(int i=1;i<n-1;i++) {
            int take=nums[i];
            if(i>1) take+=prev2;

            int nottake=0+prev;

            int cur=max(take,nottake);
            prev2=prev;
            prev=cur;
        }

        prev2=0;
        int pre=nums[1];

        for(int i=2;i<n;i++) {
            int take=nums[i];
            if(i>1) take+=prev2;

            int nottake=0+pre;

            int cur=max(take,nottake);
            prev2=pre;
            pre=cur;
        }

        return max(prev,pre);
    }
};