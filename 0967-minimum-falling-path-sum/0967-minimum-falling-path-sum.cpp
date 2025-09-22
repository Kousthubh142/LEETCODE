class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> ans(n,-1);

        for(int i=0;i<n;i++) {
            ans[i]=matrix[0][i];
        }

        for(int i=1;i<n;i++) {
            vector<int> seen(n,-1);
            for(int j=0;j<n;j++) {
                int best=ans[j];
                if(j>0) best=min(best,ans[j-1]);
                if(j<n-1) best=min(best,ans[j+1]);
                seen[j]=matrix[i][j]+best;
            }
            ans=seen;
        }

        sort(ans.begin(),ans.end());
        return ans[0];
    }
};