class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        for(int x:nums1) ans.push_back(x);
        for(int x:nums2) ans.push_back(x);

        sort(ans.begin(),ans.end());

        if((ans.size())%2==1) {
            return (double)ans[ans.size()/2];
        }
        else return ((double)ans[ans.size()/2] + (double)ans[(ans.size()/2) - 1]) / 2.0;
    }
};