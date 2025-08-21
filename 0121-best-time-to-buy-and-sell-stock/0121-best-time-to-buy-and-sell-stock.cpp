class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bought=prices[0];
        int profit=0;

        for(int i=0;i<prices.size();i++) {
            if(bought>prices[i]) bought=prices[i];

            profit=max(profit,prices[i]-bought);
        }

        return profit;
    }
};