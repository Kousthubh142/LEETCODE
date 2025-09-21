class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();

        vector<int> front(n,0);

        for(int j=0;j<n;j++) {
            front[j]=triangle[n-1][j];
        }

        for(int i=n-2;i>=0;i--) {
            vector<int> cur(n,0);
            for(int j=i;j>=0;j--) {
                int d=front[j];
                int di=front[j+1];
                cur[j]=triangle[i][j]+min(d,di);
            }
            front=cur;
        }

        return front[0];
    }
};