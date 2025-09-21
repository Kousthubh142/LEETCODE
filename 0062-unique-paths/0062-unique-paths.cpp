class Solution {
public:
    int call(int m,int n,vector<vector<int>>& dp) {
        if(m==0 && n==0) return 1;
        if(n<0 || m<0) return 0;

        if(dp[m][n]!=-1) return dp[m][n];
        int up=call(m-1,n,dp);
        int left=call(m,n-1,dp);
        return dp[m][n]=up+left;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans=call(m-1,n-1,dp);
        return ans;
    }
};