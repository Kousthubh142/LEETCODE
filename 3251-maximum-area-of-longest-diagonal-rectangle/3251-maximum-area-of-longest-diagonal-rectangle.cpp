class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagSq = 0;  
        int maxArea = 0;

        for (auto &rect : dimensions) {
            int l = rect[0], w = rect[1];
            int diagSq = l * l + w * w;   
            int area = l * w;

            if (diagSq > maxDiagSq) {
                maxDiagSq = diagSq;
                maxArea = area;
            } else if (diagSq == maxDiagSq) {
                maxArea = max(maxArea, area);  
            }
        }

        return maxArea;
    }
};
