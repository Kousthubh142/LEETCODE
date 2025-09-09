class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n=s.length();
        int count=1;

        for(int i=1;i<=n;i++) {
            if(i<n && s[i]==s[i-1]) {
                count++;
            }
            else {
                if(count==k) return true;
                count=1;
            }
        }
        return false;
    }
};