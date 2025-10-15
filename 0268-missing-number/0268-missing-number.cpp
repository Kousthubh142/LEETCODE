class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int raw=0;

        for(int i=1;i<=nums.size();i++) {
            raw^=i;
        }
        int check=0;
        for(int i=0;i<nums.size();i++) {
            check^=nums[i];
        }


        return raw^check;
    }
};