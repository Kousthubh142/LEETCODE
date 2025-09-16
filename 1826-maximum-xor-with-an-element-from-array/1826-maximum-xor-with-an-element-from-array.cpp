class TrieNode{
    public:
    vector<TrieNode *>v;
    TrieNode() : v(2,nullptr){}
};
class Solution {
public:
    TrieNode *root = new TrieNode();
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int m = queries.size();
        vector<int>ans(m);
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>>pq;
        int j=0;
        for(auto i:queries){
            pq.push({{i[1],i[0]},j++});
        }
        j=0;
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            for(;j<n && temp.first.first>=nums[j] ;j++){
                string str = bitset<32>(nums[j]).to_string();
                TrieNode * node = root;
                for(char ch:str){
                    if(node->v[ch-'0'] == nullptr){
                        node->v[ch-'0'] = new TrieNode();
                    }
                    node = node->v[ch-'0'];
                }
            }
            if (j == 0) {
                ans[temp.second] = -1;
                continue;
            }
            string str = bitset<32>(temp.first.second).to_string();
            TrieNode * node = root;
            string str1 = "";
            for(char ch:str){
                int ele = (ch - '0') ^ 1;
                if(node->v[ele] != nullptr){
                    str1 += to_string(ele);
                    node = node->v[ele];
                }
                else {
                    str1 += ch;
                    node = node->v[ch-'0'];
                }
            }
            ans[temp.second] = stoi(str1,0,2) ^ temp.first.second;
        }
        return ans;
    }
};