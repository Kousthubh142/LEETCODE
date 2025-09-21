class Solution {
public:
    int call(int m,int n,vector<vector<int>>& grid,vector<vector<int>>& dp) {
        if(m<0 || n<0) return 0;
        if(m>=0 && n>=0 && grid[m][n]==1) return 0;

        if(dp[m][n]!=-1) return dp[m][n];
        int up=call(m-1,n,grid,dp);
        int left=call(m,n-1,grid,dp);

        return dp[m][n]=up+left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0]=1;
        int ans=call(m-1,n-1,obstacleGrid,dp);
        return ans;
    }
};