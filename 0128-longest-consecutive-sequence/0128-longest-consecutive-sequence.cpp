class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest=0;

        for(int x:st) {
            if(st.find(x-1)==st.end()) {
                int curNumber=x;
                int count=1;
            
                while(st.find(curNumber+1)!=st.end()) {
                    curNumber++;
                    count++;
                }
                
                longest=max(longest,count);
            }
        }
        return longest;
    }
};