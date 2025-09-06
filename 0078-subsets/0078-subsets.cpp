class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums,int index,vector<int>& current,int n) {
        if(index==n) {
            result.push_back(current);
            return;
        }

        current.push_back(nums[index]);
        backtrack(nums,index+1,current,n);
        current.pop_back();
        backtrack(nums,index+1,current,n);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        int n=nums.size();
        backtrack(nums,0,current,n);
        return result;
    }
};