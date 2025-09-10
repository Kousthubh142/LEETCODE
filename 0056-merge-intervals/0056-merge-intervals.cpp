class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // if(!intervals.size()) return {};
        // sort(intervals.begin(),intervals.end());

        // vector<vector<int>> merged;

        // for(auto& interval:intervals) {
        //     if(merged.empty() || merged.back()[1]<interval[0]) 
        //         merged.push_back(interval);
        //     else {
        //         merged.back()[1]=max(merged.back()[1],interval[1]);
        //     }
        // }
        // return merged;

        if(!intervals.size()) return {};
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());


        for(auto& interval:intervals) {
            if(ans.empty() || ans.back()[1]<interval[0]) {
                ans.push_back(interval);
            }
            else {
                ans.back()[1]=max(ans.back()[1],interval[1]);
            }
        }
        return ans;
    }
};