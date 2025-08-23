class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       unordered_map<int,int> map;
       vector<int> ans;
       for(int i=0;i<nums.size();i++) {
           map[nums[i]]++;
           if(map[nums[i]]>nums.size()/3) {
               if(find(ans.begin(),ans.end(),nums[i])==ans.end())
                   ans.push_back(nums[i]);
           }
       }
        return ans;
    }
};